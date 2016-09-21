#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>

#define FLUSH while(getchar() != '\n');

using namespace std;

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    char c;
    bool flag = false;

    while (scanf("%c", &c) != EOF) {
        if (c == '"') {
            if (!flag)
                printf("``");
            else
                printf("''");

            flag = !flag;
        }
        else
            printf("%c", c);
    }
    return 0;
}
