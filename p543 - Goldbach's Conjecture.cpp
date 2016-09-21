#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>

#define FLUSH while(getchar() != '\n');

using namespace std;

#define MAX 1000000
bool primes[MAX + 1];
vector<int> defined;

void generate() {
    memset(primes, true, sizeof primes);

    primes[0] = primes[1] = false;
    primes[2] = true;
    defined.push_back(2);

    for (int i = 2; i <= MAX / 2;) {
        int num = i;
        while (num + i <= MAX) {
            num += i;
            primes[num] = false;
        }
        
        i++;

        while (!primes[i] && i <= MAX / 2) {
            i++;
        }
        
        if(i <= MAX / 2)
            defined.push_back(i);
    }
}

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    generate();
    int num = 0;
    while (true) {
        scanf("%d", &num);
        
        if (num == 0)
            break;

        for (int i = 0; defined[i] <= MAX / 2; i++) {
            if (primes[num - defined[i]]) {
                printf("%d = %d + %d\n", num, defined[i], num - defined[i]);
                break;
            }
        }
    }
    return 0;
}
