/*������ģ��һλˮƽ��żУ��λ�ļ������
����̶����ĸ�������100101 ���һ����У��λ0
�ٶ���Ϣ����ÿλ��������ͬ����Ϊ5%
У��λû�з�������
2019/4/26 by Haoyu Li*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
main(){
int num=10000,sam[N]={1,0,0,1,0,1},count=0,detect_num=0;//numΪ����������Ŀ��samΪ��������100101,countΪ��ʵ���������detect_numΪʶ��������
int send[num][N+1]={0},error[num],detect[num];//send����Ϊ10000�����������,errorΪ�жϣ�1��ʾδ���� detectΪʶ�𵽵Ĵ���
for(int i=0;i<num;i++) {error[i]=1,detect[i]=1;}
for(int i=0;i<num;i++)
for(int j=0;j<N;j++){send[i][j]=sam[j];send[i][N]=0;}
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

printf("���������Ϊ��%d\n",count);
printf("���������Ϊ��%.2f%%\n",100*float(count)/num);
for(int i=0;i<num;i++){
    int sum=0;
    for(int j=0;j<N+1;j++) sum+=send[i][j];
    if((sum%2)==0){detect[i]=0;detect_num++;}
}
printf("ʶ�𵽵Ĵ�����Ϊ��%d\n",detect_num);
printf("ʶ�𵽵Ĵ�����Ϊ��%.2f%%\n",100*float(detect_num)/num);

printf("\n�����Ϊ��%.2f%%\n",100*float(detect_num)/count);
/*for(int i=0;i<num;i++)printf("%d ",error[i]);
putchar('\n');
for(int i=0;i<num;i++)printf("%d ",detect[i]);*/
}

