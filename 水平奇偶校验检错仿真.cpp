/*本代码模拟一位水平奇偶校验位的检错能力
传输固定量的给定数据100101 添加一个奇校验位0
假定信息码组每位错误率相同，均为5%
校验位没有发生错误
2019/4/26 by Haoyu Li*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
main(){
int num=10000,sam[N]={1,0,0,1,0,1},count=0,detect_num=0;//num为传输数据数目，sam为传输数据100101,count为真实错误计数，detect_num为识别错误计数
int send[num][N+1]={0},error[num],detect[num];//send数组为10000个传输的码组,error为判断，1表示未出错 detect为识别到的错误
for(int i=0;i<num;i++) {error[i]=1,detect[i]=1;}
for(int i=0;i<num;i++)
for(int j=0;j<N;j++){send[i][j]=sam[j];send[i][N]=0;}
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

printf("传输错误数为：%d\n",count);
printf("传输错误率为：%.2f%%\n",100*float(count)/num);
for(int i=0;i<num;i++){
    int sum=0;
    for(int j=0;j<N+1;j++) sum+=send[i][j];
    if((sum%2)==0){detect[i]=0;detect_num++;}
}
printf("识别到的错误数为：%d\n",detect_num);
printf("识别到的错误率为：%.2f%%\n",100*float(detect_num)/num);

printf("\n检错率为：%.2f%%\n",100*float(detect_num)/count);
/*for(int i=0;i<num;i++)printf("%d ",error[i]);
putchar('\n');
for(int i=0;i<num;i++)printf("%d ",detect[i]);*/
}

