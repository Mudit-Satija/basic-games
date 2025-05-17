#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };

char currentPlayer = 'X';

// Display the board
void displayBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Mark the board
bool markBoard(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Cell already taken! Choose another one.\n";
        return false;
    } else {
        board[row][col] = currentPlayer;
        return true;
    }
}

// Switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Check for a win condition
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||  // Row check
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) { // Column check
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||  // Main diagonal
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {  // Anti-diagonal
        return true;
    }

    return false;
}

int main() {
    int position;

    for (int turn = 0; turn < 9; turn++) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid position! Try again.\n";
            turn--;
            continue;
        }

        if (!markBoard(position)) {
            turn--;
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins! \n";
            return 0;  // End the game
        }

        switchPlayer();
    }

    displayBoard();
    cout << "It's a draw! \n";
    return 0;
}
     
