#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int case_num, lines;
    cin >> case_num;

    string buf;

    for (int case_idx = 0; case_idx < case_num; case_idx++) {

        cin >> lines;
        vector<string> unsorted(lines);
        map<string, int> position;
        vector<pair<string, int>> sequence;
        
        // io fix
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // parse lines
        for (int i = lines - 1; i >= 0; i--) {
            getline(cin, unsorted[i]);
        }

        for (int i = lines - 1; i >= 0; i--) {
            getline(cin, buf);
            position[buf] = i;
        }

        // compare
        int moves = 0;

        for(int i = 0; i < lines; i++) {
            int pos = position[unsorted[i]];

            if (pos != i - moves) {
                moves++;
                sequence.push_back(make_pair(unsorted[i], pos));
            }
        }

        sort(sequence.begin(), sequence.end(), [&](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        });

        for_each(sequence.begin(), sequence.end(), [](const pair<string, int>& s) {
            cout << s.first << endl;
        });

        cout << endl;

    }

    return 0;
}
