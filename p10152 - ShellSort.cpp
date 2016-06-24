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
        vector<string> sequence;
        
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
            if (position[unsorted[i]] != i - moves) {
                moves++;
                sequence.push_back(unsorted[i]);
            }
        }

        sort(sequence.begin(), sequence.end(), [&](const string& a, const string& b) {
            return position[a] < position[b];
        });

        for_each(sequence.begin(), sequence.end(), [](const string& s) {
            cout << s << endl;
        });

        cout << endl;

    }

    return 0;
}
