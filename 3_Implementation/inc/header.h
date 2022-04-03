#ifndef _HEADER_H_
#define _HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FREE 0
#define FOUR_WHEELER 1
#define TWO_WHEELER 2

static const char *TYPE[] = {"FREE", "FOUR_WHEELER", "TWO_WHEELER"};

struct vehicle
{
    int num;
    int row;
    int col;
    int type;
};

#endif
