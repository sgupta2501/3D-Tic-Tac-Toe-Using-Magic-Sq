

#include <stdio.h>
#include <stdlib.h>
#include "AI Assignment 1 Display.c"
#include "AI Assignment 1 Check.c"




/*int search(int list[], int ele){
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
		
}*/






/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int n=3;
	int p1moves[21];
	int p2moves[21];
	int p1_score, p2_score;
	/*printf("Enter the length of one side of the magic cube\n");
	scanf("%d",&n);*/   //taking the size as input
	int mcube[n][n][n], count=2,i, j, k;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				mcube[i][j][k] = 0;				
			}	
		}		
	}
	if(n%2!=0)//checking for odd side
	{
		i=0;
		j=(n-1)/2;
		k=(n-1)/2;
		mcube[i][j][k] = 1; //place number 1 in middle of the top layer 
		int m=n*n*n;
		for (count=2; count <=m; count++) //nos bte 1 and n^3
		{
			i = i-1; //layer
			k = k-1; //column
			if(i<0) //should be -1
			{
				i = n-1;
			}
			if(k<0)
			{
				k = n-1;
			}
			if(mcube[i][j][k]!=0) //occupied-case1
			{
				j = j - 1; //row
				k = k+1; 				
				if(j<0)
				{
					j = n-1;
				}
				if(k>n-1)
				{
					k = k%n;
				}
			}
			if(mcube[i][j][k]!=0) //occupied-case2
			{
				i = i +2;
				j = j + 1;	

				if(i>n-1)
				{
					i = i%n;
				}
				if(j>n-1)
				{
					j = j%n;
				}
			}
			mcube[i][j][k] = count;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				printf("%d ",mcube[i][j][k]);
			}
			printf("\n");		
		}
		printf("\n");
	}
	
	for(i=0;i<21;i++){
		p1moves[i]=0;
		p2moves[i]=0;
	}
	p1moves[0]=1;
	p1moves[5]=8;
	p1moves[1]=14;
	p1moves[2]=20;
	p1moves[3]=18;
	p1moves[4]=4;
	
	
	
	display_tictactoe(mcube,p1moves,p2moves);
	p1_score=check_lines(mcube,p1moves);
	printf("p1 score: %d",p1_score);
	return 0;
}











