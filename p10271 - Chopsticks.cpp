#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int chops[5001];
int dp[1009][5001];

/* s = set of chopsticks, x = # of chopsticks
 * v = array of chopsticks
 * f = sum of badness
 * f(s, x) = min{f(s, x - 1), f(s - 1, x - 2) + (v(x-1) - v(x))^2)}
 *         = 0  if s = 0
 *         = oo if x < 3 * s
 */

int main(void) {
    ios::sync_with_stdio(false);

    int case_num = 0;
    cin >> case_num;

    for(int cases = 1; cases <= case_num; cases++) {
        int k, n;

        cin >> k >> n;
        k += 8;

        // put it in reverse order
        for(int i = n; i >= 1; i--) {
            cin >> chops[i];
        }

        // init dp array
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        // initial value
        for(int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for(int i = 1; i <= k; i++) {
            for(int j = i * 3; j <= n; j++) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-2] + (chops[j-1]-chops[j]) * (chops[j-1]-chops[j]));
            }
        }

        cout << dp[k][n] << endl;

    }

    return 0;
}
