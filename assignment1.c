#include "assignment1.h"

//Traverse through the list and display each element of the list.
void display_moves(int a[],int size) 
{
    int i;
      for(i=0;i<size;i++)
      {
          printf("%d, ",a[i]);
      }
      printf("\n");
}

//Check weather each element is not a part of the player moves and AI moves. If itrue, add to the empty spaces list. If not, check for the next element.
void empty_spaces(int a[][50][50],int *arr,int *l,int n){
	int len=0;
	memset(arr,0,(*l)*sizeof(*arr));
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

/*Fill an empty spot that is of the highest category in the following category:
i) Centre of plane
ii) Corners of plane
iii) Left over points
*/
void pos_choice(int a[][50][50],struct options *temp1,struct options *temp2,struct options *temp3){
	temp1->index=-1;
	temp2->index=-1;
	temp3->index=-1;
	for(int i=0;i<3;i++){
		if(a[i][0][0]!=AI && a[i][0][0]!=P1){
			if(temp1->index<0){
				temp1->index=0;
			}
			temp1->arr[temp1->index]=a[i][0][0];
			temp1->index+=1;
		}
		if(a[i][0][2]!=AI && a[i][0][2]!=P1){
			if(temp1->index<0){
				temp1->index=0;
			}
			temp1->arr[temp1->index]=a[i][0][2];
			temp1->index+=1;
		}
		if(a[i][2][0]!=AI && a[i][2][0]!=P1){
			if(temp1->index<0){
				temp1->index=0;
			}
			temp1->arr[temp1->index]=a[i][2][0];
			temp1->index+=1;
		}
		if(a[i][2][2]!=AI && a[i][2][2]!=P1){
			if(temp1->index<0){
				temp1->index=0;
			}
			temp1->arr[temp1->index]=a[i][2][2];
			temp1->index+=1;
		}
	}
	for(int i=0;i<3;i++){
		if(a[i][1][1]!=AI && a[i][1][1]!=P1){
			if(temp2->index<0){
				temp2->index=0;
			}
			temp2->arr[temp2->index]=a[i][1][1];
			temp2->index+=1;
		}
	}
	for(int i=0;i<3;i++){
		if(a[i][0][1]!=AI && a[i][0][1]!=P1){
			if(temp3->index<0){
				temp3->index=0;
			}
			temp3->arr[temp3->index]=a[i][0][1];
			temp3->index+=1;
		}
		if(a[i][1][0]!=AI && a[i][1][0]!=P1){
			if(temp3->index<0){
				temp3->index=0;
			}
			temp3->arr[temp3->index]=a[i][1][0];
			temp3->index+=1;
		}
		if(a[i][2][1]!=AI && a[i][2][1]!=P1){
			if(temp3->index<0){
				temp3->index=0;
			}
			temp3->arr[temp3->index]=a[i][2][1];
			temp3->index+=1;
		}
		if(a[i][1][2]!=AI && a[i][1][2]!=P1){
			if(temp3->index<0){
				temp3->index=0;
			}
			temp3->arr[temp3->index]=a[i][1][2];
			temp3->index+=1;
		}
	}
}

//Check if an element is present in an array.
int check_if_present(int a[],int lenght,int find){
	for(int i=0;i<lenght;i++){
		if(a[i]==find){
			return true;
		}
	}
	return false;
}

//Print the magic cube
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

//Function to print the tic tac toe grid
void print_board(int c[][50][50],int mcube[][50][50],int n){
 	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(c[i][j][k]==P1){
					printf("%c(%d)\t",P1SYM,mcube[i][j][k]);
				}
				else if(c[i][j][k]==AI){
					printf("%c(%d)\t",AISYM,mcube[i][j][k]);
				}
				else{
					printf("%d\t",c[i][j][k]);
				}
			}
			printf("\n");		
		}
		printf("\n");
	}
}

//For every element in the source cube, copy it into the same position in the destination cube
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

//Traverse through the array and find the element to be searched. Once the element has been found, mark the player’s icon in that position
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

//Traverse through the array. At each element of the cube, check if it is equal to the element to be found. If yes, return the position. If not, then check for the next elements
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

//Check the sum of the three numbers passed to function. If the sum is 42, return true, else return false.
int check_sum(int a, int b, int c){
	if((a+b+c)==42){
		return true;
	}
	else {
		return false;
	}
}

//check weather the points given are collinear
int check_collinear(int mcube[][50][50], int a, int b, int c){
	int i,j,k;
	int i1,j1,k1,i2,j2,k2,i3,j3,k3;
	int area;
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
			}			
		}
    }

    //points are (i1,j1,k1),(i2,j2,k2),(i3,j3,k3)
    //assuming 3 distinct points
    int c1=0, c2=0, c3=0;
    
    if ((i1==i2)&&(i2==i3)) c1=1;
    if ((j1==j2)&&(j2==j3)) c2=1;
    if ((k1==k2)&&(k2==k3)) c3=1;
    
    //printf("points: (%d,%d,%d),(%d,%d,%d),(%d,%d,%d)\n",i1,j1,k1,i2,j2,k2,i3,j3,k3);
    //printf("c1=%d,c2=%d,c3=%d\n",c1,c2,c3);
    
    if (c1+c2+c3 == 2) //vertical/horiz 3 points on an edge or face of the cube
        area=0;
        // points on a diagonal on the face of the cube
    else if ((c1+c2+c3 == 1)&&(((c1==1)&&(j1+j2+j3==3)&&(k1+k2+k3==3))||((c2==1)&&(i1+i2+i3==3)&&(k1+k2+k3==3))||((c3==1)&&(i1+i2+i3==3)&&(j1+j2+j3==3))))
                area=0;
        //body diagonal
    else if ((c1+c2+c3 == 0)&&(i1+i2+i3==3)&&(j1+j2+j3==3)&&(k1+k2+k3==3))
            {
                area=0;            
            }
    else area=1;                
		if(area==0){
			return true;
		}
		else {
			return false;
		}
}

//generate the magic cube
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

//take the absolute value of the difference
int modulas_sub(int a,int b){
	if((a-b)<0){
		return (-1)*(a-b);
	}
	else{
		return (a-b);
	}
}

/*
Check if the player can make a line by placing their symbol on an empty spot on the board. 
If yes, block it. 
If not, go to step 2.
Check if AI can make a line by placing its symbol on an empty spot on the board. 
If yes, play that spot. 
If not, go to step 3.
Go to pos_choice to determine your next move.
*/
int point_to_add(int mcube[][50][50],int temp[][50][50],int arr[],int len){
	int empty_pos[27];
	int empty_pos_len;
	empty_spaces(temp,empty_pos,&empty_pos_len,3);
	if(len==1){
		return -1;
	}
	for(int i=0;i<len;i++){
		for(int j=1;j<len;j++){
			if(i==j){
				continue;
			}
			int pos=modulas_sub(42,(arr[j]+arr[i]));
			if(pos>=1 && pos<=27){
				if(check_collinear(mcube,arr[i],arr[j],pos)==false){
					continue;
				}
				if(check_if_present(empty_pos,empty_pos_len,pos)==true){
					printf("%d,%d\n",arr[j],arr[i]);
					return pos;
				}
			}
			else{
				continue;
			}
		}
	}
	return -1;
}

//Function to check no. of lines formed
int check_lines(int mcube[][50][50], int list[]){
	int i,j,k;
	int count=0;
	for(i=0;list[i]!=0;i++){
		for(j=i+1;list[j]!=0;j++){
			for(k=j+1;list[k]!=0;k++){
                if((check_sum(list[i],list[j],list[k])==true)&&(check_collinear(mcube,list[i],list[j],list[k]) == true))
				{
				    count++;
				}
			}
		}
	}
	return count;
}
