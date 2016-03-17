/*************************************************************************
    > File Name: Maze1.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月05日 星期日 12时08分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
int visit(int i,int j);
int maze[7][7]= {
	{2, 2, 2, 2, 2, 2, 2},
	{2, 0, 0, 0, 0, 0, 2},
	{2, 0, 2, 0, 2, 0, 2},
	{2, 0, 0, 2, 0, 2, 2},
	{2, 2, 0, 2, 0, 2, 2},
	{2, 0, 0, 0, 0, 0, 2},
	{2, 2, 2, 2, 2, 2, 2}
};
int sI=1,sJ=1,eI=5,eJ=5,success=0;
int main(){
	cout<<"迷宫:"<<endl;
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			if(maze[i][j]==2)
				cout<<"&";	
			else
				cout<<" ";
		}
		cout<<endl;
	}
	if(visit(sI,sJ)==0)
		cout<<endl<<"没有找到出口"<<endl;
	else{
		cout<<endl<<"显示路径:"<<endl;
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(maze[i][j]==2)
					cout<<"&";
				else if(maze[i][j]==1)
					cout<<"^";
				else
					cout<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
int visit(int i,int j){
	maze[i][j]=1;
	if(i==eI&&j==eJ)
		success=1;
	if(success!=1&&maze[i][j+1]==0) visit(i,j+1);
	if(success!=1&&maze[i+1][j]==0) visit(i+1,j);
	if(success!=1&&maze[i][j-1]==0) visit(i,j-1);
	if(success!=1&&maze[i-1][j]==0) visit(i-1,j);
	if(success!=1)
		maze[i][j]=0;
	return success;
}
