/*本代码用于模拟无检错编码情况下的传输
假定传输固定数量的给定数据
每个数据位发生传输错误的概率为5%
模拟接收段情况
计算后可知 可以用（11,6）线性分组码编码
并非汉明码 5个冗余位 满足
 by Haoyu Li*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define r 5

void HanmingCoding(int a[]);
void ExamHanming(int a[]);
void testrun();

void HanmingCoding(int a[]){//进行(11,6)汉明编码
a[N]=(a[0]+a[4]+a[5])%2;
a[N+1]=(a[0]+a[1]+a[3])%2;
a[N+2]=(a[2]+a[3]+a[5])%2;
a[N+3]=(a[1]+a[2]+a[4])%2;
a[N+4]=(a[1]+a[3]+a[5])%2;
}

void ExamHanming(int a[],int &sign){//利用校验矩阵H进行校验
    sign=1;
int s[r]={0};
s[0]=(a[N]+a[0]+a[4]+a[5])%2;
s[1]=(a[0]+a[1]+a[3]+a[N+1])%2;
s[2]=(a[2]+a[3]+a[5]+a[N+2])%2;
s[3]=(a[1]+a[2]+a[4]+a[N+3])%2;
s[4]=(a[1]+a[3]+a[5]+a[N+4])%2;
for(int i=0;i<r;i++) if(s[i]!=0) {sign=0;return;}}

void testrun(){
int num=20000,sam[N]={1,0,0,1,0,1},count=0,detect_num=0;//num为传输数据数目，sam为传输数据100101,count为真实错误计数，detect_num为识别错误计数
int send[num][N+r]={0},error[num],detect[num];
int sam_pro[N+r];
for(int i=0;i<num;i++) {error[i]=1,detect[i]=1;}
for(int i=0;i<N;i++)sam_pro[i]=sam[i];
HanmingCoding(sam_pro);//得到汉明编码
printf("\n汉明编码为：");
for(int i=0;i<N+r;i++) printf("%d ",sam_pro[i]);
for(int i=0;i<num;i++)
    for(int j=0;j<N+r;j++)send[i][j]=sam_pro[j];

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
printf("\n传输错误数为：%d\n",count);
printf("传输错误率为：%.2f%%",100*float(count)/num);
for(int i=0;i<num;i++) ExamHanming(send[i],detect[i]);
for(int i=0;i<num;i++) if(detect[i]==0) detect_num++;
printf("\n识别到的错误数为：%d\n",detect_num);
printf("识别到的错误率为：%.2f%%\n",100*float(detect_num)/num);

printf("\n检错率为：%.2f%%\n",100*float(detect_num)/count);
}

main(){
srand((unsigned)time(NULL));
for(int i=0;i<5;i++) testrun();}
