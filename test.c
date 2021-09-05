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
	while(((pindex+aindex)!=27)){
		turn=P1;
		int pos;
		print_board(temp,n);
		printf("enter positon\n");
		scanf("%d",&pos);
		if(put_val(temp,n,turn,pos)==0){
			printf("success\n");

		}
		else{
			printf("value filled\n");
		}
		turn=AI;
		p1[pindex]=pos;
		pindex+=1;
		if(((pindex+aindex)<2) && (first==0)){
			first=1;
			if(pos==14){
				if(put_val(temp,n,turn,20)==0){
					printf("AI played at position 20\n");
				}
				else{
					printf("something went wrong\n");
				}
			}
			else{
				if(put_val(temp,n,turn,14)==0){
					printf("AI played at position 14\n");
				}
				else{
					printf("something went wrong\n");
				}
			}
		}
		// else{
		// }
		// if()
	}
	return 0;
}