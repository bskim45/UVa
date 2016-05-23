#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>

#define MAX INT_MAX / 2
using namespace std;

/*
 * dp[i][j] -> cost to s[i] where fuel is j
 *          = dp[i - 1][j + dis + fill] + c[i].price * fill
 */
typedef struct {
    int distance;
    int price;
} Station;

Station s[102];
int dp[102][201];

int main(void) {
//    ios::sync_with_stdio(false);

    int case_num = 0;
    cin >> case_num;
    cin.ignore();

    string buf;
    getline(cin, buf);

    for (int cases = 1; cases <= case_num; cases++) {
        int t;

        cin >> t;
        cin.ignore();

        int n = 1;

        s[0].distance = 0;
        s[0].price = 0;

        while (getline(cin, buf)) {
            if(!buf[0]) break;
            stringstream ss(buf);
            ss >> s[n].distance >> s[n].price;
            n++;
        }

        // trick: set destination as max gas station
        s[n].distance = t;
        s[n].price = MAX;

        // init array
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 200; j++) {
                dp[i][j] = MAX;
            }
        }
        dp[0][100] = 0;

        for (int i = 1; i <= n; i++) {
            int d = s[i].distance - s[i - 1].distance;

            for (int j = d; j <= 200; j++)
                dp[i][j - d] = dp[i - 1][j];

            for (int j = 1; j <= 200; j++)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + s[i].price);
        }

        int ans = MAX;
        for (int i = 100; i <= 200; i++)
            ans = min(ans, dp[n][i]);

        if (ans >= MAX)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;

        // newline for next result
        if (cases != case_num) {
            cout << endl;
        }
    }

    return 0;
}
