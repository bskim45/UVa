#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>

#define FLUSH while(getchar() != '\n');

using namespace std;
int num[1001];

int sort(int nums) {
    int flip = 0;

    for (int i = 1; i < nums; i++) {
        for (int j = i + 1; j <= nums; j++) {
            if (num[i] > num[j]) flip++;
        }
    }

    return flip;
}

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    int nums = 0;
    while (scanf("%d", &nums) != EOF) {
        for (int i = 1; i <= nums; i++) {
            scanf("%d", &num[i]);
        }

        printf("Minimum exchange operations : %d\n", sort(nums));
    }
    return 0;
}
