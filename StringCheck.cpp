/*************************************************************************
    > File Name: SringCheck.cpp
    > Author: muyeby
    > Mail: muyeby@gmail.com 
    > Created Time: 2015年04月15日 星期三 08时13分42秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void table(char *key);						//建立前进表
int search(int p,char* input,char *key);
void substring(char *text,char *tmp,int s,int e);
int skip[256];

int main(){
	char str_input[80];
	char str_key[80];
	char tmp[80]={'\0'};
	cout<<"Input your string";
	cin>>str_input;
	cout<<"Input your search string";
	cin>>str_key;
	int m=strlen(str_input);
	int n=strlen(str_key);
	table(str_key);
	int p=search(n-1,str_input,str_key);
	while(p!=-1) {
	    substring(str_input,tmp,p,m);
	    printf("%s\n",tmp);;
	    p=search(p+n+1,str_input,str_key);
	}
	cout<<endl;
	return 0;
}
void table(char *key){
	int n=strlen(key);
	for(int k=0;k<255;k++)
		skip[k]=n;
	for(int k=0;k<n-1;k++)
		skip[key[k]]=n-k-1;
}

int search(int p,char* input,char *key){
	char tmp[80]={'\0'};
	int m=strlen(input);
	int n=strlen(key);
	while(p<m){
		substring(input,tmp,p-n+1,p);
		if(!strcmp(tmp,key))
			return p-n+1;
		p+=skip[input[p]];
	}
	return -1;
}
void substring(char *text,char *tmp,int s,int e){
	int i,j;
	for(i=s,j=0;i<=e;i++,j++)
		tmp[j]=text[i];
	tmp[j]='\0';
}

