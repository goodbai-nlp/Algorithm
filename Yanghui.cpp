/*************************************************************************
    > File Name: Yanghui.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月05日 星期日 10时27分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define N 12
using namespace std;
int comb(int n,int r){
	long p=1;
	for(int i=1;i<=r;i++)
		p=p*(n-i+1)/i;
	return p;
}
int main(){
	for(int n=0;n<=N;n++){
		for(int r=0;r<=n;r++){
			if(r==0)
				for(int i=0;i<(N-n);i++)
					cout<<"   ";
			else
				cout<<"   ";
			printf("%3d",comb(n,r));
		}
		cout<<endl;
	}
	return 0;
}
