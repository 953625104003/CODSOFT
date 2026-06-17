#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | "
             << board[i][1] << " | "
             << board[i][2] << endl;

        if (i < 2)
            cout << "---|---|---" << endl;
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void resetBoard() {
    char value = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
}

int main() {
    char playAgain;

    do {
        resetBoard();
        char player = 'X';
        int choice;

        while (true) {
            displayBoard();

            cout << "Player " << player
                 << ", enter position (1-9): ";
            cin >> choice;

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (choice < 1 || choice > 9 ||
                board[row][col] == 'X' ||
                board[row][col] == 'O') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = player;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << player
                     << " wins!\n";
                break;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
