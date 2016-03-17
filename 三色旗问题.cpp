/*************************************************************************
    > File Name: ThreeColorFlag.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月05日 星期日 11时16分47秒
 ************************************************************************/

#include<iostream>
#define swap(t,x,y){t _z;_z = y;y = x;x = _z;}
using namespace std;
void Sequence(char *a,int n){
	int num=0;
	int W=0,B=0,R=n-1;
	while(W<=R){
		if('W'==a[W])
			W+=1;
		else{
			if('B'==a[W]){
				swap(char,a[W],a[B]);
				W++;
				B++;
			}
			else{
				swap(char,a[R],a[W]);
				num++;
				R--;
			}
		}
	}
	cout<<num<<endl;
}
int main(){
	char a[10]={'W','B','B','R','R','W','R','B','W','B'};
	Sequence(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i];
	return 0;
}
