#include <iostream>

const int ROWS = 3;
const int COLS = 3;

char board[ROWS][COLS] = {{' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '}};

// A function to draw the board
void drawBoard() {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        std::cout << i << " ";
        for (int j = 0; j < COLS; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// A Function to check moves
bool makeMove(int row, int col, char symbol) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        std::cout << "Invalid move" << std::endl;
        return false;
    }

    if (board[row][col] != ' ') {
        std::cout << "Position already occupied" << std::endl;
        return false;
    }

    board[row][col] = symbol;
    return true;
}

// A Function to determine the winner
bool checkWin(char symbol) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }

    return false;
}

int main() {
    char player = 'X';

    while (true) {
        drawBoard();
        std::cout << "Player " << player << ", enter your move (row col): ";
        int row, col;
        std::cin >> row >> col;

        if (!makeMove(row, col, player)) {
            continue;
        }

        if (checkWin(player)) {
            std::cout << "Player " << player << " wins!" << std::endl;
            break;
        }

        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    return 0;
}
