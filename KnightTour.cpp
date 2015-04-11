#include <iostream>
#include <iomanip>
#define SIZE 8
using namespace std;
bool travel(int board[][SIZE],int x,int y);
int possible(int board[][SIZE],int *nexti,int *nextj,int x,int y);
int min(int board[][SIZE],int *nexti,int *nextj,int count);
void printBoard(int borad[][SIZE]);
int main()
{
    int start_x;
    int start_y;
    cout<<"输入初始位置"<<endl;
    cin>>start_x>>start_y;
    int board[SIZE][SIZE]={0};
    if(start_x>SIZE-1||start_y>SIZE-1)cout<<"输入越界!"<<endl;
    else if(travel(board,start_x,start_y))cout<<"遍历成功!"<<endl;
    else cout<<"遍历失败!"<<endl;
    printBoard(board);
    return 0;
}
bool travel(int board[][SIZE],int x,int y)
{
    board[x][y]=1;                   			//当前位置为第1次走的位置
    int nexti[SIZE]={0};
    int nextj[SIZE]={0};             			//下一跳初始化
    int i=x;
    int j=y;
    int MAX=SIZE*SIZE;
    int count=0;
    for(int m=2;m<=MAX;m++)          			//遍历棋盘,记录过程
    {
        count=possible(board,nexti,nextj,i,j);  //得到可能的下一跳数目
        if(count==0)return false;               //无可走方向,遍历失败
        int min_Direction=min(board,nexti,nextj,count);//在多个可能方向中查找下一跳方向最少的方向
        i=nexti[min_Direction];      			//下一跳位置坐标
        j=nextj[min_Direction];
        board[i][j]=m;               			//当前位置为第m次走的位置
    }
    return true;
}
int possible(int board[][SIZE],int *nexti,int *nextj,int x,int y)
{
    int mvi[SIZE]={-2,-1,1,2,2,1,-1,-2};    	//下一跳可能的八个方向(x坐标y坐标)
    int mvj[SIZE]={1,2,2,1,-1,-2,-2,-1};
    int count=0;
    for(int i=0;i<SIZE;++i)
    {
        int tmpx=x+mvi[i];
        int tmpy=y+mvj[i];
        if(tmpx<0||tmpy<0||tmpx>SIZE-1||tmpy>SIZE-1)continue; //越界,不是可行方向
        if(board[tmpx][tmpy]==0)                  //未走过,找到一个可能方向
        {
            nexti[count]=tmpx;
            nextj[count]=tmpy;
            count++;
        }
    }
    return count;                              //返回可能的方向数
}
int min(int board[][SIZE],int *nexti,int *nextj,int count)
{
    int mvx[SIZE]={-2,-1,1,2,2,1,-1,-2};
    int mvy[SIZE]={1,2,2,1,-1,-2,-2,-1};
    int exist[SIZE]={0};                   //记录该方向的下一跳方向的数目
    int min_direction=-1;                  //初始化最小方向数的方向
    if(count==1)min_direction=0;           //只有一个可行方向
    else
    {
        for(int i=0;i<count;++i)           	//在所有可行方向中遍历
        {
            for(int j=0;j<SIZE;++j)        	//计算每一个方向下一跳的数目
            {
                int tmpx=nexti[i]+mvx[j];
                int tmpy=nextj[i]+mvy[j];
                if(tmpx<0||tmpy<0||tmpx>SIZE-1||tmpy>SIZE-1)continue;
                if(board[tmpx][tmpy]==0)
                    exist[i]++;
            }
        }
        int min=exist[0];                 	//取其中最小数目的方向
        min_direction=0;
        for(int i=1;i<count;++i)		  	//exist数组只有count位不为0
        {
            if(exist[i]<min)
            {
                min=exist[i];
                min_direction=i;
            }
        }
    }
    return min_direction;
}
void printBoard(int board[][SIZE])
{
     for(int i=0;i<SIZE;++i)
     {
         for(int j=0;j<SIZE;++j)
         {
             cout<<setw(2)<<board[i][j]<<" ";
         }
         cout<<endl;
     }
}
