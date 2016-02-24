#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define eps 1e-7

using namespace std;

pair<double, double> peak_pair(const double w, const double l) {
    double root = sqrt(w * w + l * l - w * l);
    return make_pair(((w + l) - root) / 6.0, ((w + l) + root) / 6.0);
}

int main() {
    ios::sync_with_stdio(false);

    string buf;

    while (getline(cin, buf)) {
        stringstream ss(buf);

        double l = 0, w = 0;

        ss >> l >> w;

        auto peaks = peak_pair(w, l);

        double limit = min(w / 2, l / 2);

        double min_x = limit < peaks.second ? limit : peaks.second;


        cout << setprecision(3) << fixed
            << peaks.first << " " << 0.000 << " " << min_x + eps << endl;
    }

    return 0;
}
