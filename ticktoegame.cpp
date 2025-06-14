#include <iostream>
using namespace std;

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

char currentPlayer = 'X';

void printBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < 3 &&
           col >= 0 && col < 3 &&
           board[row][col] == ' ';
}

bool checkWin(char player) {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player &&
             board[i][1] == player &&
             board[i][2] == player) ||
            (board[0][i] == player &&
             board[1][i] == player &&
             board[2][i] == player)) {
            return true;
        }
    }

    // Diagonals
    if ((board[0][0] == player &&
         board[1][1] == player &&
         board[2][2] == player) ||
        (board[0][2] == player &&
         board[1][1] == player &&
         board[2][0] == player)) {
        return true;
    }

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int row, col;
    bool gameEnded = false;

    while (!gameEnded) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column: 0 1): ";
        cin >> row >> col;

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnded = true;
            } else if (isDraw()) {
                printBoard();
                cout << "The game is a draw!" << endl;
                gameEnded = true;
            } else {
                switchPlayer();
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}
