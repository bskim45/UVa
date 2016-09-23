#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>

#define FLUSH while(getchar() != '\n');

using namespace std;

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    int cases, walls;

    scanf("%d", &cases);
    for (int t = 1; t <= cases; t++) {
        scanf("%d", &walls);

        int higher = 0, lower = 0, prev = 0, cur = 0;
        scanf("%d", &prev);
        for (int i = 1; i < walls; i++) {
            scanf("%d", &cur);
            if (cur > prev) higher++;
            if (cur < prev) lower++;
            prev = cur;
        }

        printf("Case %d: %d %d\n", t, higher, lower);
    }
    return 0;
}
