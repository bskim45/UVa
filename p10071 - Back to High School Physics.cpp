#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>

#define FLUSH while(getchar() != '\n');

using namespace std;

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);
    
    int start, end;
    while (scanf("%d %d", &start, &end) == 2) {
        printf("%d\n", 2 * start * end);
    }
    return 0;
}
