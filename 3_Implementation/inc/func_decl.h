#ifndef _FUNC_DECL_H_
#define _FUNC_DECL_H_

int login();
void display();
struct vehicle* add(int, int, int, int);
void get_rowcol_by_number(int, int, int *);
void get_free_rowcol(int, int *);
void flushinp();
int valid_vehicle_type(int);

#endif
