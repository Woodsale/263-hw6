#include <iostream>
#include <string> 
//#include "back.h"
/*
bool back(int board[9][9]){
	int i,j,k,m,n;	
	for(i = 0;i<9;i++){
		for(j = 0;j<9;j++){
			if((board[i][j] == 0)){
				for(k = 1;k<10;k++){
					if((col(board[][],i,k))&&(row(board[][],j,k))){
						
					}
				}
			}
		}	
	}
	return false;
}*/
bool back(int board[9][9],int r,int c,int avoid);
bool col(int board[9][9],int row,int num);
bool row(int board[9][9],int col,int num);
//bool area(int board[9][9],row,col,num);
	

bool back(int board[9][9],int r,int c,int avoid){
	int num = 1;
	int twenty = 20;
	if(board[r][c] == 0){
		while((board[r][c] == 0)&&(num < 10)){
			if(num == avoid){
				num = num + 1;
			}
			if((col(board,r,num) == true)&&
				(row(board,c,num) == true)){
				board[r][c] = num;
			}else{
				//board[r][c]=num;
				num = num + 1;
			}
		}
		if(board[r][c] == 0){
			return false;
		}	
	}
	if(r == 8){
		if(c == 8){
			return true;
		}else{
		r = 0;
		c = c + 1;
		}
	}else{
		r = r + 1;
	}
	printf("\n%d\n",num);	
	//bool next; //= back(board,r,c,twenty);
	/*if( back(board,r,c,twenty) == false){
		avoid = num;
		if((c = 0)&&(r > 0)){
			r = 8;
			c = c - 1;
		}
		if((r != 0)&&(c != 0)){
			r = r - 1;
			c = c - 1;	 
		}
		back(board,r,c,avoid);
	}*/
	if(back(board,r,c,twenty) == true){
		back(board,r,c,twenty);
	}else{
		return false;
	}
	return false;
}
/*
bool area(int board[9][9],&row,&col,num){
	for(){
		for(){
			
		}
	}
}*/

bool col(int board[9][9],int row,int num){
	for(int j = 0;j<9;j++){
		if(num == board[row][j]){
			return false;	
		}
	}
	return true;
}
bool row(int board[9][9],int col,int num){
	for(int i = 0;i<9;i++){
		if(num == board[i][col]){
			return false;	
		}
	}
	return true;
}

int main(){
	int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
        	           { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
        	           { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
        	           { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
        	           { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
        	           { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
        	           { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
        	           { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
        	           { 0, 7, 0, 0, 0, 0, 0, 3, 0 }
        };
	back(board,0,0,20);//row,col,avoid
	//prints board at the end
	for(int i = 0;i<9;i++){
		for(int k = 0;k<9;k++){
			printf("%d   ",board[i][k]);
		}
		printf("\n");
	}
	return 0;
}
