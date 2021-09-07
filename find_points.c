#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define P1 -1
#define AI -2
#define P1SYM 'X'
#define AISYM 'O'
#define true 0
#define false 1
void empty_spaces(int a[][3][3],int *b,int *l,int n){
	int len=0;
	memset(b,0,(*l)*sizeof(*a));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(a[i][j][k]!=AI && a[i][j][k]!=P1){
					b[len]=a[i][j][k];
					len+=1;
				}
			}
		}
	}
	*l=len;
}
int main(int argc, char const *argv[])
{
	int a[3][3][3]={{{1,2,P1},{3,100,P1},{4,5,P1}},
				    {{6,7,P1},{8,100,P1},{9,10,P1}},
				    {{11,12,P1},{13,100,P1},{14,15,P1}}};
    int b[27];
    int len=0;
    empty_spaces(a,b,&len,3);
    printf("%d\n",len);
    for(int i=0;i<len;i++){
    	printf("%d,",b[i]);
    }
	// int first_preference[50]={};
	// int second_preference[50]={};
	// int third_preference[50]={};
	// int findex=0;
	// int sindex=0;
	// int tindex=0;
	// for(int i=0;i<3;i++){
	// 	if(a[i][0][0]!=AI && a[i][0][0]!=P1){
	// 		second_preference[sindex]=a[i][0][0];
	// 		sindex+=1;
	// 	}
	// 	if(a[i][0][2]!=AI && a[i][0][2]!=P1){
	// 		second_preference[sindex]=a[i][0][2];
	// 		sindex+=1;
	// 	}
	// 	if(a[i][2][0]!=AI && a[i][2][0]!=P1){
	// 		second_preference[sindex]=a[i][2][0];
	// 		sindex+=1;
	// 	}
	// 	if(a[i][2][2]!=AI && a[i][2][2]!=P1){
	// 		second_preference[sindex]=a[i][2][2];
	// 		sindex+=1;
	// 	}
	// }
	// for(int i=0;i<3;i++){
	// 	if(a[i][1][1]!=AI && a[i][1][1]!=P1){
	// 		first_preference[findex]=a[i][1][1];
	// 		printf("%d\n",a[i][1][1] );
	// 		findex+=1;
	// 	}
	// }
	// for(int i=0;i<3;i++){
	// 	if(a[i][0][1]!=AI && a[i][0][1]!=P1){
	// 		third_preference[tindex]=a[i][0][1];
	// 		tindex+=1;
	// 	}
	// 	if(a[i][1][0]!=AI && a[i][1][0]!=P1){
	// 		third_preference[tindex]=a[i][1][0];
	// 		tindex+=1;
	// 	}
	// 	if(a[i][2][1]!=AI && a[i][2][1]!=P1){
	// 		third_preference[tindex]=a[i][2][1];
	// 		tindex+=1;
	// 	}
	// 	if(a[i][1][2]!=AI && a[i][1][2]!=P1){
	// 		third_preference[tindex]=a[i][1][2];
	// 		tindex+=1;
	// 	}
	// }
	// printf("f:%d\n",findex);
	// printf("second:\n");
	// for(int i=0;i<sindex;i++){
	// 	printf("%d,",second_preference[i]);
	// }
	// printf("first:\n");
	// for(int i=0;i<findex;i++){
	// 	printf("%d,",first_preference[i]);
	// }
	// printf("third:\n");
	// for(int i=0;i<tindex;i++){
	// 	printf("%d,",third_preference[i]);
	// }

	return 0;
}