#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <windows.h>
#include <X11/Xutil.h>

typedef struct {
    char a[8];
} asd;

int main(void)
{
    unsigned int vk = VK_OEM_6;
    printf("vk: %d, char: %c\n", vk, MapVirtualKey(vk, MAPVK_VK_TO_CHAR));

    return 0;
}
