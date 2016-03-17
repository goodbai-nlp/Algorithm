/*************************************************************************
    > File Name: MulHanoi.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月17日 星期五 08时57分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

void hanoi(int disks,char source,char temp,char target){
	if(disks==1){
		cout<<"move disk from "<<source<<" to "<<target<<endl;
		cout<<"move disk from "<<source<<" to "<<target<<endl;
	}
	else{
		hanoi(disks-1,source,target,temp);
		hanoi(1,source,temp,target);
		hanoi(disks-1,temp,source,target);	
	}
}

void hanoi2colors(int disks){
	char source='A',temp='B',target='C';
	for(int i=disks/2;i>1;i--){
		hanoi(i-1,source,temp,target);
		cout<<"move disk from "<<source<<" to "<<temp<<endl;
		cout<<"move disk from "<<source<<" to "<<temp<<endl;
		hanoi(i-1,target,temp,source);
		cout<<"move disk from "<<temp<<" to "<<target<<endl;
	}
	cout<<"move disk from "<<source<<" to "<<temp<<endl;
	cout<<"move disk from "<<source<<" to "<<target<<endl;
}
int main(){
	int n;
	cin>>n;
	hanoi2colors(n);
	return 0;
}