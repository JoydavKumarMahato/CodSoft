#include <iostream>
using namespace std;

char matrix[3][3];
char turn = 'X';

void reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }
}

void model() {
    cout << "\n";
    cout << "     |     |     " << endl;
    cout << "  " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << "\n";
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << "\n";
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << "\n";
    cout << "     |     |     " << endl;
}

bool checkvictory() {
    for (int i = 0; i < 3; i++) {
        if ((matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] != ' ') || 
            (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] != ' ')) {
            return true;
        }
    }
    if ((matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[0][0] != ' ') ||
        (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[0][2] != ' ')) {
        return true;
    }
    return false;
}

bool checktie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void input() {
    int digit;
    int row = -1, column = -1;
    while (true) {
        if (turn == 'X') {
            cout << "Enter player X: ";
        } else {
            cout << "Enter player O: ";
        }
        cin >> digit;

        if (digit < 1 || digit > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue;
        }

        switch (digit) {
        case 1: 
            row = 0; 
            column = 0; 
            break;
        case 2: 
            row = 0; 
            column = 1; 
            break;
        case 3: 
            row = 0; 
            column = 2; 
            break;
        case 4: 
            row = 1; 
            column = 0; 
            break;
        case 5: 
            row = 1; 
            column = 1; 
            break;
        case 6: 
            row = 1;
            column = 2; 
            break;
        case 7:    
            row = 2; 
            column = 0; 
            break;
        case 8: 
            row = 2; 
            column = 1; 
            break;
        case 9: 
            row = 2; 
            column = 2; 
            break;
        default: cout << "Invalid input" << endl; return;
    }

        if (matrix[row][column] != 'X' && matrix[row][column] != 'O') {
            matrix[row][column] = turn;
            model();
            turn = (turn == 'X') ? 'O' : 'X';
            break;
        } else {
            cout << "Place is already filled. Try again." << endl;
        }
    }
}


int main() {
    int op;
    do {
        system("cls");
        cout << "\nWelcome to the TIC-TAC-TOE GAME" << endl;
        cout << "\nThe numbers represent the positions:\n" << endl;
        cout << "     |     |     " << endl;
        cout << "  1  |  2  |  3  \n";
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  4  |  5  |  6  \n";
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  7  |  8  |  9  \n";
        cout << "     |     |     " << endl;

        cout << "\nFirst player is player X" << endl;
        cout << "Second player is player O" << endl;
        turn='X';

        reset();
        model();

        while (true) {
            input();
            if (checkvictory()) {
                cout<<"\n-------------------------------------------\n";
                cout << "Player " << (turn == 'X' ? 'O' : 'X') << " wins....!" << endl;
                cout<<"\n-------------------------------------------\n";
                break;
            }
            if (checktie()) {
                cout << "It's a tie..!" << endl;
                break;
            }
        }

        cout << "\nDo you want to play again?" << endl;
        cout << "1. Yes\n2. No" << endl;
        cout << "Enter no.: ";
        cin >> op;
    } while (op == 1);

    return 0;
}
