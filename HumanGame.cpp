//
// Created by shan on 2/7/18.
//

#include "Checking.cpp"
#include <vector>
#include <ctime>

void HumanGame() {
    int innumber;
    int numCount = 0;
    vector<int> your;
    vector<int> ans;
    string dis[4];
    int choice;
    srand(time(NULL));
    for (int i = 1; i <= 4; i++) {
        ans.push_back(rand() % 6 + 1);
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    while (numCount <= 5) {
        your.clear();
        cout << "Please enter your guess(4 digit):" << endl;
        cin >> innumber;
        for (int i = 1; i <= 4; i++) {
            your.push_back(innumber % 10);
            innumber /= 10;
        }
        reverse(your.begin(), your.end());
        check(your, ans, true);
        numCount++;
    }
    cout<<"All your attempts are being used, you lose! Bye!"<<endl;
}
