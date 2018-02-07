#include <iostream>
#include "ComputerGame.cpp"
#include <list>
#include <vector>
#include <ctime>
using namespace std;

int main() {
    int choice;

    std::cout << "Hello! Welcome to Play Mastermind! Please press:\n1. The instruction of this game\n2. You guess\n3. Computer guess"<< std::endl;
    std::cin >>choice;
    switch (choice) {
        case 1: {
            std::cout << "lol" << std::endl;
            break;
        }
        case 2: {
            HumanGame();
            break;
        }
        case 3: {
            break;
        }
    }
    return 0;
}


