//
// Created by shan on 2/7/18.
//

#include "Checking.cpp"
#include <vector>
#include <ctime>

void HumanGame() {
    int innumber;
    int numCorrectLoc;
    int numIncorrectLoc;
    int numCount = 0;
    vector<int> your;
    vector<int> ans;
    vector<int> control={1,2,3,4,5,6};
    int choice;
    srand(time(NULL));
    for (int i = 1; i <= 4; i++) {
        ans.push_back(rand() % 6 + 1);
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    while (numCount < 5) {
        int correct =0;
        while(correct!=4) {
            your.clear();
            cout << "Please enter your guess(4 digit):" << endl;
            cin >> innumber;
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
        }
        reverse(your.begin(), your.end());
        check(your, ans, true, numCorrectLoc, numIncorrectLoc);
        numCount++;
    }
    cout<<"All your attempts are being used, you lose! Bye!"<<endl;
}
