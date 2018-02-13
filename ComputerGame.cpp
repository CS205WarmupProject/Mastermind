//
//  ComputerGame.cpp
//  homework
//
//  Created by User on 2/8/18.
//  Copyright © 2018 Xu Sun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;


vector<int> full_list;
vector<int> fix_list;
int computer_gues;
int computer_gues_save;
int human_guess;

void generate_new_list(){

    for(int i = 1; i<7; i++){
        for(int j = 1; j<7; j++){
            for(int k = 1; k<7; k++){
                for(int m = 1; m<7; m++){
                    full_list.push_back(i*1000+j*100+k*10+m);

                }
            }
        }
    }

    for(int i = 1; i<7; i++){
        for(int j = 1; j<7; j++){
            for(int k = 1; k<7; k++){
                for(int m = 1; m<7; m++){
                    fix_list.push_back(i*1000+j*100+k*10+m);

                }
            }
        }
    }
}

int computer_guess(int temp){
    if (temp == 0){
        computer_gues = 1122;
    }else{
        computer_gues = 0;
        while (computer_gues == 0) {
            int index = rand() % 1296;
            computer_gues = fix_list[index];

        }
    }

    return 0;
}


int delete_pegs(vector<int> guessVector, vector<int> correctVector, int &numCorrectLoc, int &numIncorrectLoc){
    int check_peg;
    vector<int> check_peg_vec;



    if ((numIncorrectLoc+numCorrectLoc) == 4){
        for (int i = 0; i < 1296;i++){

            check_peg_vec.clear();

            check_peg = full_list[i];
            int match_num = 0;
            for (int j = 1; j <= 4; j++) {
                int a = check_peg % 10;
                check_peg_vec.push_back(a);
                check_peg /= 10;
            }

            for (int k = 0; k <= 3; k++) {
                if (find(correctVector.begin(),correctVector.end(), check_peg_vec[k]) != correctVector.end()){
                    match_num += 1;
                }else{
                    match_num += 0;
                }
            }
            if (match_num != 4) {
                fix_list[i] = 0;
            }



        }

    }

    if ((numIncorrectLoc+numCorrectLoc) == 3){
        for (int i = 0; i < 1296;i++){

            check_peg_vec.clear();

            check_peg = full_list[i];
            int match_num = 0;
            for (int j = 1; j <= 4; j++) {
                int a = check_peg % 10;
                check_peg_vec.push_back(a);
                check_peg /= 10;
            }

            for (int k = 0; k <= 3; k++) {
                if (find(correctVector.begin(),correctVector.end(), check_peg_vec[k]) != correctVector.end()){
                    match_num += 1;
                }else{
                    match_num += 0;
                }
            }
            if (match_num < 3) {
                fix_list[i] = 0;
            }



        }
    }
    if ((numIncorrectLoc+numCorrectLoc) == 2){
        for (int i = 0; i < 1296;i++){

            check_peg_vec.clear();

            check_peg = full_list[i];
            int match_num = 0;
            for (int j = 1; j <= 4; j++) {
                int a = check_peg % 10;
                check_peg_vec.push_back(a);
                check_peg /= 10;
            }

            for (int k = 0; k <= 3; k++) {
                if (find(correctVector.begin(),correctVector.end(), check_peg_vec[k]) != correctVector.end()){
                    match_num += 1;
                }else{
                    match_num += 0;
                }
            }
            if (match_num < 2) {
                fix_list[i] = 0;
            }



        }
    }
    if ((numIncorrectLoc+numCorrectLoc) == 1){
        for (int i = 0; i < 1296;i++){

            check_peg_vec.clear();

            check_peg = full_list[i];
            int match_num = 0;
            for (int j = 1; j <= 4; j++) {
                int a = check_peg % 10;
                check_peg_vec.push_back(a);
                check_peg /= 10;
            }

            for (int k = 0; k <= 3; k++) {
                if (find(correctVector.begin(),correctVector.end(), check_peg_vec[k]) != correctVector.end()){
                    match_num += 1;
                }else{
                    match_num += 0;
                }
            }
            if (match_num < 1) {
                fix_list[i] = 0;
            }



        }
    }



    return 0;
}





void Computerguess() {
    vector<int> guessVector;
    vector<int> correctVector;
    int temp = 0;
    int numCorrectLoc;
    int numIncorrectLoc;

    generate_new_list();



    cout << "Please enter your gusse: " << endl ;
    cin >> human_guess;
    for (int i = 1; i <= 4; i++) {
        correctVector.push_back(human_guess % 10);
        human_guess /= 10;
    }


    computer_guess(temp);
    temp += 1;
    computer_gues_save = computer_gues;
    for (int i = 1; i <= 4; i++) {
        guessVector.push_back(computer_gues % 10);
        computer_gues /= 10;
    }

    check(guessVector, correctVector, 0, numCorrectLoc, numIncorrectLoc);

    while (numCorrectLoc != 4) {
        for (int i = 0; i < 1296;i++){
            if(fix_list[i] == computer_gues_save){
                fix_list[i] = 0;
            }
        }
        delete_pegs(guessVector, correctVector, numCorrectLoc, numIncorrectLoc);
        computer_guess(temp);
        temp += 1;
        cout << computer_gues << endl;
        guessVector.clear();
        computer_gues_save = computer_gues;
        for (int i = 1; i <= 4; i++) {
            guessVector.push_back(computer_gues % 10);
            computer_gues /= 10;
        }

        check(guessVector, correctVector, 0, numCorrectLoc, numIncorrectLoc);

    }



}