#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 9; // Size of the Sudoku grid (9x9)

void printSudoku9x9(const vector<vector<int> >& board) {
    cout << "-------------------------" << endl;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            cout << board[y][x] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

bool canPlace9x9(const vector<vector<int> >& board, int row, int col, int n) {
    if (board[row][col] != 0) return false;
    bool status = true;
    int gridx = (col / 3) * 3;
    int gridy = (row / 3) * 3;
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == n) { status = false; break; }
        if (board[i][col] == n) { status = false; break; }
        if (board[gridy + i / 3][gridx + i % 3] == n) { status = false; break; }
    }
    return status;
}

void nextEmpty(const vector<vector<int> >& board, int row, int col, int& rowNext, int& colNext) {
    int indexNext = SIZE * SIZE + 1;
    for (int i = row * SIZE + col + 1; i < SIZE * SIZE; i++) {
        if (board[i / SIZE][i % SIZE] == 0) {
            indexNext = i;
            break;
        }
    }
    rowNext = indexNext / SIZE;
    colNext = indexNext % SIZE;
}

void copyArray(const vector<vector<int> >& src, vector<vector<int> >& dest) {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            dest[y][x] = src[y][x];
        }
    }
}

vector<int> findPlaceables(const vector<vector<int> >& board, int row, int col) {
    vector<int> placeables;
    for (int n = 1; n <= SIZE; n++) {
        if (canPlace9x9(board, row, col, n)) {
            placeables.push_back(n);
        }
    }
    return placeables;
}

bool solveSudoku9x9(vector<vector<int> >& board, int row, int col) {
    if (row >= SIZE) return true;
    if (board[row][col] != 0) {
        int rowNext, colNext;
        nextEmpty(board, row, col, rowNext, colNext);
        return solveSudoku9x9(board, rowNext, colNext);
    }

    vector<int> placeables = findPlaceables(board, row, col);
    if (placeables.empty()) return false;

    bool status = false;
    for (size_t i = 0; i < placeables.size(); ++i) {
        int n = placeables[i];
        vector<vector<int> > boardCopy = board;
        boardCopy[row][col] = n;
        int rowNext = row, colNext = col;
        nextEmpty(boardCopy, row, col, rowNext, colNext);
        if (solveSudoku9x9(boardCopy, rowNext, colNext)) {
            board = boardCopy;
            status = true;
            break;
        }
    }
    return status;
}

int main() {
    int tempBoard1[SIZE][SIZE] = {
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

    int tempBoard2[SIZE][SIZE] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    vector<vector<int> > board1(SIZE, vector<int>(SIZE));
    vector<vector<int> > board2(SIZE, vector<int>(SIZE));

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board1[i][j] = tempBoard1[i][j];
            board2[i][j] = tempBoard2[i][j];
        }
    } 

    if (solveSudoku9x9(board1, 0, 0)) cout << "Successfully solved board 1!" << endl;
    printSudoku9x9(board1);
    if (solveSudoku9x9(board2, 0, 0)) cout << "Successfully solved board 2!" << endl;
    printSudoku9x9(board2);

    return 0;
}
