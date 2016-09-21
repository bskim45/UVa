#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>

#define FLUSH while(getchar() != '\n');

using namespace std;

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    char str[50];

    while (true) {
        memset(str, '\0', sizeof str);

        scanf("%s", str);

        if (str[0] == '#')
            break;
        
        if (next_permutation(str, str + strlen(str))) {
            printf("%s\n", str);
        }
        else {
            printf("No Successor\n");
        }

    }
    return 0;
}
