#include "assignment1.h"
void is_collinar(int p1[],int ai[],int pindex,int aindex)
{
    int i,j;
    for(i-0;i<pindex-1;i++)
    {
        num = p1[pindex-1]+p1[i];
        if(((42-num)<=27)&&(42-num)>=0)
        {
            for(j=0;j<aindex-1;j++)
            {
                if(ai[j]==num)
                {
                    break;
                }
            }
            check_collinear(mcube[][50][50],a[pindex-1],a[i],num);
        }
    }
}
void empty_spaces(int a[][50][50],int *arr,int *l,int n){
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
void pos_choice(int a[][50][50],struct options *temp1,struct options *temp2,struct options *temp3){
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
	if(check_sum(a,b,c)==false){
		return false;
	}
	for(i=0;i<3;i++){
	
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				if(mcube[i][j][k]==a){
					i1=i;
					j1=j;
					k1=k;
					
				}
				
				else if(mcube[i][j][k]==b){
					i2=i;
					j2=j;
					k2=k;
					
				}
				
				else if(mcube[i][j][k]==c){
					i3=i;
					j3=j;
					k3=k;
					
				}
				else{
					continue;
				}
			}			
		}
		area = (i1*(j2*k3 - k2*j3) - i2*(j3*k1 - k3*i1) + i3*(j1*k2 - k1*j2));

		printf("A:%f\n",area);
		
		if(area==0){
			return true;
		}
		else {
			return false;
		}
	
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

