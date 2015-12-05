#include<stdio.h>
#include<string.h>

/* Magic Squares - Knuth 1.3.2 ex. 21. */

int main(void)
{
    int n, n2, i, i2, j, k, p;
    char temp[10], pad[10];

    printf("*** Magic Squares ***\n\nn: ");
    scanf("%d", &n);
    if (!(n % 2)){
        printf("N must be odd.\n");
        return 1;
    }
    n2 = n * n;

    /* Create a format string for neat output. */
    sprintf(temp, "%d", n2);
    sprintf(pad, "%%c%%0%dd", strlen(temp));

    k = n + 1;
    printf("Sum should be %d.\n", (n * (n2 + 1)) / 2);
    
    int sq[n2];
    for(i = 0; i < n2; i++){
        sq[i] = 0;
    }

    i = n2 / 2 - 1;
    
    for(j = 1; j < (n2 + 1); j++){
            i2 = !((i + 1) % n) ? (i + 1) % n2 : (i + k) % n2;
            if (sq[i2])
                i2 = (i + n * 2) % n2;
            sq[i2] = j;
            i = i2;
    }

    for(i = 0; i < n2; i++){
        printf(pad, i % n ? ' ' : '\n', sq[i]);
        } 
    printf("\n");
    return 0;
}
