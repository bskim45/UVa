#include <iostream>
#include <functional>
#include <algorithm>

#define FLUSH while(getchar() != '\n');

using namespace std;

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    int well = 0;
    int climb = 0;
    int slide = 0;
    int fatigue = 100;

    while (true) {
        scanf("%d %d %d %d", &well, &climb, &slide, &fatigue);

        if (well == 0) {
            break;
        }
        
        double actual_climb = climb;
        double height = 0;

        for(int day = 1; ; ++day) {
            // day
            height += actual_climb;

            if (height > well) {
                printf("success on day %d\n", day);
                break;
            }

            // night
            height -= slide;

            if(height < 0) {
                printf("failure on day %d\n", day);
                break;
            }

            actual_climb = max(actual_climb - climb * (fatigue / 100.0), 0.0);
        }
    }

    return 0;
}
