 #include <stdio.h>         
 void fun(int *a){          
     a[0]=100;              
 }                          
 int main(){                
     int a[3]={1,2,3};      
     fun(a);                
     printf("%d",a[0]);     
     return 0;              
 }                          
                            
                            
