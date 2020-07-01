#include "malloc.h"
#include <stdio.h>

int main()
{
    int f = 10;
    char*bjr = Mmalloc(sizeof(char) * f);

    for (int i = 0 ; i<f-1 ; i++){
        bjr[i] = 'e';
        printf("%d\n", i);
    }
    bjr[f - 1] = 0;
    printf("%s\n", bjr);
    printf("free\n");
    Mfree(bjr);
    printf("malloc\n");
    bjr = Mmalloc(sizeof(char) * f);
    for (int i = 0 ; i<f-1 ; i++){
        bjr[i] = 'w';
        printf("%d\n", i);
    }
    bjr[f - 1] = 0;
    printf("%s\n", bjr);
}
