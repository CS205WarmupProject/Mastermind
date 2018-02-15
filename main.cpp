#include <iostream>
#include "HumanGame.cpp"
#include "ComputerGame.cpp"
#include <list>
#include <vector>
#include <ctime>
using namespace std;

int main() {
    int choice;
    char go;
    int status=0;
    std::cout << "Hello! Welcome to Play Mastermind! Please press:\n1. The instruction of this game\n2. You guess\n3. Computer guess"<< std::endl;
    std::cin >>choice;
    switch (choice) {
        case 1: {
            std::cout << "Mastermind is a code-breaking game for two players. You can guess or let computer guess 4 digit numbers(1-6) in few times." << std::endl;
            while(status==0) {
                std::cout << "Menu or quit?(Y/N)" << std::endl;
                cin >> go;
                if (go == 'Y') {
                    main();
                    status=1;
                } else if (go == 'N') {
                    exit(0);
                    status=1;
                } else {
                    cout << "I don't understand." << endl;
                }
            }
            break;
        }
        case 2: {
            HumanGame();
            break;
        }
        case 3: {
            Computerguess();
            break;
        }
    }
    return 0;
}


