/*������ʵ���������ɶ���ʽ��ģ�⴫��10000
�������������������CRC�������
�ٶ���������Ϊ6λ 100101��ÿ���źŷ����������ĸ���Ϊ5%����ÿλ�������
���ɶ���ʽ���������
by Haoyu Li*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 24

void CRCCoding(int r[], int g[], int n_pro,int n_g);//rΪ��ʽ��gΪ��ʽ��n_proΪ�ӳ���ĳ���,n_gΪ���ɶ���ʽ����
void ExamCoding(int f[], int g[], int &sign,int n_pro,int n_g);
float test(int g[], int n_g,int error_poss);

void CRCCoding( int r[], int g[], int n_pro,int n_g){
int q[n_pro]={0};//��ʼ����ʽ
int first=0;
    while(r[first]==0){first++;}
if((n_pro-first)<n_g) return;
    else {q[first+n_g-1]=1;
    for(int i=0;i<n_g;i++) r[i+first]=(r[i+first]+g[i])%2;
    CRCCoding(r,g,n_pro,n_g);}}

void ExamCoding(int f[], int g[], int &sign,int n_pro,int n_g){
    sign=1;
    CRCCoding(f,g,n_pro,n_g);
    //for(int i=0;i<n_pro;i++) printf("%d ",f[i]);putchar('\n');
    for(int i=0;i<n_pro;i++)if(f[i]!=0){sign=0;break;}
    //printf("%d ",sign);
}
float test(int g[],int n_g,int error_poss){
int num=15000,sam[N]={1,0,0,1,0,1,1,1,1,1,0,0,1,1,1,0,1,0,0,1,1,1,0,0},count=0,detect_num=0;
clock_t start,finish;
double total_time=0;
int n_pro,*r,*f;
n_pro=N+n_g-1;
f=(int *)malloc(n_pro*sizeof(int));
r=(int *)malloc(n_pro*sizeof(int));
for(int i=0;i<N;i++){f[i]=sam[i];r[i]=sam[i];}
for(int i=N;i<n_pro;i++){f[i]=0;r[i]=0;}
CRCCoding(r,g,n_pro,n_g);
for(int i=N;i<n_pro;i++)f[i]=r[i];
//printf("\nCRC���������Ϊ��\n");
//for(int i=0;i<n_pro;i++)printf("%d ",f[i]);

int send[num][32]={0},error[num],detect[num];
for(int i=0;i<num;i++) {error[i]=1,detect[i]=1;
for(int j=0;j<n_pro;j++)send[i][j]=f[j];
}
//srand((unsigned)time(NULL));
for(int i=0;i<num;i++)//����5%�ĸ��ʷ����������
    for(int j=0;j<N;j++)
{
    int x=rand()%100;
    if(x<=error_poss) send[i][j]=(send[i][j]+1)%2;
}
for(int i=0;i<num;i++)
    {
    for(int j=0;j<N;j++)
        if(send[i][j]!=sam[j]){error[i]=0;count++;break;}
}

//printf("\n���������Ϊ��%d\n",count);
//printf("���������Ϊ��%.2f%%\n",100*float(count)/num);
start=clock();
for(int i=0;i<num;i++) ExamCoding(send[i],g,detect[i],n_pro,n_g);
finish=clock();
total_time=((double)(finish-start))/CLK_TCK;
//for(int i=0;i<num;i++) printf("%d ",detect[i]);
for(int i=0;i<num;i++) if((detect[i]==0)&&(error[i]==0)) detect_num++;
/*printf("ʶ�𵽵Ĵ�����Ϊ��%d\n",detect_num);
printf("ʶ�𵽵Ĵ�����Ϊ��%.2f%%\n",100*float(detect_num)/num);
printf("\n�����Ϊ��%.2f%%\n",100*float(detect_num)/count);
printf("The time is: %f s",total_time);*/
return 100*float(detect_num)/count;
}

main(){
int n_g,*g=NULL;
printf("���������ɶ���ʽ�������г���:");
scanf("%d",&n_g);
g=(int *)malloc(n_g*sizeof(int));
printf("���������ɶ���ʽ��������:\n");
for(int i=0;i<n_g;i++){
    printf("�������%dλ:",i+1);scanf("%d",&g[i]);
}
srand((unsigned)time(NULL));
float result[3]={0};
for(int j=0;j<8;j++){
for(int i=0;i<3;i++) result[i]=test(g,n_g,4+j*5);
float sum=0;
for(int i=0;i<3;i++) sum+=result[i];
printf("\nkennegxingwei:%d  ",(j+1)*5);
printf("       pinjunwei%.2f%%",sum/3);
}
}
