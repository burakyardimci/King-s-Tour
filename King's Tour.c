#include <stdio.h>
#include "stdlib.h"
#include "string.h"


#define N 8

const int offsetx[]={2,1,-1,-2,-2,-1,-1,2};
const int offsety[]={1,2,2,1,-1,-2,-2,-1};

// function prototypes
int move_r(int,int,int,int [N][N]);
int check_limits(int x,int y);

// main program
int main(void){
    int i,j,board[N][N];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            board[i][j]=0;
        }
    }
    fprintf(stdout,"Initial position ? ");
    scanf("%d %d",&i,&j);
    board[i][j]=1;
    if(move_r(2,i,j,board)){
        fprintf(stdout,"Solution found: \n");
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                fprintf(stdout,"%2d ",board[i][j]);
            }
            fprintf(stdout,"\n");
        }
    }
    else{
        fprintf(stdout,"Solution not found!\n");
    }
    return 0;
}

// compute a knight tour, recursive function
int move_r(int level,int x,int y,int board[N][N]){
    int i,xx,yy;
    if(level==N*N+1){
        return 1;
    }
    for(i=0;i<8;i++){
        xx=x+offsetx[i];
        yy=y+offsety[i];
        if(check_limits(xx,yy)){
            if(board[xx][yy]==0){
                board[xx][yy]=level;
                if(move_r(level+1,xx,yy,board)){
                    return 1;
                }
                board[xx][yy]=0;
            }
        }
    }
    return 0;
}

int check_limits(int x,int y){
    if(x<0 || y<0 || x>=N || y>=N){
        return 0;
    }
    return 1;
}
