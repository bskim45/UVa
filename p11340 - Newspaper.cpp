#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cstring>

#define FLUSH() while(getchar() != '\n');

using namespace std;

constexpr int BUFFER_SIZE = 10000;
constexpr int CHAR_OFFSET = 128;
char buffer[10000];
int word_map[256];

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    int cases = 0;
    scanf("%d", &cases);

    for (int case_num = 1; case_num <= cases; ++case_num) {
        int word_num = 0;
        int lines = 0;
        double value = 0.0;

        scanf("%d", &word_num);

        memset(word_map, 0, sizeof(word_map));

        char ch;
        int price = 0;
        for (int i = 0; i < word_num; ++i) {
            FLUSH()
            scanf("%c %d", &ch, &price);
            word_map[ch + CHAR_OFFSET] = price;
        }

        scanf("%d", &lines);

        FLUSH()
        for (int i = 0; i < lines; ++i) {
            gets(buffer);

            for (int j = 0; buffer[j] != NULL && j < BUFFER_SIZE; ++j) {
                value += word_map[buffer[j] + CHAR_OFFSET] / 100.0;
            }
        }

        printf("%.2f$\n", value);
    }

    return 0;
}
