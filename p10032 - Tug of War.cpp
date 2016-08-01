#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>

#define FLUSH while(getchar() != '\n');

using namespace std;

int people[101];
long long weight[450 * 100 / 2 + 450];

int main(void) {
    ios::sync_with_stdio(false);

    int case_num, lines, sum;
    scanf("%d", &case_num);

    for (int case_idx = 0; case_idx < case_num; case_idx++) {

        memset(people, 0, sizeof people);
        memset(weight, 0, sizeof weight);

        scanf("%d", &lines);

        sum = 0;

        // parse lines
        for (int i = 1; i <= lines; i++) {
            scanf("%d", &people[i]);
            sum += people[i];
        }
        
        int half = lines / 2;
        int upper = 450 * lines / 2 + 450;
        bool isEven = lines % 2 == 0;
        int half_sum = sum / 2;

        weight[0] = 1LL << 0;
        int seek = 0;

        for (int i = 1; i <= lines; i++) {
            int w = people[i];
            
            seek = min(seek + w, upper);

            for (int j = seek; j >= w; j--) {
                if(weight[j - w])
                    weight[j] |= weight[j - w] << 1;

                // found solution, stop update
                if(j == half_sum && (weight[j] & (1LL << half) || !isEven && weight[j] & (1LL << half + 1))) {
                    break;
                }
            }
        }

        int one_side = 0;
        for (int i = half_sum, j = half_sum; i > 0 && j < upper; i--, j++) {
            if ((weight[i] & (1LL << half)) || !isEven && (weight[i] & 1LL << half + 1)) {
                one_side = i;
                break;
            }

            if ((weight[j] & (1LL << half)) || !isEven && (weight[j] & 1LL << half + 1)) {
                one_side = j;
                break;
            }
        }

        printf("%d %d\n", min(one_side, sum - one_side), max(one_side, sum - one_side));

        if (case_idx < case_num - 1) printf("\n");
    }

    return 0;
}
