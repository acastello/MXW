#ifndef _ACTIONS_H
#define _ACTIONS_H

#include <windows.h>

#define MAXHWNDS 32

typedef enum {
    sendwin_e,
    getwins_e,
} action_e;

typedef struct {
    HWND handles[MAXHWNDS];
    int vk; 
} sendwin_t;

typedef struct {
    size_t n;
    HWND handles[MAXHWNDS];
} getwins_t;

#endif
