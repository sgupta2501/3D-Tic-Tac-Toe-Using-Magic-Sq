#include "assignment1.h"
int main(int argc, char *argv[]) 
{	
	int n;
	printf("Enter the length of one side of the magic cube\n");
	scanf("%d",&n);   //taking the size as input
	int mcube[50][50][50];
	magic_cube_gen(mcube,n);
	int temp[50][50][50];
	copy_cube(temp,mcube,n);
	int mconst=(n*((n*n*n)+1))/2;
	int a,b,c;
	int p1[14],ai[13];
	int pindex=0,aindex=0;
	int turn=P1;
	int first=0;
	printf("%d\n",check_collinear(mcube,20,18,4));
	// while(((pindex+aindex)!=27)){
	// 	turn=P1;
	// 	int pos;
	// 	print_board(temp,n);
	// 	printf("enter positon\n");
	// 	scanf("%d",&pos);
	// 	if(put_val(temp,n,turn,pos)==0){
	// 		printf("success\n");

	// 	}
	// 	else{
	// 		printf("value filled\n");
	// 	}
	// 	turn=AI;
	// 	p1[pindex]=pos;
	// 	pindex+=1;
	// 	if(((pindex+aindex)<2) && (first==0)){
	// 		first=1;
	// 		if(pos==14){
	// 			if(put_val(temp,n,turn,mcube[0][0][0])==true){
	// 				printf("AI played at position %d\n",mcube[0][0][0]);
	// 			}
	// 			else{
	// 				printf("something went wrong\n");
	// 			}
	// 		}
	// 		else{
	// 			int p=n/2;
	// 			if(put_val(temp,n,turn,mcube[p][p][p])==true){
	// 				printf("AI played at position %d\n",mcube[p][p][p]);
	// 				ai[aindex]=mcube[p][p][p];
	// 				aindex+=1;
	// 			}
	// 			else{
	// 				printf("something went wrong\n");
	// 			}
	// 		}
	// 	}
	// 	else{
	// 		//check for ai win case first
	// 		int t1=p1[pindex];
	// 		int t2=p1[pindex-1];
	// 		int t3=42-(t1+t2);
	// 		if(check_collinear(mcube,t1,t2,t3)==true){
	// 			if(put_val(temp,n,AI,t3)){
	// 				printf("AI played at %d\n",t3);
	// 				ai[aindex]=t3;
	// 				aindex+=1;
	// 			}
	// 			else{
	// 				printf("already blocked\n");
	// 			}	
	// 		}
	// 		else{
	// 			printf("not collinear\n");
	// 		}
	// 	}
		
	// }
	return 0;
}