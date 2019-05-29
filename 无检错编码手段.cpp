/*本代码用于模拟无检错编码情况下的传输
假定传输固定数量的给定数据
每个数据位发生传输错误的概率为5%
模拟接收段情况
2019/4/26 by Haoyu Li*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
main(){
int num=10000,sam[N]={1,0,0,1,0,1},count=0;//num为传输数据数目，sam为传输数据100101,count为错误计数
int send[num][N]={0},error[num];//send数组为10000个传输的码组,error为判断，1表示未出错
for(int i=0;i<num;i++) error[i]=1;
for(int i=0;i<num;i++)
for(int j=0;j<N;j++)send[i][j]=sam[j];
srand((unsigned)time(NULL));
for(int i=0;i<num;i++)//按照5%的概率发生传输错误
    for(int j=0;j<N;j++)
{
    int x=rand()%100;
    if(x<=4) send[i][j]=(send[i][j]+1)%2;
}
for(int i=0;i<num;i++)
    {
    for(int j=0;j<N;j++)
        if(send[i][j]!=sam[j]){error[i]=0;count++;break;}
}
//for(int i=0;i<num;i++)printf("%d ",error[i]);
printf("传输错误数为：%d\n",count);
printf("传输错误率为：%.2f%%",100*float(count)/num);}
