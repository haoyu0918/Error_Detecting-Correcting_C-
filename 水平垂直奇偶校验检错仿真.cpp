/*������ģ�ⴹֱˮƽ��żУ��ļ������
���������Ϊ100��101 2��һ�鴫�䣬���зֱ������У��
�ٶ���Ϣ����������Ϊ5%
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
    int num=10000,sam[ROW][COL]={{1,0,0},{1,0,1}},count=0,detect_num=0;//numΪ����������Ŀ��samΪ��������100101,countΪ��ʵ���������detect_numΪʶ��������
int send[num][ROW+1][COL+1]={0},error[num],detect[num];//send����Ϊ10000�����������,errorΪ�жϣ�1��ʾδ���� detectΪʶ�𵽵Ĵ���
for(int i=0;i<num;i++) {error[i]=1,detect[i]=1;}
for(int i=0;i<num;i++)
for(int j=0;j<ROW;j++)
    for(int k=0;k<COL;k++){send[i][j][k]=sam[j][k];}
for (int i=0;i<num;i++) {send[i][0][COL]=0;send[i][1][COL]=1;send[i][ROW][0]=1;send[i][ROW][1]=1;send[i][ROW][2]=0;}
srand((unsigned)time(NULL));
for(int i=0;i<num;i++)//����5%�ĸ��ʷ����������
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

printf("���������Ϊ��%d\n",count);
printf("���������Ϊ��%.2f%%\n",100*float(count)/num);
for(int i=0;i<num;i++){
    Detect(send[i],detect,detect_num,i);
}
printf("ʶ�𵽵Ĵ�����Ϊ��%d\n",detect_num);
printf("ʶ�𵽵Ĵ�����Ϊ��%.2f%%\n",100*float(detect_num)/num);

printf("\n�����Ϊ��%.2f%%\n",100*float(detect_num)/count);
}
