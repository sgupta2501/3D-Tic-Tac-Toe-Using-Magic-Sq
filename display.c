#include <stdio.h>
#include <stdlib.h>



int search(int list[], int ele){
	int i,flag=0;
	 
	
	for(i=0;list[i]!=0;i++){
	    
		if(list[i]==ele){
			return 1;
		}
	}
	return 0;
}

void display_tictactoe(int mcube[3][3][3], int p1moves[], int p2moves[]){
	int i,j,k;
	int n=3;
	int p1[21],p2[21];
	
	
	
	for(i=0;i<21;i++){	
	    p1[i]=p1moves[i];
	    p2[i]=p2moves[i];
	    
    }
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(search(p1,mcube[i][j][k])==1){
					printf("X\t");
					
				}
				else if(search(p2,mcube[i][j][k])==1){
					printf("O\t");
				}
				else
				    printf(".\t");
			}
			printf("\n");		
		}
		printf("\n");
	}
		
}
