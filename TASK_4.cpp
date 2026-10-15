#include <iostream>
using namespace std;


int N;
int** board;                                   // N x N board made on the heap
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};      // the 8 knight moves (row)
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};      // the 8 knight moves (column)

// makes the board and marks every square as not visited (-1)
void createBoard() {
    board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
        for (int j = 0; j < N; j++) board[i][j] = -1;
    }
}

// frees each row first, then the array of row pointers
void deleteBoard() {
    for (int i = 0; i < N; i++) delete[] board[i];
    delete[] board;
    board = nullptr;
}

// square must be inside the board and not visited yet
bool isSafe(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N && board[r][c] == -1;
}

bool solveKnightTour(int row, int col, int moveNumber) {
    board[row][col] = moveNumber;               // put the knight here
    if (moveNumber == N * N) return true;       // every square is visited, done

    for (int k = 0; k < 8; k++) {
        int nr = row + dx[k], nc = col + dy[k];
        if (isSafe(nr, nc) && solveKnightTour(nr, nc, moveNumber + 1))
            return true;                        // this path worked, stop trying
    }
    board[row][col] = -1;                       // dead end, undo and step back
    return false;
}

void displayBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << board[i][j] << "\t";
        cout << "\n";
    }
}

int main() {
    int x, y;
    cout << "N: "; cin >> N;
    if (N <= 0) { cout << "Invalid board size\n"; return 0; }

    cout << "start row col: "; cin >> x >> y;
    if (x < 0 || x >= N || y < 0 || y >= N) {
        cout << "Bad start position\n";
        return 0;
    }

    createBoard();
    if (solveKnightTour(x, y, 1)) displayBoard();
    else cout << "No tour found\n";

    deleteBoard();                              // give the memory back
    return 0;
}