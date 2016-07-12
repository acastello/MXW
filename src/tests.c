#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char a[8];
} asd;

int main(void)
{
    printf("%d\n", 1 & 0 | 1 );
    return 0;
}
