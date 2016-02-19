#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char* argv[]) {

    ios::sync_with_stdio(false);
    
    int case_num;
    cin >> case_num;

    for (int case_idx = 0; case_idx < case_num; case_idx++) {
        int sim_days, party_num, count = 0;
        cin >> sim_days >> party_num;

        vector<int> party_index;
        int input;

        for (int i = 0; i < party_num; i++) {
            cin >> input;
            party_index.push_back(input);
        }

        vector<bool> bitmap;
        bitmap.resize(sim_days + 1, false);
        bitmap[0] = false;

        // start simulation
        for (int i = 0; i < party_num; i++) {
            for (int j = party_index[i]; j <= sim_days; j += party_index[i]) {
                bitmap[j] = true;
            }
        }

        // count
        for (int i = 1; i <= sim_days; i++) {
            if (i % 7 == 6 || i % 7 == 0)
                continue;
            
            if (bitmap[i]) count++;

        }

        cout << count << endl;
    }
    return 0;
}

