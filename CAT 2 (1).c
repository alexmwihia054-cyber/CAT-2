//program to show arrays
/*
Name:Alex Mwangi
Reg No:CT100/G/26203/25
DESCRIPTION:program to display scores
*/
#include <stdio.h>

int main() {
    int scores[2][4] = {
        {65, 92, 35, 70},
        {84, 72, 59, 67}
    };
    int i, j;

    printf("Elements of the scores array:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
    return 0;
}