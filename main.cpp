#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 0 = player win, 1 = pc win, 2 = tie, 3 = error
int checkWin(string playerChoice, string pcChoice){
    if(playerChoice.compare("Rock") == 0) {
        if(pcChoice.compare("Rock") == 0) {
            return 2;
        }
        if(pcChoice.compare("Paper") == 0) {
            return 1;
        }
        return 0;
    }
    if (playerChoice.compare("Paper") == 0) {
        if(pcChoice.compare("Rock") == 0) {
            return 0;
        }
        if(pcChoice.compare("Paper") == 0) {
            return 2;
        }
        return 1;
    }
    if(playerChoice.compare("Scissors") == 0) {
        if(pcChoice.compare("Rock") == 0) {
            return 1;
        }
        if(pcChoice.compare("Paper") == 0) {
            return 0;
        }
        return 2;
    }
    return 3;
}

int main()
{
    cout << "Rock, Paper, or Scissors? ";
    string playerChoice;
    cin >> playerChoice;
    if (playerChoice.compare("Rock") == 0) {
        cout << "You chose Rock!\n";
    } else if (playerChoice.compare("Paper") == 0) {
        cout << "You chose Paper!\n";
    } else if (playerChoice.compare("Scissors") == 0) {
        cout << "You chose Scissors!\n";
    } else {
        cout << "Please choose Rock, Paper or Scissors!\n";
        return 0;
    }
    srand(static_cast<unsigned int>(time(0)));
    int pcDiceRoll = rand() % 3;
    string pcChoice;
    if(pcDiceRoll == 0){
        pcChoice = "Rock";
        cout << "PC chose Rock!\n";
    } else if(pcDiceRoll == 1){
        pcChoice = "Paper";
        cout << "PC chose Paper!\n";
    } else{
        pcChoice = "Scissors";
        cout << "PC chose Scissors!\n";
    }
    int winCheck = checkWin(playerChoice, pcChoice);
    if(winCheck == 0) {
        cout << "You won!\n";
    } else if (winCheck == 1) {
        cout << "You lost!\n";
    } else if (winCheck == 2) {
        cout << "You tied!\n";
    } else {
        cout << "This guy sucks at writing code!\n";
    }
}
