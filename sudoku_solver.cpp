#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int val, int n) {
    for (int i = 0; i < n; i++) {
        if (board[row][i] == '0' + val) {
            return false;
        }
        if (board[i][col] == '0' + val) {
            return false;
        }
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == '0' + val) {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board) {
    int n = board.size();
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == '.') {
                for (int i = 1; i <= 9; i++) {
                    if (isSafe(board, row, col, i, n)) {
                        board[row][col] = '0' + i;                     
                        bool aageSolPossible = solve(board);
                        if (aageSolPossible) {
                            return true;
                        }
                        else {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char> (9));
    // Enter number or . for empty space
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    bool ans = solve(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}