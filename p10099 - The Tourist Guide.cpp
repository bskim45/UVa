#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int graph[101][101];

int main() {
    ios::sync_with_stdio(false);

    string buf;

    int v_num = 0, e_num = 0;
    cin >> v_num >> e_num;

    for (int case_idx = 1; v_num != 0; case_idx++) {
        memset(graph, -1, sizeof graph);

        for (int i = 0; i < e_num; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = c;
            graph[b][a] = c;
        }

        for (int i = 1; i <= v_num; i++) {
            graph[i][i] = 0;
        }

        int source = 0, sink = 0, passengers = 0;
        cin >> source >> sink >> passengers;

        for (int k = 1; k <= v_num; k++) {
            for (int i = 1; i <= v_num; i++) {
                for (int j = 1; j <= v_num; j++) {
                    graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
                }
            }
        }

        int min_trips = source == sink ? 1 : ceil((float)passengers / (graph[source][sink] - 1));

        cout << "Scenario #" << case_idx << endl;
        cout << "Minimum Number of Trips = " << min_trips << endl << endl;

        cin >> v_num >> e_num;
    }


    return 0;
}
