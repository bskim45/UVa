#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>
#include <cmath>

#define FLUSH while(getchar() != '\n');

using namespace std;

int main(int argc, const char* argv[]){
    ios::sync_with_stdio(false);

    int num;
    scanf("%d", &num);
    for(int cases = 1; num >= 0; cases++)
    {
        printf("Case %d: %d\n", cases, static_cast<int>(ceil(log2(num))));
        scanf("%d", &num);
    }

    return 0;
}
