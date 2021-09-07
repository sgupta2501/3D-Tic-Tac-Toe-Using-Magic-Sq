#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void empty_spaces(int a[][3][3],int *arr,int *l,int n){
	int len=0;
	memset(arr,0,(*l)*sizeof(*a));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(a[i][j][k]!=AI && a[i][j][k]!=P1){
					arr[len]=a[i][j][k];
					len+=1;
				}
			}
		}
	}
	*l=len;
}
void pos_choice(int a[][3][3],struct options *temp1,struct options *temp2,struct options *temp3){

	for(int i=0;i<3;i++){
		if(a[i][0][0]!=AI && a[i][0][0]!=P1){
			temp1->arr[temp1->index]=a[i][0][0];
			temp1->index+=1;
		}
		if(a[i][0][2]!=AI && a[i][0][2]!=P1){
			temp1->arr[temp1->index]=a[i][0][2];
			temp1->index+=1;
		}
		if(a[i][2][0]!=AI && a[i][2][0]!=P1){
			temp1->arr[temp1->index]=a[i][2][0];
			temp1->index+=1;
		}
		if(a[i][2][2]!=AI && a[i][2][2]!=P1){
			temp1->arr[temp1->index]=a[i][2][2];
			temp1->index+=1;
		}
	}
	for(int i=0;i<3;i++){
		if(a[i][1][1]!=AI && a[i][1][1]!=P1){
			temp2->arr[temp2->index]=a[i][1][1];
			temp2->index+=1;
		}
	}
	for(int i=0;i<3;i++){
		if(a[i][0][1]!=AI && a[i][0][1]!=P1){
			temp3->arr[temp3->index]=a[i][0][1];
			temp3->index+=1;
		}
		if(a[i][1][0]!=AI && a[i][1][0]!=P1){
			temp3->arr[temp3->index]=a[i][1][0];
			temp3->index+=1;
		}
		if(a[i][2][1]!=AI && a[i][2][1]!=P1){
			temp3->arr[temp3->index]=a[i][2][1];
			temp3->index+=1;
		}
		if(a[i][1][2]!=AI && a[i][1][2]!=P1){
			temp3->arr[temp3->index]=a[i][1][2];
			temp3->index+=1;
		}
	}
}
int main(int argc, char const *argv[])
{
	int a[3][3][3]={{{1,2,P1},{3,100,P1},{4,5,P1}},
				    {{6,7,P1},{8,100,P1},{9,10,P1}},
				    {{11,12,P1},{13,100,P1},{14,15,P1}}};
	struct options first_preference;
	struct options second_preference;
	struct options third_preference;
	first_preference.index=0;
	second_preference.index=0;
	third_preference.index=0;
	pos_choice(a,&first_preference,&second_preference,&third_preference);

	// int first_preference[50]={};
	// int second_preference[50]={};
	// int third_preference[50]={};
	// int findex=0;
	// int sindex=0;
	// int tindex=0;
	// for(int i=0;i<3;i++){
	// 	if(a[i][0][0]!=AI && a[i][0][0]!=P1){
	// 		second_preference.arr[second_preference.index]=a[i][0][0];
	// 		second_preference.index+=1;
	// 	}
	// 	if(a[i][0][2]!=AI && a[i][0][2]!=P1){
	// 		second_preference.arr[second_preference.index]=a[i][0][2];
	// 		second_preference.index+=1;
	// 	}
	// 	if(a[i][2][0]!=AI && a[i][2][0]!=P1){
	// 		second_preference.arr[second_preference.index]=a[i][2][0];
	// 		second_preference.index+=1;
	// 	}
	// 	if(a[i][2][2]!=AI && a[i][2][2]!=P1){
	// 		second_preference.arr[second_preference.index]=a[i][2][2];
	// 		second_preference.index+=1;
	// 	}
	// }
	// for(int i=0;i<3;i++){
	// 	if(a[i][1][1]!=AI && a[i][1][1]!=P1){
	// 		first_preference.arr[first_preference.index]=a[i][1][1];
	// 		first_preference.index+=1;
	// 	}
	// }
	// for(int i=0;i<3;i++){
	// 	if(a[i][0][1]!=AI && a[i][0][1]!=P1){
	// 		third_preference.arr[third_preference.index]=a[i][0][1];
	// 		third_preference.index+=1;
	// 	}
	// 	if(a[i][1][0]!=AI && a[i][1][0]!=P1){
	// 		third_preference.arr[third_preference.index]=a[i][1][0];
	// 		third_preference.index+=1;
	// 	}
	// 	if(a[i][2][1]!=AI && a[i][2][1]!=P1){
	// 		third_preference.arr[third_preference.index]=a[i][2][1];
	// 		third_preference.index+=1;
	// 	}
	// 	if(a[i][1][2]!=AI && a[i][1][2]!=P1){
	// 		third_preference.arr[third_preference.index]=a[i][1][2];
	// 		third_preference.index+=1;
	// 	}
	// }
	printf("second:\n");
	for(int i=0;i<second_preference.index;i++){
		printf("%d,",second_preference.arr[i]);
	}
	printf("first:\n");
	for(int i=0;i<first_preference.index;i++){
		printf("%d,",first_preference.arr[i]);
	}
	printf("third:\n");
	for(int i=0;i<third_preference.index;i++){
		printf("%d,",third_preference.arr[i]);
	}

	return 0;
}