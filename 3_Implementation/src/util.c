#include <header.h>

struct vehicle *parkinfo[10][10] = {0};
int vehicle_count = 0;
int fourwheeler_count = 0;
int twowheeler_count = 0;


int valid_vehicle_type(int type)
{
    return type == TWO_WHEELER || type == FOUR_WHEELER;
}

void get_rowcol_by_number(int type, int num, int *arr)
{
    int r, c, fr = 0, tr = 5;
    if (type == TWO_WHEELER)
    {
        fr += 5;
        tr += 5;
    }
    for (r = fr; r < tr; r++)
    {
        for (c = 0; c < 10; c++)
        {
            if (parkinfo[r][c] && parkinfo[r][c]->num == num)
            {
                arr[0] = r;
                arr[1] = c;
                return;
            }
        }
    }
    arr[0] = -1;
    arr[1] = -1;
}

