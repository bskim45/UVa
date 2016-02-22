#include <iostream>
#include <sstream>
#include <algorithm>
#include <climits>

constexpr int INF = INT_MAX / 2;

using namespace std;

int dist[501][501];
int fire_pos[101];
int fire_num, inter_num;

void init(void) {
    for (int i = 1; i <= inter_num; i++) {
        for (int j = 1; j <= inter_num; j++) {
            dist[i][j] = INF;
        }

        dist[i][i] = 0;
    }
}

void floyd() {
    for (int k = 1; k <= inter_num; k++) {
        for (int i = 1; i <= inter_num; i++) {
            for (int j = 1; j <= inter_num; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);

    int case_num;
    cin >> case_num;

    string buf;

    for (int case_idx = 0; case_idx < case_num; case_idx++) {

        cin >> fire_num >> inter_num;

        for (int i = 1; i <= fire_num; i++) {
            cin >> fire_pos[i];
        }

        // io fix
        cin.ignore();

        // initialize
        init();

        // parse roads vector
        while (getline(cin, buf)) {
            if (buf.empty())
                break;

            istringstream ss(buf);

            int a, b, c;
            ss >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }

        floyd();

        int min_fire_dist[501];
        int max_short_dist = 0;

        // check maxinum fire dist
        for (int i = 1; i <= inter_num; i++) {
            min_fire_dist[i] = INF;

            for (int j = 1; j <= fire_num; j++) {
                min_fire_dist[i] = min(min_fire_dist[i], dist[i][fire_pos[j]]);
            }

            max_short_dist = max(max_short_dist, min_fire_dist[i]);
        }

        int min_new_fire_pos = 1;

        // position new fire
        for (int i = 1; i <= inter_num; i++) {
            int new_max = 0;

            // local max
            for (int j = 1; j <= inter_num; j++) {
                int new_min = min(dist[i][j], min_fire_dist[j]);
                new_max = max(new_max, new_min);
            }

            // new local max is longer
            if (new_max < max_short_dist) {
                max_short_dist = new_max;
                min_new_fire_pos = i;
            }
        }

        cout << min_new_fire_pos << endl;

        if (case_idx != case_num - 1)
            cout << endl;
    }

    return 0;
}
