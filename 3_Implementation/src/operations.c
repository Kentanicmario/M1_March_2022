#include "header.h"
#include "func_decl.h"

extern struct vehicle *parkinfo[10][10];
extern int vehicle_count;
extern int fourwheeler_count;
extern int twowheeler_count;

void flushinp() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

struct vehicle* add(int t, int number, int row, int col)
{
    struct vehicle * v;
    v = (struct vehicle *) malloc(sizeof(struct vehicle));
    v->type = t;
    v->row = row;
    v->col = col;
    v->num = number;
    if (t == FOUR_WHEELER) fourwheeler_count++;
    else twowheeler_count++;
    vehicle_count++;
    return v;
}

int login(char *uname, char *pword)
{
    char stepin[10] = "stepin";
    char password[10] = "password";

    return (strcmp(uname, stepin) == 0) && (strcmp(pword, password) == 0);
}

void get_free_rowcol(int type, int *arr)
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
            if (!parkinfo[r][c])
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


void display()
{
    int r, c;
    printf("Four Wheeler =>\n");
    for (r = 0; r < 10; r++)
    {
        if (r == 5) printf("Two Wheeler =>\n");
        for (c = 0; c < 10; c++) {
            struct vehicle *v = parkinfo[r][c];
            if (v)
                printf("%d\t", v->num);
            else
                printf("0\t");
        }
        printf("\n");
    }
}

