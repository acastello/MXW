#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "actions.h"

BOOL CALLBACK _getwins_callback(HWND, LPARAM);

struct pthread_sendwin_t {
    HWND hwnd;
    vk_t *vk;
};
void *pthread_sendwin_f(void *param)
{
    char mask, vk;
    struct pthread_sendwin_t v = *( (struct pthread_sendwin_t *) param );
    int i;
    for (i=0; i<MAXVKS; i++) {
        // printf("[pthreading]\t hwnd: %d, key: %d\n", v.hwnd, v.vk[i].vk);
        mask = v.vk[i].mask;
        vk = v.vk[i].vk;

        if (mask & VK_T_DOWN)
            SendMessage(v.hwnd, WM_KEYDOWN, vk, 0);

        if (mask & VK_T_CHAR)
            SendMessage(v.hwnd, WM_CHAR, vk, 0);

        if (mask & VK_T_UP)
            SendMessage(v.hwnd, WM_KEYUP, vk, 0); 
    }
    return NULL;
}

void sendwin(sendwin_t *params)
{
    HWND *h = params->handles;

    if (params->n == 1) {
        pthread_sendwin_f((struct pthread_sendwin_t []) {*h, (vk_t *) &params->vk});
        return;
    }

    pthread_t pthreads[MAXHWNDS];
    int i,j;
    for (i=0; *h && i<params->n; i++, h++) {
        // printf("[loop]\t\t HWND: 0x%x\n", *h);
        if (pthread_create(
                    &pthreads[i], 
                    NULL,
                    pthread_sendwin_f, 
                    (struct pthread_sendwin_t []) {*h, (vk_t *) &params->vk} ))
            fprintf(stderr, "asd\n");
    }
    for (j=0; j<i; j++) {
        // printf("j: %d, p: %p\n", j, pthreads[j]);
        pthread_join(pthreads[j],NULL);
    }
}

void getwins(getwins_t *ret)
{
    EnumWindows(_getwins_callback, (size_t) ret); 
}

BOOL CALLBACK _getwins_callback(HWND hwnd, LPARAM lparam)
{
    static char buff[32];

    getwins_t *ret = (getwins_t *) lparam;

    if (ret->n == MAXHWNDS)
        return FALSE; 
    
    GetClassName(hwnd, buff, 32);
    if (!strncmp(buff, "GxWindowClass", sizeof("GxWindowClass")-1)) {
        // printf("[getwins][%d][h: 0x%x] Class: %s\n", ret->n, hwnd, buff);
        ret->handles[ret->n++] = hwnd;
    }

    return TRUE;
}

int main(void)
{
    getwins_t wins;
    getwins(&wins);
    printf("n wins: %d\n", wins.n);
    printf("sizeof %d\n", sizeof(sendwin_t));
    char c = 'K';
    sendwin_t s = {
        .n = wins.n,
        .vk = {{7, 'M'}}
        // .vk = {{VK_T_DOWN, 'M'},{VK_T_UP, 'M'},{VK_T_DOWN, 'M'},{VK_T_UP, 'M'},{VK_T_DOWN, 'M'},{VK_T_UP, 'M'},{VK_T_DOWN, 'M'},{VK_T_UP, 'M'}}
    };
    memcpy(&s.handles, wins.handles, sizeof(s.handles));

    sendwin(&s);
    sendwin(&s);
    sendwin(&s);
    sendwin(&s);
    sendwin(&s);

    // printf("sizeof: %d\n", sizeof(sendwin_t));
    // printf("class: %s\n", b);
    // printf("hwnd: %d\n", st.handles[0]);
    return 0;
}
