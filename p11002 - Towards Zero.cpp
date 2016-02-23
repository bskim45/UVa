#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int board[70][70] = { 0 };
set<int> sums[70][70];

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

        sums[2 * rows - 1][1].insert(board[2 * rows - 1][1]);
        sums[2 * rows - 1][1].insert(-board[2 * rows - 1][1]);

        for (int i = rows * 2 - 1; i >= 2; i--) {
            if (i > rows) {
                for (int j = 1; j <= rows * 2 - i; j++) {
                    for (auto iter = sums[i][j].begin(); iter != sums[i][j].end(); ++iter) {
                        if (board[i - 1][j] != -1) {

                            // left
                            sums[i - 1][j].insert(*iter + board[i-1][j]);
                            sums[i - 1][j].insert(*iter - board[i-1][j]);
                        }

                        if (board[i - 1][j + 1] != -1) {

                            // right
                            sums[i - 1][j + 1].insert(*iter + board[i-1][j+1]);
                            sums[i - 1][j + 1].insert(*iter - board[i-1][j+1]);
                        }
                    }
                }
            }
            else {
                for (int j = 1; j <= i; j++) {
                    for (auto iter = sums[i][j].begin(); iter != sums[i][j].end(); ++iter) {
                        if (board[i - 1][j - 1] != -1) {
                            // left
                            sums[i - 1][j - 1].insert(*iter + board[i-1][j-1]);
                            sums[i - 1][j - 1].insert(*iter - board[i-1][j-1]);
                        }

                        if (board[i - 1][j] != -1) {
                            // right
                            sums[i - 1][j].insert(*iter + board[i-1][j]);
                            sums[i - 1][j].insert(*iter - board[i-1][j]);
                        }
                    }
                }
            }
        }

        auto min_elem = min_element(sums[1][1].begin(), sums[1][1].end(), [](const int& a, const int& b)
        {
            return abs(a) < abs(b);
        });

        cout << abs(*min_elem) << endl;
        cin >> rows;
    }

    return 0;
}
