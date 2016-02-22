#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int num;
    while(cin >> num) {
        if(num == 0) {
            break;
        }

        vector<double> expenses;

        double input, sum  = 0;
        for(int i = 0; i < num; i++) {
            cin >> input;
            expenses.push_back(input);
            sum += input;
        }

        double average = sum / num;
        double diff_pos = 0, diff_neg = 0;

        for(auto iter = expenses.begin(); iter != expenses.end(); ++iter) {
            double diff = (double)(int)((*iter - average) * 100.0) / 100.0;  // cent precision fix
            if (diff > 0)
                diff_pos += diff;
            else
                diff_neg -= diff;
        }

        cout << setprecision(2) << fixed << "$" << max(diff_pos, diff_neg) << endl;

    }
}