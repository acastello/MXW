#ifndef _ACTIONS_H
#define _ACTIONS_H

#include <windows.h>

#define MAXHWNDS 32
#define MAXVKS 8

typedef enum {
    sendwin_e,
    getwins_e,
} action_e;

#define VK_T_DOWN 1
#define VK_T_UP 2
typedef struct {
    char flags;
    char vk;
} vk_t;

typedef struct {
    size_t n;
    HWND handles[MAXHWNDS];
    vk_t vk[MAXVKS]; 
} sendwin_t;

typedef struct {
    size_t n;
    HWND handles[MAXHWNDS];
} getwins_t;

extern void sendwin(sendwin_t *);
extern void getwins(getwins_t *);

#endif
