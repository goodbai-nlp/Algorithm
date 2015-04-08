/*************************************************************************
    > File Name: EightQueen.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月07日 星期二 14时52分05秒
 ************************************************************************/

#include<iostream>
#define N 8
using namespace std;
int cloumn[N+1];//同栏是否有皇后,1有
int rup[2*N+1];//右上至左下是否有皇后
int lup[2*N+1];//左上至右下是否有皇后
int queen[N+1]={0};
int num;//解答编号

void backtrack(int i);
void showAnswer();

int main(){
	num=0;
	for(int i=1;i<=N;i++)
		cloumn[i]=1;
	for(int i=1;i<=2*N;i++)
		rup[i]=lup[i]=1;
	backtrack(1);
	return 0;
}
void showAnswer(){
	cout<<"\n解答" <<++num<<endl;
	for(int y=1;y<=N;y++){
		for(int x=1;x<=N;x++){
			if(queen[y]==x)
				cout<<" Q";
			else
				cout<<" .";
		}
		cout<<endl;
	}
}
void backtrack(int i){
	int j;
	if(i>N)
		showAnswer();
	else{
		for(int j=1;j<=N;j++){
			if(cloumn[j]==1&&rup[i+j]==1&&lup[i-j+N]==1){
				queen[i]=j;
				cloumn[j]=rup[i+j]=lup[i-j+N]=0;
				backtrack(i+1);
				cloumn[j]=rup[i+j]=lup[i-j+N]=1;
			}
		}
	}
}