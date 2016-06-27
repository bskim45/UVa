#include <iostream>
#include <sstream>
#include <limits>
#include <vector>

using namespace std;

vector<string> unsorted(200);
vector<string> sorted(200);

int main(void) {
    ios::sync_with_stdio(false);

    int case_num, lines;
    cin >> case_num;

    for (int case_idx = 0; case_idx < case_num; case_idx++) {

        cin >> lines;

        // io fix
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // parse lines
        for (int i = lines - 1; i >= 0; i--) {
            getline(cin, unsorted[i]);
        }

        for (int i = lines - 1; i >= 0; i--) {
            getline(cin, sorted[i]);
        }

        // compare
        int moves = 0;

        for (int i = 0, j = 0; i < lines && j < lines; i++) {
            if (unsorted[i] != sorted[j]) {
                moves++;
            }
            else {
                j++;
            }
        }

        for (int i = lines - moves; i < lines; i++) {
            cout << sorted[i] << endl;
        }

        cout << endl;

    }

    return 0;
}
