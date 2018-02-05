//
// Created by Joshua on 1/28/2018.
// A function for the checking of each guess
//

#include <vector>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

bool check(vector<int> guessVector, vector<int> correctVector, bool hints) {

    int numCorrectLoc = 0; //Number of correctly guessed pegs. Corresponds to the colored peg in mastermind
    int numIncorrectLoc = 0; //Number of pegs where the color was correctly guessed but the location was not. Corresponds to the white peg in mastermind

    bool hasCorrespondingArray[4] = {false, false, false, false}; //Keeps track of which pegs in the solution have already been counted
    bool hasBeenChecked[4] = {false, false, false, false}; //keeps track of which pegs in the guess have been checked already
    string correctList = "Correct indexes: "; //This is appended when correct indexes are found. For use in the hint
    ostringstream oss;


    //For each peg in the known/correct pattern
    for (int i = 0; i < correctVector.size(); i++) {

        if (correctVector[i] == guessVector[i]) {
            numCorrectLoc++;
            hasCorrespondingArray[i] = true;
            hasBeenChecked[i] = true;
            oss << i << ", ";
            correctList += oss.str();
            oss.str("");
        }
    }
    for (int j = 0; j < guessVector.size(); j++) {
        for (int k = 0; k < correctVector.size(); k++) {
            if (guessVector[j] == correctVector[k] && !hasCorrespondingArray[k] && !hasBeenChecked[j]){
                numIncorrectLoc++;
                hasBeenChecked[j] = true;
                hasCorrespondingArray[k] = true;
            }
        }
    }


    cout << "# Correct: " << numCorrectLoc << endl;
    cout << "# in the wrong location: " << numIncorrectLoc << endl;
    if (hints) {
        cout << correctList << endl;
    }
}

void testCheck() {
    vector<int> testCorrect =   {1, 4, 2, 2};
    vector<int> testGuess =     {1, 1, 4, 2};
    check(testGuess, testCorrect, true);
}