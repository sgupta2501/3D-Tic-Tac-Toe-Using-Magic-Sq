#include<stdio.h>
#include<stdlib.h>



int check_sum(int a, int b, int c){
	if((a+b+c)==42){
		printf("sum checking success\n");
		return 1;
	}
	else {
		return 0;
	}
}


int check_collinear(int mcube[3][3][3], int a, int b, int c){
	int i,j,k;
	int i1,j1,k1,i2,j2,k2,i3,j3,k3;
	float area;
	double x_ratio, y_ratio, z_ratio;
	printf("%d\n",c);
	for(i=0;i<3;i++){
	
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				if(mcube[i][j][k]==a){
					i1=i;
					j1=j;
					k1=k;
					
					printf("%d : %d %d %d\n",mcube[i][j][k],i,j,k);
				}
				
				else if(mcube[i][j][k]==b){
					i2=i;
					j2=j;
					k2=k;
					
					printf("%d : %d %d %d\n",mcube[i][j][k],i,j,k);
				}
				
				else if(mcube[i][j][k]==c){
					i3=i;
					j3=j;
					k3=k;
					
					printf("%d : %d %d %d\n",mcube[i][j][k],i,j,k);
				}
				else{
					continue;
				}
			}			
		}
		
		/*x_ratio=(float)(i2-i1)/(i3-i1);
		y_ratio=(float)(j2-j1)/(j3-j1);
		z_ratio=(float)(k2-k1)/(k3-k1);*/
		
		area = (i1*(j2*k3 - k2*j3) - i2*(j3*k1 - k3*i1) + i3*(j1*k2 - k1*j2));
		
		printf("%f\n", area);
		
		/*if((x_ratio == y_ratio)&&(y_ratio == z_ratio)){
			return 1;
		}
		else {
			return 0;
		}*/
		
		if(area==0){
			return 1;
		}
		else {
			return 0;
		}
	
    }
}



int check_lines(int mcube[3][3][3], int list[]){
	int i,j,k;
	int count=0;
	
	for(i=0;list[i]!=0;i++){
		for(j=i+1;list[j]!=0;j++){
			for(k=j+1;list[k]!=0;k++){
				if(check_sum(list[i],list[j],list[k])==1 && check_collinear(mcube,list[i],list[j],list[k])==1)
				count++;
			}
		}
	}
	return count;
}

