#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define P1 -1
#define AI -2
#define P1SYM 'X'
#define AISYM 'O'
#define true 0
#define false 1
struct options{
	int arr[50];
	int index;
};
void display_moves(int a[],int);
void empty_spaces(int a[][50][50],int*,int*,int);
void pos_choice(int a[][50][50],struct options*,struct options*,struct options*);
int check_if_present(int [],int,int);
void print_cube(int c[][50][50],int);
void print_board(int c[][50][50],int mcube[][50][50],int);
void copy_cube(int other[][50][50],int main[][50][50],int);
int put_val(int d[][50][50],int,int,int);
void find_pos(int d[][50][50],int *,int *,int *,int,int);
int check_sum(int,int,int);
int check_collinear(int mcube[][50][50],int,int,int);
// void is_collinar(int mcube[][50][50],int [],int [],int,int);
void magic_cube_gen(int mcube[][50][50],int);
int modulas_sub(int,int);
int point_to_add(int mcube[][50][50],int temp[][50][50],int [],int);
int check_lines(int mcube[][50][50],int []);