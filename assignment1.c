#include "assignment1.h"
int check_if_present(int a[],int lenght,int find){
	for(int i=0;i<lenght;i++){
		if(a[i]==find){
			return true;
		}
	}
	return false;
}
void print_cube(int c[][50][50],int n){
 	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				printf("%d ",c[i][j][k]);
			}
			printf("\n");		
		}
		printf("\n");
	}
}
void print_board(int c[][50][50],int n){
 	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(c[i][j][k]==P1){
					printf("%c\t",P1SYM);
				}
				else if(c[i][j][k]==AI){
					printf("%c\t",AISYM);
				}
				else{
					printf("%d\t",c[i][j][k]);
				}
				// printf("%d ",c[i][j][k]);
			}
			printf("\n");		
		}
		printf("\n");
	}
}
void copy_cube(int other[][50][50],int main[][50][50],int n){
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				other[i][j][k]=main[i][j][k];
			}	
		}
	}
}
int put_val(int d[][50][50],int n,int player,int find){
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{	if(d[i][j][k]==find){
					d[i][j][k]=player;
					return true;
				}
			}	
		}
	}
	return false;
}
void find_pos(int d[][50][50],int *a,int *b,int *c,int n,int find){
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(d[i][j][k]==find){
					*a=i;
					*b=j;
					*c=k;
				}
			}	
		}
	}

}
int check_sum(int a, int b, int c){
	if((a+b+c)==42){
		printf("sum checking success\n");
		return true;
	}
	else {
		return false;
	}
}


int check_collinear(int mcube[][50][50], int a, int b, int c){
	int i,j,k;
	int i1,j1,k1,i2,j2,k2,i3,j3,k3;
	float area;
	double x_ratio, y_ratio, z_ratio;
	for(i=0;i<3;i++){
	
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				if(mcube[i][j][k]==a){
					i1=i;
					j1=j;
					k1=k;
					
					// printf("%d : %d %d %d\n",mcube[i][j][k],i,j,k);
				}
				
				else if(mcube[i][j][k]==b){
					i2=i;
					j2=j;
					k2=k;
					
					// printf("%d : %d %d %d\n",mcube[i][j][k],i,j,k);
				}
				
				else if(mcube[i][j][k]==c){
					i3=i;
					j3=j;
					k3=k;
					
					// printf("%d : %d %d %d\n",mcube[i][j][k],i,j,k);
				}
				else{
					continue;
				}
			}			
		}
		
		int l=-100;
		int tx1=i2-i1;
		int ty1=j2-j1;
		int tz1=k2-k1;
		int tx2=i3-i2;
		int ty2=j3-j2;
		int tz2=k3-k2;
		printf("%d %d %d %d %d %d\n",tx1,ty1,tz1,tx2,ty2,tz2);

		int l1=0,l2=0,l3=0;
		if(tx2==0){
			l1=0;
		}
		else{
			l1=tx1/tx2;
		}
		if(ty2==0){
			l2=0;
		}
		else{
			l2=ty1/ty2;
			if(l1!=0){
				if(l2!=l1){
					return false;
				}
			}
		}
		if(tz2==0){
			l3=0;
		}
		else{
			l3=tz1/tz2;
			if(l2!=0){
				if(l2!=l3){
					return false;
				}
			}
		}
		return true;	
    }
}
void magic_cube_gen(int mcube[][50][50],int n){
	int count=2,i, j, k;
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
}

