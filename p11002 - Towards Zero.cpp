#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int board[70][70] = { 0 };
unordered_map<int, bool> sums[70][70];

void init() {
    for (int i = 0; i < 70; i++) {
        for (int j = 0; j < 70; j++) {
            board[i][j] = -1;
            sums[i][j].clear();
        }
    }
}


int main() {
    ios::sync_with_stdio(false);

    int rows = 0;
    cin >> rows;

    while (rows != 0) {
        init();

        int input = 0;
        for (int i = 1; i <= rows * 2 - 1; i++) {
            int limit = i <= rows ? i : rows * 2 - i;
            for (int j = 1; j <= limit; j++) {
                cin >> input;
                board[i][j] = abs(input);
            }
        }

        sums[2 * rows - 1][1][board[2 * rows - 1][1]] = true;
        sums[2 * rows - 1][1][-board[2 * rows - 1][1]] = true;

        for (int i = rows * 2 - 1; i >= 2; i--) {
            if (i > rows) {
                for (int j = 1; j <= rows * 2 - i; j++) {
                    for (auto iter = sums[i][j].begin(); iter != sums[i][j].end(); ++iter) {
                        if (board[i - 1][j] != -1) {

                            // left
                            sums[i - 1][j][iter->first + board[i - 1][j]] = true;
                            sums[i - 1][j][iter->first - board[i - 1][j]] = true;
                        }

                        if (board[i - 1][j + 1] != -1) {

                            // right
                            sums[i - 1][j + 1][iter->first + board[i - 1][j + 1]] = true;
                            sums[i - 1][j + 1][iter->first - board[i - 1][j + 1]] = true;
                        }
                    }
                }
            }
            else {
                for (int j = 1; j <= i; j++) {
                    for (auto iter = sums[i][j].begin(); iter != sums[i][j].end(); ++iter) {
                        if (board[i - 1][j - 1] != -1) {
                            // left
                            sums[i - 1][j - 1][iter->first + board[i - 1][j - 1]] = true;
                            sums[i - 1][j - 1][iter->first - board[i - 1][j - 1]] = true;
                        }

                        if (board[i - 1][j] != -1) {
                            // right
                            sums[i - 1][j][iter->first + board[i - 1][j]] = true;
                            sums[i - 1][j][iter->first - board[i - 1][j]] = true;
                        }
                    }
                }
            }
        }

        auto min_elem = min_element(sums[1][1].begin(), sums[1][1].end(), [](const pair<int, bool> &a, const pair<int, bool> &b)
        {
            return abs(a.first) < abs(b.first);
        });

        cout << abs(min_elem->first) << endl;
        cin >> rows;
    }

    return 0;
}
