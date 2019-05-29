/*����������ģ���޼���������µĴ���
�ٶ�����̶������ĸ�������
ÿ������λ�����������ĸ���Ϊ5%
ģ����ն����
������֪ �����ã�11,6�����Է��������
���Ǻ����� 5������λ ����
 by Haoyu Li*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define r 5

void HanmingCoding(int a[]);
void ExamHanming(int a[]);
void testrun();

void HanmingCoding(int a[]){//����(11,6)��������
a[N]=(a[0]+a[4]+a[5])%2;
a[N+1]=(a[0]+a[1]+a[3])%2;
a[N+2]=(a[2]+a[3]+a[5])%2;
a[N+3]=(a[1]+a[2]+a[4])%2;
a[N+4]=(a[1]+a[3]+a[5])%2;
}

void ExamHanming(int a[],int &sign){//����У�����H����У��
    sign=1;
int s[r]={0};
s[0]=(a[N]+a[0]+a[4]+a[5])%2;
s[1]=(a[0]+a[1]+a[3]+a[N+1])%2;
s[2]=(a[2]+a[3]+a[5]+a[N+2])%2;
s[3]=(a[1]+a[2]+a[4]+a[N+3])%2;
s[4]=(a[1]+a[3]+a[5]+a[N+4])%2;
for(int i=0;i<r;i++) if(s[i]!=0) {sign=0;return;}}

void testrun(){
int num=20000,sam[N]={1,0,0,1,0,1},count=0,detect_num=0;//numΪ����������Ŀ��samΪ��������100101,countΪ��ʵ���������detect_numΪʶ��������
int send[num][N+r]={0},error[num],detect[num];
int sam_pro[N+r];
for(int i=0;i<num;i++) {error[i]=1,detect[i]=1;}
for(int i=0;i<N;i++)sam_pro[i]=sam[i];
HanmingCoding(sam_pro);//�õ���������
printf("\n��������Ϊ��");
for(int i=0;i<N+r;i++) printf("%d ",sam_pro[i]);
for(int i=0;i<num;i++)
    for(int j=0;j<N+r;j++)send[i][j]=sam_pro[j];

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
printf("\n���������Ϊ��%d\n",count);
printf("���������Ϊ��%.2f%%",100*float(count)/num);
for(int i=0;i<num;i++) ExamHanming(send[i],detect[i]);
for(int i=0;i<num;i++) if(detect[i]==0) detect_num++;
printf("\nʶ�𵽵Ĵ�����Ϊ��%d\n",detect_num);
printf("ʶ�𵽵Ĵ�����Ϊ��%.2f%%\n",100*float(detect_num)/num);

printf("\n�����Ϊ��%.2f%%\n",100*float(detect_num)/count);
}

main(){
srand((unsigned)time(NULL));
for(int i=0;i<5;i++) testrun();}
