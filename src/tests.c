#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char a[8];
} asd;

int main(void)
{
    char a[] = {"asd"};
    char b[] = a;
    puts(b);
    return 0;
}
