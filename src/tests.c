#include <stdio.h>
#include <string.h>

typedef struct {
    int n;
    int v[];
} asd;
int main(void)
{
    asd a = {1, (int[]) {1,2,3}};
    printf("sizeof: %d\n", sizeof(a));
    
    return 0;
}
