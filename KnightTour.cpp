/*************************************************************************
    > File Name: KnightTour.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com
    > Created Time: 2015年04月06日 星期一 09时20分12秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<cstdio>
#define N 7
using namespace std;
int board[N][N]={0};
int travel(int x,int y);
int main(){
	int sx,sy;
	while(scanf("%d %d",&sx,&sy)!=EOF){
		if(sx<1||sy<1||sx>N||sy>N) break;
		if(travel(sx,sy))
			printf("Travel finished\n");
		else
			printf("Travel failed!\n");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%2d ",board[i][j]);
			}
			puts("\n");
		}
	}
	return 0;
}
int travel(int x,int y){
	memset(board,0,sizeof(board));
	int ktmove1[8]={-2,-1,1,2,2,1,-1,-2};//骑士可走的八个方向
	int ktmove2[8]={1,2,2,1,-1,-2,-2,-1};
	int nexti[8]={0};
	int nextj[8]={0};
	int exits[8]={0};
	int i=x,j=y;
	int k,m,l,count,min,tmpi,tmpj,tmp;
	board[i][j]=1;
	for (m=2;m<=N*N;m++){
		for(l=0;l<8;l++)
			exits[l]=0;
		l=0;
		for(k=0;k<8;k++){
			tmpi=i+ktmove1[k];
			tmpj=j+ktmove2[k];
			if(tmpi<0||tmpj<0||tmpi>7||tmpj>7)
				continue;
			if(board[tmpi][tmpj]==0){
				nexti[l]=tmpi;
				nextj[l]=tmpj;
				l++;
			}
		}
		count=1;
		if(count==0) return 0;
		else if(count==1) min=0;
		else{
			for(l=0;l<count;l++){
				for(k=0;k<8;k++){
					tmpi=nexti[l]+ktmove1[k];
					tmpj=nextj[l]+ktmove2[k];
					if(tmpi<0||tmpj<0||tmpi>7||tmpj>7)
						continue;
					if(board[tmpi][tmpj]==0)
						exits[l]++;
				}
			}
			tmp=exits[0];
			min=0;
			for(l=1;l<count;l++)
				if(exits[l]<tmp){
					tmp=exits[l];
					min=l;
				}
		}
		i=nexti[min];
		j=nextj[min];
		board[i][j]=m;
	}
	return l;
}
