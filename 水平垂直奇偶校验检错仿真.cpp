/*本代码模拟垂直水平奇偶校验的检错能力
传输的码组为100与101 2个一组传输，行列分别进行奇校验
假定信息码组误码率为5%
2019/4/26 by Haoyu Li*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 2
#define COL 3
void Detect(int (*rec)[COL+1],int judge[],int &num,int p)
{
    for(int i=0;i<ROW;i++){
            int sum=0;
    for(int j=0;j<COL+1;j++)sum+=rec[i][j];
    if((sum%2)==0) {judge[p]=0;num++;return;}}
    for(int j=0;j<COL;j++){
        int sum=0;
    for(int i=0;i<ROW+1;i++)sum+=rec[i][j];
    if((sum%2)==0) {judge[p]=0;num++;return;}}
}

main(){
    int num=10000,sam[ROW][COL]={{1,0,0},{1,0,1}},count=0,detect_num=0;//num为传输数据数目，sam为传输数据100101,count为真实错误计数，detect_num为识别错误计数
int send[num][ROW+1][COL+1]={0},error[num],detect[num];//send数组为10000个传输的码组,error为判断，1表示未出错 detect为识别到的错误
for(int i=0;i<num;i++) {error[i]=1,detect[i]=1;}
for(int i=0;i<num;i++)
for(int j=0;j<ROW;j++)
    for(int k=0;k<COL;k++){send[i][j][k]=sam[j][k];}
for (int i=0;i<num;i++) {send[i][0][COL]=0;send[i][1][COL]=1;send[i][ROW][0]=1;send[i][ROW][1]=1;send[i][ROW][2]=0;}
srand((unsigned)time(NULL));
for(int i=0;i<num;i++)//按照5%的概率发生传输错误
    for(int j=0;j<ROW;j++)
        for(int k=0;k<COL;k++)
{
    int x=rand()%100;
    if(x<=4) send[i][j][k]=(send[i][j][k]+1)%2;
}
for(int i=0;i<num;i++)
    for(int j=0;j<ROW;j++)
        for(int k=0;k<COL;k++)
        if(send[i][j][k]!=sam[j][k]){error[i]=0;count++;break;}

printf("传输错误数为：%d\n",count);
printf("传输错误率为：%.2f%%\n",100*float(count)/num);
for(int i=0;i<num;i++){
    Detect(send[i],detect,detect_num,i);
}
printf("识别到的错误数为：%d\n",detect_num);
printf("识别到的错误率为：%.2f%%\n",100*float(detect_num)/num);

printf("\n检错率为：%.2f%%\n",100*float(detect_num)/count);
}
