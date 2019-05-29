/*������ģ��7-3ѭ����ļ���������
Ĭ�����ɶ���ʽΪx^4+x^2+x+1
�������Ϣ����Ϊ101 �ŵ�������5%
by Haoyu Li*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

void XunhuanCoding(int a[]);
void DeCoding(int a[], int &sign);
void test(int sam[],int send[],int &if_correct);
float testrun(int error_poss);

void XunhuanCoding(int a[]){
int i=N;
a[i]=(a[0]+a[1])%2;
a[i+1]=(a[1]+a[2])%2;
a[i+2]=(a[0]+a[1]+a[2])%2;
a[i+3]=(a[0]+a[2])%2;
}

void DeCoding(int a[],int &sign){
int H[7][4]={{1,0,1,1},{1,1,1,0},{0,1,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int s_sam[8][4]={{0,1,0,1},{1,0,0,1},{1,1,0,0},{1,0,1,0},{0,1,1,0},{0,0,1,1},{1,1,0,1},{1,1,1,1}};
int r[8][7]={{1,1,0,0,0,0,0},{0,1,1,0,0,0,0},{1,0,1,0,0,0,0},{1,0,0,0,0,0,1},{0,1,0,1,0,0,0},{1,0,0,1,0,0,0},{1,0,1,0,0,0,1},{1,0,0,0,1,0,0}};
int s[4]={0};
for(int i=0;i<4;i++)
{for(int j=0;j<7;j++) s[i]+=a[j]*H[j][i];
s[i]=s[i]%2;
}
sign=1;//signΪ����־
for(int i=0;i<4;i++) if(s[i]==1){sign=0;break;}
if(sign==1) return;
int num;
for(int i=0;i<7;i++){
    int p=1;
    for(int j=0;j<4;j++) p=p&&(H[i][j]==s[j]);
    if(p==1) {num=i;a[num]=(a[num]+1)%2;return;}
}
for(int i=0;i<8;i++)
    {int p=1;
    for(int j=0;j<4;j++) p=p&&(s_sam[i][j]==s[j]);
    if(p==1) {num=i;break;}}
for(int i=0;i<7;i++)
    a[i]=(a[i]+r[num][i])%2;
}

void test(int sam[],int send[], int &if_correct){
    if_correct=1; //�Ƿ�������ȷ
    for(int i=0;i<7;i++) if(sam[i]!=send[i]){if_correct=0;break;}
}

float testrun(int error_poss){
int num=15000,sam[7]={1,0,1},realerror=0,detect_num=0,right_num=0,correct_num=0;
//15000����Ϣ�룬realerrorΪʵ�ʴ��������Ŀ��detect_numΪ�����Ĵ�����Ŀ��right_numΪ�������ȷ��Ŀ��correct_num����������ȷ��Ŀ
int send[num][7],real_error[num],detect_error[num],right[num],error_count[num];
XunhuanCoding(sam);
//printf("ѭ�������Ϊ��\n");
//for(int i=0;i<7;i++)printf("%d ",sam[i]);
for(int i=0;i<num;i++)
{ for(int j=0;j<7;j++) send[i][j]=sam[j];
real_error[i]=1;
detect_error[i]=1;
right[i]=1;
error_count[i]=0;
}
//srand((unsigned)time(NULL));
for(int i=0;i<num;i++)//����5%�ĸ��ʷ����������
    for(int j=0;j<7;j++)
{
    int x=rand()%100;
    if(x<=error_poss) send[i][j]=(send[i][j]+1)%2;
}
 for(int i=0;i<num;i++)
    {
    for(int j=0;j<7;j++)
        if(send[i][j]!=sam[j]){real_error[i]=0;realerror++;break;}
}
for(int i=0;i<num;i++)
    for(int j=0;j<7;j++)
    if(send[i][j]!=sam[j]) error_count[i]++;
//printf("\n ���������Ϊ��%d\n",realerror);
//printf("���������Ϊ��%.2f%%\n",100*float(realerror)/num);
for(int i=0;i<num;i++) DeCoding(send[i],detect_error[i]);
for(int i=0;i<num;i++) if(detect_error[i]==0) detect_num++;
//printf("\nʶ�𵽵Ĵ�����Ϊ��%d\n",detect_num);
//printf("ʶ�𵽵Ĵ�����Ϊ��%.2f%%\n",100*float(detect_num)/num);
//printf("\n�����Ϊ��%.2f%%\n",100*float(detect_num)/realerror);
for(int i=0;i<num;i++) test(sam,send[i],right[i]);
for(int i=0;i<num;i++) if(right[i]==1) right_num++;
//printf("\n��ȷ������ĿΪ��%d\n",right_num);
//printf("������ȷ��Ϊ��%.2f%%\n",100*float(right_num)/num);
for(int i=0;i<num;i++) if((real_error[i]==0)&&(right[i]==1)) correct_num++;
//printf("\n�����Ĵ�������Ϊ��%d\n",correct_num);
//printf("���������Ϊ��%.2f%%\n",100*float(correct_num)/realerror);
int two_error=0,correct_two_number=0;
for(int i=0;i<num;i++) {
        if(error_count[i]==2) two_error++;
        if((error_count[i]==2)&&(right[i]==1)) correct_two_number++;
}
//printf("����2λ����%d\n",two_error);
//printf("����2λ����%d\n",correct_two_number);
//printf("2λ������Ϊ��%.2f%%\n",100*float(correct_two_number)/two_error);
return 100*float(correct_num)/realerror;
}

main(){
float result[3]={0};
    srand((unsigned)time(NULL));
for(int j=0;j<7;j++){
for(int i=0;i<3;i++) result[i]=testrun(4+j*5);
float sum=0;
for(int i=0;i<3;i++) sum+=result[i];
printf("\nkennegxingwei:%d  ",(j+1)*5);
printf("       pinjunwei%.2f%%",sum/3);}

}
