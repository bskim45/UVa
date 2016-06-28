#include <stdio.h>
#include <string.h>
#include <iostream>

#define FLUSH while(getchar() != '\n');

char unsorted[200][100];
char sorted[200][100];

int main(void) {
    std::ios_base::sync_with_stdio(false);

    int case_num, lines;
    scanf("%d", &case_num);

    FLUSH

    for (int case_idx = 0; case_idx < case_num; case_idx++) {
        scanf("%d", &lines);

        // io fix
        FLUSH

        memset(unsorted, 0, sizeof unsorted);
        memset(unsorted, 0, sizeof sorted);

        // parse lines
        for (int i = lines - 1; i >= 0; i--) {
            gets(unsorted[i]);
        }

        for (int i = lines - 1; i >= 0; i--) {
            gets(sorted[i]);
        }

        // compare
        int moves = 0;

        for (int i = 0, j = 0; i < lines && j < lines; i++) {
            if (strcmp(unsorted[i], sorted[j]) != 0) {
                moves++;
            }
            else {
                j++;
            }
        }

        for (int i = lines - moves; i < lines; i++) {
            printf("%s\n", sorted[i]);
        }

        printf("\n");

    }

    return 0;
}
