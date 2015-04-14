/*************************************************************************
    > File Name: Hanoi.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月04日 星期六 10时43分43秒
 ************************************************************************/
#include<iostream>
using namespace std;

void hanoi(int n,char A,char B,char C){
	if(n==1)
		cout <<"Move disk "<< n <<" from "<< A << " to " << C <<endl;
	else{
		hanoi(n-1,A,C,B);
		cout << "Mone disk " <<n <<" from "<< A << " to " << C <<endl;
		hanoi(n-1,B,A,C);
	}
}
int main(){
	int n;
	cin>>n;
	hanoi(n,'A','B','C');
	return 0;
}
