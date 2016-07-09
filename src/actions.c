#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "actions.h"


struct pthread_sendwin_t {
    HWND hwnd;
    int vk;
};
void *pthread_sendwin_f(void *param)
{
    struct pthread_sendwin_t v = *( (struct pthread_sendwin_t *) param );
    printf("[pthreading]\t hwnd: %d, key: %d\n", v.hwnd, v.vk);
    if (PostMessage(v.hwnd, WM_KEYDOWN, v.vk, 0))
        printf("[pthreading]\t returning\n");
    else 
        fprintf(stderr, "[pthreading]\t failed.\n");
    sleep(1);
    return NULL;
}

void sendwin_f(sendwin_t *params)
{
    HWND *h = params->handles;
    pthread_t pthreads[MAXHWNDS];
    int i,j;
    for (i=0; *h && i<MAXHWNDS; i++, h++) {
        printf("[loop]\t\t HWND: 0x%x\n", *h);
        if (pthread_create(
                    &pthreads[i], 
                    NULL,
                    pthread_sendwin_f, 
                    (struct pthread_sendwin_t []) {*h, params->vk} ))
            fprintf(stderr, "asd\n");
    }
    for (j=0; j<i; j++) {
        printf("j: %d, p: %p\n", j, pthreads[j]);
        fflush(stdout);
        pthread_join(pthreads[j],NULL);
    }
}

void getwins(HWND *handles, size_t sz)
{

}

int main(void)
{
    char b[512];
    HWND hwnd = FindWindow(NULL, "World of Warcraft");
    GetClassName(hwnd,b,512);
    sendwin_t st = {
        .handles = {hwnd, 0},
        .vk = 0x30
    }; 
    sendwin_f(&st);
    // printf("sizeof: %d\n", sizeof(sendwin_t));
    // printf("class: %s\n", b);
    // printf("hwnd: %d\n", st.handles[0]);
    return 0;
}
