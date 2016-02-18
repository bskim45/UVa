#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int row, col, cnt = 0;
    bool isFirst = true;
    char map[100][100];

    cin >> row >> col;
    while (row != 0 || col != 0) {
        for (int i = 0; i < row; i++)
            cin >> map[i];

        int ans[100][100] = {0};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (map[i][j] == '*') {
                    for (int k = i - 1; k <= i + 1; k++) {
                        for (int l = j - 1; l <= j + 1; l++) {
                            if (!((k >= 0) && (l >= 0) && (k < row) && (l < col)))
                                continue;

                            ans[k][l]++;
                        }
                    }
                }
            }

        }

        if (!isFirst)
            cout << endl;

        isFirst = false;

        cout << "Field #" << ++cnt << ":" << endl;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (map[i][j] == '*')
                    cout << map[i][j];
                else
                    cout << ans[i][j];

            }
            cout << endl;
        }

        cin >> row >> col;
    }
}
