#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int cmp(const void *a, const void *b) {
    return (*(char *)a) - (*(char *)b);
}

int main() {
    int R;
    char Col[MAX_LENGTH + 1];
    
    while (1) {
        scanf("%d", &R);
        if (R == 0) {
            break;
        }

        scanf("%s", Col);
        
        int length = strlen(Col);
        char last_col[MAX_LENGTH + 1];
        char first_col[MAX_LENGTH + 1];
        int map[MAX_LENGTH];
        
        strcpy(last_col, Col);
        strcpy(first_col, Col);
        
        qsort(first_col, length, sizeof(char), cmp);
        
        char last_col_copy[MAX_LENGTH + 1];
        strcpy(last_col_copy, last_col);
        for (int j = 0; j < length; j++) {
            map[j] = -1;
            for (int k = 0; k < length; k++) {
                if (last_col_copy[k] == first_col[j]) {
                    map[j] = k;
                    last_col_copy[k] = '\0';
                    break;
                }
            }
        }
        
        char grid[MAX_LENGTH][MAX_LENGTH];
        for (int j = 0; j < length; j++) {
            grid[0][j] = first_col[j];
        }
        for (int j = 0; j < length; j++) {
            grid[length - 1][j] = last_col[j];
        }
        
        for (int j = 1; j < length - 1; j++) {
            for (int jj = 0; jj < length; jj++) {
                grid[j][jj] = grid[j - 1][map[jj]];
            }
        }
        
        for (int j = 0; j < length; j++) {
            printf("%c", grid[j][R - 1]);
        }
        printf("\n");
    }

    return 0;
}
