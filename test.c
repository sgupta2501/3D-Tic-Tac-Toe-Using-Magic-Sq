#include "assignment1.h"
int main(int argc, char *argv[]) 
{	
	// int empty_spaces[50]={};
	// int empty_length;
	int n;
 	//scanf("%d",&n);   //taking the size as input- fixing here to 3
 	n=3;
	int mcube[50][50][50];
	magic_cube_gen(mcube,n);
	int temp[50][50][50];
	copy_cube(temp,mcube,n);
	int mconst=(n*((n*n*n)+1))/2;
	int a,b,c;
	int ai[14];
	int p1[14];
	int pindex=0,aindex=0;
	int turn=P1;
	int first=0;
	struct options first_preference;
	struct options second_preference;
	struct options third_preference;

	// printf("%d\n",check_collinear(mcube,25,14,3));
 //    int cube[50][50][50]={{{20,18,4},{15,1,26},{7,23,12}},
 //    				{{6,19,17},{25,14,3},{11,9,22}},
 //    				{{16,5,21},{2,27,13},{24,10,8}}};
	// int board[50][50][50]={{{AI,18,AI},{AI,P1,26},{7,23,P1}},
 //    				{{6,19,17},{25,14,3},{11,9,22}},
 //    				{{16,5,21},{2,27,13},{24,10,8}}};
	// print_cube(cube,3);
	// printf("%d\n",point_to_add(cube,board,AI,ai,3));
	// from here
	int choice=1;
	while(1){
		printf("player first or ai?\n");
		printf("1:player(default)\n");
		printf("2:ai\n");
		scanf("%d",&choice);
		if(choice<1 || choice>2){
			printf("wrong choice\n");
		}
		else{
			if(choice==1){
				break;
				turn=P1;
			}
			else if(choice==2){
				turn=AI;
				break;
			}
		}
		system("clear");
	}
	if(choice==1){
		while(((pindex+aindex)!=27))
		{
    		 int ai_line=check_lines(mcube,ai);
			 int p1_line=check_lines(mcube,p1);
			 printf("AI lines:%d\n",ai_line);
			 printf("P1 lines:%d\n",p1_line);
			 printf("...... ");

			 printf("AI moves:");
						
			 display_moves(ai,aindex);
			 printf("Player Moves:");
			 display_moves(p1,pindex);
			 int pos;
			 print_board(temp,mcube,n);
			 turn=P1;
			 printf("enter positon\n");
			 scanf("%d",&pos);

			 while (put_val(temp,n,turn,pos)==false){
				printf("......  ");

				printf("value filled\n");
				printf("enter positon\n");
				scanf("%d",&pos);
			}
			turn=AI;
			p1[pindex]=pos;
			pindex+=1;
			if(((pindex+aindex)<2) && (first==0)){
    			printf("......  ");
				first=1;
				if(pos==14){
					if(put_val(temp,n,turn,mcube[0][0][0])==true){
						printf("AI played at position %d\n",mcube[0][0][0]);
						ai[aindex]=mcube[0][0][0];
						aindex+=1;

					}
					else{
						printf("something went wrong\n");
					}
				}
				else{
					int p=n/2;
					if(put_val(temp,n,turn,mcube[p][p][p])==true){
						printf("AI played at position %d\n",mcube[p][p][p]);
						ai[aindex]=mcube[p][p][p];
						aindex+=1;
					}
					else{
						printf("something went wrong\n");
					}
				}
			}
			else{
    			printf("......  ");
				//blocking the player
				turn=AI;
				int block=point_to_add(mcube,temp,p1,pindex);
    			printf("......****  ");

				printf("block:%d\n",block);
				if(block==-1){
					printf("ai_len:%d\n",aindex);
					block=point_to_add(mcube,temp,ai,aindex);
					if(block==-1){
						//printf("in here\n");
						pos_choice(temp,&second_preference,&first_preference,&third_preference);
						if((first_preference.index)>=0){
							if(put_val(temp,n,turn,first_preference.arr[0])==true){
								printf("AI played at:%d ,successfully\n",first_preference.arr[0]);
								ai[aindex]=first_preference.arr[0];
								aindex+=1;
							}
							else{
								printf("something went wrong\n");
							}
						}
						else if((second_preference.index)>=0){
							if(put_val(temp,n,turn,second_preference.arr[0])==true){
								printf("AI played at:%d ,successfully\n",second_preference.arr[0]);
								ai[aindex]=second_preference.arr[0];
								aindex+=1;
							}
							else{
								printf("something went wrong\n");
							}
						}
						else if((third_preference.index)>=0){
							if(put_val(temp,n,turn,third_preference.arr[0])==true){
								printf("AI played at:%d ,successfully\n",third_preference.arr[0]);
								ai[aindex]=third_preference.arr[0];
								aindex+=1;
							}
							else{
								printf("something went wrong\n");
							}
						}


					}
					else{
						if(put_val(temp,n,AI,block)==true){
							printf("AI played at:%d ,successfully\n",block);
							ai[aindex]=block;
							aindex+=1;
						}
						else{
							printf("something went wrong\n");
						}
					}
				}
				else{
					ai[aindex]=block;
					aindex+=1;
					if(put_val(temp,n,AI,block)==true){
						printf("AI played at:%d ,successfully\n",block);
					}
					else{
						printf("something went wrong\n");
					}
				}
						
			}
             printf("The Final Results are:\n"); 
			 printf("AI lines:%d\n",ai_line);
			 printf("P1 lines:%d\n",p1_line);	
             if (ai_line==10) printf("AI WINS.....\n");
             if (p1_line==10) printf("PLAYER WINS.....\n");			 		
		}
	}
	else if(choice==2){
		printf("ai plays\n");
		while(((pindex+aindex)!=27))
		{
			turn=AI;
			 int ai_line=check_lines(mcube,ai);
			 int p1_line=check_lines(mcube,p1);
			 printf("AI lines:%d\n",ai_line);
			 printf("P1 lines:%d\n",p1_line);
			 printf("AI moves:");
			 display_moves(ai,aindex);
			 printf("Player Moves:");
			 display_moves(p1,pindex);
			 int pos;
			 printf("\n\n");
			 if(((pindex+aindex)<2) && (first==0)){
				//printf("in here\n");
				first=1;
				if(put_val(temp,n,AI,14)==true){
					printf("AI played at:%d ,successfully\n",14);
					ai[aindex]=14;
					aindex+=1;
				}
				else{
					printf("something went wrong\n");
				}
				print_board(temp,mcube,n);
				printf("enter positon\n");
				scanf("%d",&pos);

				while (put_val(temp,n,P1,pos)==false){
					printf("value filled\n");
					printf("enter positon\n");
					scanf("%d",&pos);
				}
				p1[pindex]=pos;
				pindex+=1;

			}
			else{	
				turn=AI;
				printf("%d\n",pindex);
				int block=point_to_add(mcube,temp,p1,pindex);
				if(block==-1){	
					printf("ai:%d\n",aindex);				
					block=point_to_add(mcube,temp,ai,aindex);
					if(block==-1){
						pos_choice(temp,&second_preference,&first_preference,&third_preference);
						if((first_preference.index)>=0){
							if(put_val(temp,n,turn,first_preference.arr[0])==true){
								printf("AI played at:%d ,successfully\n",first_preference.arr[0]);
								ai[aindex]=first_preference.arr[0];
								aindex+=1;
							}
							else{
								printf("something went wrong\n");
							}
						}
						else if((second_preference.index)>=0){
							if(put_val(temp,n,turn,second_preference.arr[0])==true){
								printf("AI played at:%d ,successfully\n",second_preference.arr[0]);
								ai[aindex]=second_preference.arr[0];
								aindex+=1;
							}
							else{
								printf("something went wrong\n");
							}
						}
						else if((third_preference.index)>=0){
							if(put_val(temp,n,turn,third_preference.arr[0])==true){
								printf("AI played at:%d ,successfully\n",third_preference.arr[0]);
								ai[aindex]=third_preference.arr[0];
								aindex+=1;
							}
							else{
								printf("something went wrong\n");
							}
						}


					}
					else{
						if(put_val(temp,n,AI,block)==true){
							printf("AI played at:%d ,successfully\n",block);
							ai[aindex]=block;
							aindex+=1;
						}
						else{
							printf("something went wrong\n");
						}
					}
				}
				else{
					ai[aindex]=block;
					aindex+=1;
					if(put_val(temp,n,AI,block)==true){
						printf("AI played at:%d ,successfully\n",block);
					}
					else{
						printf("something went wrong\n");
					}
				}

				print_board(temp,mcube,n);

				printf("enter positon\n");
				scanf("%d",&pos);
				while (put_val(temp,n,P1,pos)==false){
					printf("value filled\n");
					printf("enter positon\n");
					scanf("%d",&pos);
				}
				p1[pindex]=pos;
				pindex+=1;

			}
			// while (put_val(temp,n,turn,pos)==false){
			// 	printf("value filled\n");
			// 	printf("enter positon\n");
			// 	scanf("%d",&pos);
			// }

             printf("The Final Results are:\n"); 
			 printf("AI lines:%d\n",ai_line);
			 printf("P1 lines:%d\n",p1_line);			
             if (ai_line==10) printf("AI WINS.....\n");
             if (p1_line==10) printf("PLAYER WINS.....\n");
		}
	}
	return 0;
}
