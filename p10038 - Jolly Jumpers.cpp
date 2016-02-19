#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>      
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, const char* argv[]) {

    ios::sync_with_stdio(false);
    string buf;
    while (getline(cin, buf)) {
        vector<int> nums;
        stringstream ss(buf);
        int size, input;

        // seqence size
        ss >> size;

        // get numbers
        while (ss >> input)
            nums.push_back(input);

        // create bitmap
        vector<bool> bitmap;
        bitmap.resize(size, false);
        bitmap[0] = true;

        // fill bitmap
        for (int i = 0; i < size - 1; i++) {
            int diff = abs(nums[i] - nums[i + 1]);

            if(diff <= size - 1)
                bitmap[diff] = true;
        }

        // check bitmap
        string result = find(bitmap.begin(), bitmap.end(), false)
            == bitmap.end() ? "Jolly" : "Not jolly";

        cout << result << endl;
    }
    return 0;
}

