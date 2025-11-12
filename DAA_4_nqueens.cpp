#include <iostream>
#include <vector>
using namespace std;

int totalBacktracking = 0;

void printBoard(vector<vector<char>>& board) {
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board.size(); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafeBacktrack(vector<vector<char>>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

void solveBacktracking(vector<vector<char>>& board, int row, int n) {
    if(row == n) {
        totalBacktracking++;
        printBoard(board);
        return;
    }

    for(int col = 0; col < n; col++) {
        if(isSafeBacktrack(board, row, col, n)) {
            board[row][col] = 'Q';
            solveBacktracking(board, row + 1, n);
            board[row][col] = '.'; // backtrack
        }
    }
}


int main() {
    int n;
    cout << "Enter value of N for N-Queens: ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    cout << "\nSolving using Backtracking (Row-wise)\n";
    solveBacktracking(board, 0, n);
    cout << "Total Solutions (Backtracking): " << totalBacktracking << "\n";

    return 0;
}