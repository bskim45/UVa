#include <iostream>
#include <cstring>

constexpr int MAX_SUM = 100;
using namespace std;

int board[70][70] = { 0 };
bool sum_pos[70][70][MAX_SUM];
bool sum_neg[70][70][MAX_SUM];

void insert(int row, int col, int value) {
    if (value >= 0)
        sum_pos[row][col][value] = true;
    else
        sum_neg[row][col][-value] = true;
}

int main() {
    ios::sync_with_stdio(false);

    int rows = 0;
    cin >> rows;

    while (rows != 0) {
        memset(board, -1, sizeof board);
        memset(sum_pos, false, sizeof sum_pos);
        memset(sum_neg, false, sizeof sum_neg);

        int input = 0;
        for (int i = 1; i <= rows * 2 - 1; i++) {
            int limit = i <= rows ? i : rows * 2 - i;
            for (int j = 1; j <= limit; j++) {
                cin >> input;
                board[i][j] = abs(input);
            }
        }

        insert(2 * rows - 1, 1, board[2 * rows - 1][1]);
        insert(2 * rows - 1, 1, -board[2 * rows - 1][1]);

        for (int i = rows * 2 - 1; i >= 2; i--) {
            if (i > rows) {
                for (int j = 1; j <= rows * 2 - i; j++) {
                    for (int k = 0; k < MAX_SUM; k++) {
                        if (!sum_pos[i][j][k] && !sum_neg[i][j][k])
                            continue;
                        
                        if (sum_pos[i][j][k]) {
                            if (board[i - 1][j] != -1) {

                                // left
                                insert(i - 1, j, k + board[i - 1][j]);
                                insert(i - 1, j, k - board[i - 1][j]);
                            }

                            if (board[i - 1][j + 1] != -1) {

                                // right
                                insert(i - 1, j + 1, k + board[i - 1][j + 1]);
                                insert(i - 1, j + 1, k - board[i - 1][j + 1]);
                            }
                        }
                        
                        if (sum_neg[i][j][k]) {
                            if (board[i - 1][j] != -1) {

                                // left
                                insert(i - 1, j, -k + board[i - 1][j]);
                                insert(i - 1, j, -k - board[i - 1][j]);
                            }

                            if (board[i - 1][j + 1] != -1) {

                                // right
                                insert(i - 1, j + 1, -k + board[i - 1][j + 1]);
                                insert(i - 1, j + 1, -k - board[i - 1][j + 1]);
                            }
                        }
                    }
                }
            }
            else {
                for (int j = 1; j <= i; j++) {
                    for (int k = 0; k < MAX_SUM; k++) {
                        if (!sum_pos[i][j][k] && !sum_neg[i][j][k])
                            continue;

                        if (sum_pos[i][j][k]) {

                            if (board[i - 1][j - 1] != -1) {
                                // left
                                insert(i - 1, j - 1, k + board[i - 1][j - 1]);
                                insert(i - 1, j - 1, k - board[i - 1][j - 1]);
                            }

                            if (board[i - 1][j] != -1) {
                                // right
                                insert(i - 1, j, k + board[i - 1][j]);
                                insert(i - 1, j, k - board[i - 1][j]);
                            }
                        }

                        if(sum_neg[i][j][k]) {
                            if (board[i - 1][j - 1] != -1) {
                                // left
                                insert(i - 1, j - 1, -k + board[i - 1][j - 1]);
                                insert(i - 1, j - 1, -k - board[i - 1][j - 1]);
                            }

                            if (board[i - 1][j] != -1) {
                                // right
                                insert(i - 1, j, -k + board[i - 1][j]);
                                insert(i - 1, j, -k - board[i - 1][j]);
                            }
                        }
                    }
                }
            }
        }

        int min = MAX_SUM;

        for (int i = 0; i < MAX_SUM; i++) {
            if (sum_pos[1][1][i] || sum_neg[1][1][i]) {
                min = i;
                break;
            }
        }

        cout << min << endl;
        cin >> rows;
    }

    return 0;
}
