/*������ʵ��23-12������ļ������������
����������� �ŵ�������5%
by Haoyu Li*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 12

void GaolaiCoding(int a[]);
void get_s(int a[],int s[]);//aΪ�����룬sΪ���ɵİ���ʽ
void DeCoding(int a[], int &sign,int (*s_sam)[11],int (*error_pic)[23]);
void test(int sam[],int send[],int &if_correct);
float testrun(int error_poss);

void GaolaiCoding(int a[]){
a[N]=(a[0]+a[3]+a[4]+a[5]+a[9]+a[10]+a[11])%2;
a[N+1]=(a[0]+a[2]+a[4]+a[5]+a[7]+a[8]+a[11])%2;
a[N+2]=(a[0]+a[2]+a[3]+a[5]+a[6]+a[8]+a[10])%2;
a[N+3]=(a[0]+a[2]+a[3]+a[4]+a[6]+a[7]+a[9])%2;
a[N+4]=(a[0]+a[1]+a[4]+a[5]+a[6]+a[8]+a[9])%2;
a[N+5]=(a[0]+a[1]+a[3]+a[5]+a[6]+a[7]+a[11])%2;
a[N+6]=(a[0]+a[1]+a[3]+a[4]+a[7]+a[8]+a[10])%2;
a[N+7]=(a[0]+a[1]+a[2]+a[5]+a[7]+a[9]+a[10])%2;
a[N+8]=(a[0]+a[1]+a[2]+a[4]+a[6]+a[10]+a[11])%2;
a[N+9]=(a[0]+a[1]+a[2]+a[3]+a[8]+a[9]+a[11])%2;
a[N+10]=(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11])%2;
}
void get_s(int a[],int s[]){
s[0]=(a[0]+a[3]+a[4]+a[5]+a[9]+a[10]+a[11]+a[N])%2;
s[1]=(a[0]+a[2]+a[4]+a[5]+a[7]+a[8]+a[11]+a[N+1])%2;
s[2]=(a[0]+a[2]+a[3]+a[5]+a[6]+a[8]+a[10]+a[N+2])%2;
s[3]=(a[0]+a[2]+a[3]+a[4]+a[6]+a[7]+a[9]+a[N+3])%2;
s[4]=(a[0]+a[1]+a[4]+a[5]+a[6]+a[8]+a[9]+a[N+4])%2;
s[5]=(a[0]+a[1]+a[3]+a[5]+a[6]+a[7]+a[11]+a[N+5])%2;
s[6]=(a[0]+a[1]+a[3]+a[4]+a[7]+a[8]+a[10]+a[N+6])%2;
s[7]=(a[0]+a[1]+a[2]+a[5]+a[7]+a[9]+a[10]+a[N+7])%2;
s[8]=(a[0]+a[1]+a[2]+a[4]+a[6]+a[10]+a[11]+a[N+8])%2;
s[9]=(a[0]+a[1]+a[2]+a[3]+a[8]+a[9]+a[11]+a[N+9])%2;
s[10]=(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[N+10])%2;
}

void DeCoding(int a[], int &sign,int (*s_sam)[11],int (*error_pic)[23]){
int s[11]={0};
sign=1;
get_s(a,s);
//for(int i=0;i<11;i++)printf("%d ",s[i]);
//printf("\n");
for(int i=0;i<11;i++) if(s[i]==1){sign=0;break;}
if(sign==1) return;
int num=0;
for(int i=0;i<2047;i++)
    {int p=1;
    for(int j=0;j<11;j++) p=p&&(s_sam[i][j]==s[j]);
    if(p==1) {num=i;break;}}
//printf("num=%d\n",num);
for(int i=0;i<23;i++)
    a[i]=(a[i]+error_pic[num][i])%2;
}
void test(int sam[],int send[], int &if_correct){
    if_correct=1; //�Ƿ�������ȷ
    for(int i=0;i<23;i++) if(sam[i]!=send[i]){if_correct=0;break;}
}

float testrun(int error_poss){
int s_sam[2047][11];//r_sam�洢���еİ���ʽ
int error_pic[2047][23]={0};//error_pic�洢���еĴ���ͼ��
int temp[23]={0};//�������еĴ���ͼ��
int pos=0;
for(temp[0]=0;temp[0]<2;temp[0]++)
    for(temp[1]=0;temp[1]<2;temp[1]++)
    for(temp[2]=0;temp[2]<2;temp[2]++)
    for(temp[3]=0;temp[3]<2;temp[3]++)
    for(temp[4]=0;temp[4]<2;temp[4]++)
    for(temp[5]=0;temp[5]<2;temp[5]++)
    for(temp[6]=0;temp[6]<2;temp[6]++)
    for(temp[7]=0;temp[7]<2;temp[7]++)
    for(temp[8]=0;temp[8]<2;temp[8]++)
    for(temp[9]=0;temp[9]<2;temp[9]++)
    for(temp[10]=0;temp[10]<2;temp[10]++)
    for(temp[11]=0;temp[11]<2;temp[11]++)
    for(temp[12]=0;temp[12]<2;temp[12]++)
    for(temp[13]=0;temp[13]<2;temp[13]++)
    for(temp[14]=0;temp[14]<2;temp[14]++)
    for(temp[15]=0;temp[15]<2;temp[15]++)
    for(temp[16]=0;temp[16]<2;temp[16]++)
    for(temp[17]=0;temp[17]<2;temp[17]++)
    for(temp[18]=0;temp[18]<2;temp[18]++)
    for(temp[19]=0;temp[19]<2;temp[19]++)
    for(temp[20]=0;temp[20]<2;temp[20]++)
    for(temp[21]=0;temp[21]<2;temp[21]++)
    for(temp[22]=0;temp[22]<2;temp[22]++)
{
    int one_count=0;
    for(int i=0;i<23;i++) if(temp[i]==1)one_count++;
    if((one_count>=1)&&(one_count<=3)) {
     for(int j=0;j<23;j++) error_pic[pos][j]=temp[j];
     get_s(error_pic[pos],s_sam[pos]);
     pos++;
    }
}

int num=15000,sam[23]={1,0,1,1,1,0,0,0,1,1,0,1},realerror=0,detect_num=0,right_num=0,correct_num=0;
//15000����Ϣ�룬realerrorΪʵ�ʴ��������Ŀ��detect_numΪ�����Ĵ�����Ŀ��right_numΪ�������ȷ��Ŀ��correct_num����������ȷ��Ŀ
int send[num][23],real_error[num],detect_error[num],right[num],error_count[num];
GaolaiCoding(sam);
//printf("\nѭ�������Ϊ��\n");
//for(int i=0;i<23;i++)printf("%d ",sam[i]);
for(int i=0;i<num;i++)
{ for(int j=0;j<23;j++) send[i][j]=sam[j];
real_error[i]=1;
detect_error[i]=1;
right[i]=1;
error_count[i]=0;
}
//srand((unsigned)time(NULL));
for(int i=0;i<num;i++)//����5%�ĸ��ʷ����������
    for(int j=0;j<23;j++)
{
    int x=rand()%100;
    if(x<=error_poss) send[i][j]=(send[i][j]+1)%2;
}
 for(int i=0;i<num;i++)
    {
    for(int j=0;j<23;j++)
        if(send[i][j]!=sam[j]){real_error[i]=0;realerror++;break;}
}
for(int i=0;i<num;i++)
    for(int j=0;j<23;j++)
    if(send[i][j]!=sam[j]) error_count[i]++;
//printf("\n ���������Ϊ��%d\n",realerror);
//printf("���������Ϊ��%.2f%%\n",100*float(realerror)/num);
for(int i=0;i<num;i++) DeCoding(send[i],detect_error[i],s_sam,error_pic);
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
int three_error=0,correct_three_number=0;
for(int i=0;i<num;i++) {
        if((error_count[i]<=3)&&(error_count[i]>=1)) three_error++;
        if((error_count[i]<=3)&&(error_count[i]>=1)&&(right[i]==1)) correct_three_number++;
}
printf("\n����3λ���´���%d\n",three_error);
printf("����3λ���´���%d\n",correct_three_number);
printf("---------------------------------------------------------------------------------------");
return 100*float(correct_num)/realerror;}
//printf("3λ������Ϊ��%.2f%%\n",100*float(correct_two_number)/two_error);}

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

