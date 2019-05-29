/*本代码实现群计数码的仿真模拟
数据量15000 码组长度为6 冗余码长度为3
每个信道误码率为5%
By Haoyu Li*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 6

void qunjishu(int a[],int n_pro);
void exam(int send[],int n_pro, int &sign);
void test();


void test(){
int num=15000,sam[N+3]={1,0,0,1,0,1},n_pro=N+3;
int send[num][n_pro],error[num],detect[num],detect_num=0,count=0;
for(int i=0;i<num;i++) {error[i]=detect[i]=1;}
for(int i=N;i<n_pro;i++) sam[i]=0;
qunjishu(sam,n_pro);
printf("群计数码为：\n");
for(int i=0;i<n_pro;i++) printf("%d ",sam[i]);
for(int i=0;i<num;i++)
    for(int j=0;j<n_pro;j++)
    send[i][j]=sam[j];
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

printf("\n传输错误数为：%d\n",count);
printf("传输错误率为：%.2f%%\n",100*float(count)/num);
for(int i=0;i<num;i++) exam(send[i],n_pro,detect[i]);
for(int i=0;i<num;i++) if(detect[i]==0) detect_num++;
printf("识别到的错误数为：%d\n",detect_num);
printf("识别到的错误率为：%.2f%%\n",100*float(detect_num)/num);
printf("\n检错率为：%.2f%%\n",100*float(detect_num)/count);
}

void qunjishu(int a[],int n_pro){
int sum=0;//sum为1的个数
for(int i=0;i<N;i++)
    if(a[i]==1)sum++;
int pos=n_pro;
while(sum!=0){
    a[--pos]=(sum%2);
    sum=sum/2;
}
}

void exam(int send[],int n_pro,int &sign){
    sign=1;
    int sum=0;
    for(int i=0;i<N;i++) if(send[i]==1) sum++;
    int cor=0;
    for(int i=N;i<n_pro;i++) cor+=send[i]*pow(2,8-i);
    if(cor!=sum) sign=0;
}

main(){
srand((unsigned)time(NULL));
for(int i=0;i<3;i++) test();}
