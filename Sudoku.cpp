#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 9; // Size of the Sudoku grid (9x9)

// Function to check if placing a number is valid
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Check row
    for (int x = 0; x < SIZE; ++x) {
        if (board[row][x] == num) {
            return false;
        }
    }
    // Check column
    for (int x = 0; x < SIZE; ++x) {
        if (board[x][col] == num) {
            return false;
        }
    }
    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            // Find an empty cell
            if (board[row][col] == 0) {
                // Try numbers 1-9
                for (int num = 1; num <= 9; ++num) {
                    if (isValid(board, row, col, num)) {
                        // Place the number
                        board[row][col] = num;

                        // Recur to solve the rest of the grid
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // Backtrack if placing num doesn't lead to a solution
                        board[row][col] = 0;
                    }
                }
                // If no number is valid, return false
                return false;
            }
        }
    }
    // If no empty cell remains, the puzzle is solved
    return true;
}

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout<<"------------------------"<<endl;
}

int main() {
    // Example Sudoku puzzle (0 represents an empty cell)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        cout << "Solved Sudoku Board:\n";
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
