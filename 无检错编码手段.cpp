/*����������ģ���޼���������µĴ���
�ٶ�����̶������ĸ�������
ÿ������λ�����������ĸ���Ϊ5%
ģ����ն����
2019/4/26 by Haoyu Li*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
main(){
int num=10000,sam[N]={1,0,0,1,0,1},count=0;//numΪ����������Ŀ��samΪ��������100101,countΪ�������
int send[num][N]={0},error[num];//send����Ϊ10000�����������,errorΪ�жϣ�1��ʾδ����
for(int i=0;i<num;i++) error[i]=1;
for(int i=0;i<num;i++)
for(int j=0;j<N;j++)send[i][j]=sam[j];
srand((unsigned)time(NULL));
for(int i=0;i<num;i++)//����5%�ĸ��ʷ����������
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
printf("���������Ϊ��%d\n",count);
printf("���������Ϊ��%.2f%%",100*float(count)/num);}
