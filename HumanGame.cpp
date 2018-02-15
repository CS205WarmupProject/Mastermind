//
// Created by shan on 2/7/18.
//

#include "Checking.cpp"
#include <vector>
#include <ctime>

bool hint = false;

void Human_game(vector<int> ansVector){
    int innumber;
    int numCorrectLoc;
    char hintstatus;
    vector<int> your;
    int status = 0;
    int numIncorrectLoc;
    int correct = 0;
    int length = 1;

    vector<int> control = {1, 2, 3, 4, 5, 6};
    while(correct!=4) {
        your.clear();
        cout << "Please enter your guess(4 digit):" << endl;
        cin >> innumber;
        while(innumber>6666||innumber<1111){
            cout<<"Wrong input"<<endl;
            cout << "Please enter your guess(4 digit):" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> innumber;
        }
        for (int i = 1; i <= 4; i++) {
            your.push_back(innumber % 10);
            innumber /= 10;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                if (your[i] == control[j]) {
                    correct++;
                }
            }
        }

    }//check the input length of the number and if it is number, and then check if input number 1-6
    reverse(your.begin(), your.end());
    check(your, ansVector, hint, numCorrectLoc, numIncorrectLoc);
    while(status == 0) {
        cout << "Do you need a hint?(Y/N) Press 'Q' to quit." << endl;
        cin >> hintstatus;
        if (hintstatus == 'Y') {
            hint = true;
            status=1;

        } else if (hintstatus == 'N') {
            hint = false;
            status=1;
        }else if (hintstatus == 'Q') {
            exit(0);
        } else {
            cout << "I don't understand." << endl;
        }
    }//ask user if needs a hint or not
}


void HumanGame() {
    char another;
    int numCount = 0;
    int status =0;
    vector<int> ans;
    int choice;
    srand(time(NULL));//to get different 4 digit for each turn
    for (int i = 1; i <= 4; i++) {
        ans.push_back(rand() % 6 + 1);
    }//push the 4 digits into vector
//    for (int i = 0; i < ans.size(); ++i) {
//        cout << ans[i] << ' ';
//    }//print out the answer(only for developing)
    cout << endl;
    while (numCount < 5) {
        Human_game(ans);
        numCount++;
    }//5 guesses(1st trail)
    while(status == 0) {
        cout << "All your attempts are being used! Another five guess?(Y/N)" << endl;
        cin >> another;
        if (another == 'Y') {
            status=1;
            numCount = 0;
            while (numCount < 5) {
                Human_game(ans);
                numCount++;
            }
        } else if (another == 'N') {
            status=1;
            exit(0);
        } else {
            cout << "I don't understand." << endl;
        }
    }//ask for 2nd trail
    cout<<"All your attempts are being used! You lose! Bye!"<<endl;//lose message
}
