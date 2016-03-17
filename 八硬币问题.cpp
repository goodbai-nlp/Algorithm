/*************************************************************************
    > File Name: EightCoins.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月12日 星期日 13时57分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<time.h>
using namespace std;
void compare(int coins[],int i,int j,int k);
void EightCoins(int coins[]);
int main(){
	int coins[8]={0};
	int i;
	srand(time(NULL));
	for(i=0;i<8;i++)
		coins[i]=10;
	cout<<"\n输入假币重量:";
	cin>>i;
	coins[rand()%8]=i;
	EightCoins(coins);
	cout<<"\n\n列出所有钱币重量: ";
	for(i=0;i<8;i++)
		cout<<coins[i];
	cout<<endl;
	return 0;
}
void compare(int coins[],int i,int j,int k){
	if(coins[i]>coins[k])
		cout<<"\n假币"<<i+1<<"较重";
	else
		cout<<"\n假币"<<j+1<<"较轻";
}
void EightCoins(int coins[]){
	if(coins[0]+coins[1]+coins[2]==coins[3]+coins[4]+coins[5]){
		if(coins[6]>coins[7])
			compare(coins,6,7,0);
		else
			compare(coins,7,6,0);
	}
	else if(coins[0]+coins[1]+coins[2]>coins[3]+coins[4]+coins[5]){
		if(coins[0]+coins[3]==coins[1]+coins[4])
			compare(coins,2,5,0);
		else if(coins[0]+coins[3]>coins[1]+coins[4])
			compare(coins,0,4,1);
		if(coins[0]+coins[3]<coins[1]+coins[4])
			compare(coins,1,3,0);
	}
	else if(coins[0]+coins[1]+coins[2]<coins[3]+coins[4]+coins[5]){
		if(coins[0]+coins[3]==coins[1]+coins[4])
			compare(coins,5,2,0);
		else if(coins[0]+coins[3]>coins[1]+coins[4])
			compare(coins,3,1,0);
		if(coins[0]+coins[3]<coins[1]+coins[4])
			compare(coins,4,0,1);
	}
}
