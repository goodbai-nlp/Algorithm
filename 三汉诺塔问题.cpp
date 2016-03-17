/*************************************************************************
    > File Name: ThreeeHanoi.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月17日 星期五 21时17分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

void hanoi(int disks, char source, char temp, char target) {
	if (disks == 1) {
		cout<<"move disk from "<<source<<" to "<<target<<endl;
		cout<<"move disk from "<<source<<" to "<<target<<endl;
		cout<<"move disk from "<<source<<" to "<<target<<endl;
	}
	else{
		hanoi(disks-1, source, target, temp);
		hanoi(1, source, temp, target);
		hanoi(disks-1, temp, source, target);
	}
}

void hanoi3colors(int disks) {
	char source = 'A';
	char temp = 'B';
	char target = 'C';
	int i;
	if(disks == 3) {
		cout<<"move disk from "<<source<<" to "<<temp<<endl;
		cout<<"move disk from "<<source<<" to "<<temp<<endl;
		cout<<"move disk from "<<source<<" to "<<target<<endl;
		cout<<"move disk from "<<temp<<" to "<<target<<endl;
		cout<<"move disk from "<<temp<<" to "<<source<<endl;
		cout<<"move disk from "<<target<<" to "<<temp<<endl;
	}
	else{
		hanoi(disks/3-1, source, temp, target);
		cout<<"move disk from "<<source<<" to "<<temp<<endl;
		cout<<"move disk from "<<source<<" to "<<temp<<endl;
		cout<<"move disk from "<<source<<" to "<<temp<<endl;
		hanoi(disks/3-1, target, temp, source);
		cout<<"move disk from "<<temp<<" to "<<target<<endl;
		cout<<"move disk from "<<temp<<" to "<<target<<endl;
		cout<<"move disk from "<<temp<<" to "<<target<<endl;
		hanoi(disks/3-1, source, target, temp);
		cout<<"move disk from "<<target<<" to "<<source<<endl;
		cout<<"move disk from "<<target<<" to "<<source<<endl;
		hanoi(disks/3-1, temp, source, target);
		cout<<"move disk from "<<source<<" to "<<temp<<endl;
		for (i = disks / 3 - 1; i > 0; i--) {
			if (i>1) 
				hanoi(i-1, target, source, temp);
			cout<<"move disk from "<<target<<" to "<<source<<endl;
			cout<<"move disk from "<<target<<" to "<<source<<endl;
			if (i>1) 
				hanoi(i-1, temp, source, target);
			cout<<"move disk from "<<source<<" to "<<temp<<endl;
		}
	}
}
int main(){
	int n;
	cin>>n;
	hanoi(n,'A','B','C');
	return 0;
}
