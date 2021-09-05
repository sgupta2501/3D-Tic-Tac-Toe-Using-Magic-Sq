#include <stdio.h>
#include <stdlib.h>
#define P1 -1
#define AI -2
#define P1SYM 'X'
#define AISYM 'O'
void print_cube(int c[][50][50],int);
void print_board(int c[][50][50],int);
void copy_cube(int other[][50][50],int main[][50][50],int);
int put_val(int d[][50][50],int,int,int);
void find_pos(int d[][50][50],int *,int *,int *,int,int);
void magic_cube_gen(int mcube[][50][50],int);