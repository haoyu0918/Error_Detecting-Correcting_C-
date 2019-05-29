/*������ԣ�7,4���������뷽�����в���
�ú�������Ծ���1λ�������
�÷���ֻ���ڲ�����֪����һλ���������
By Haoyu Li*/
#include <stdio.h>
#include <stdlib.h>
#define N 4

void HanmingCoding(int a[]);
void DeCoding(int a[]);
void HanmingCoding(int a[]){
int i=N;
a[i]=(a[0]+a[1]+a[2])%2;
a[i+1]=(a[1]+a[2]+a[3])%2;
a[i+2]=(a[0]+a[1]+a[3])%2;
}

void DeCoding(int a[]){
int H[7][3]={{1,0,1},{1,1,1},{1,1,0},{0,1,1},{1,0,0},{0,1,0},{0,0,1}};
int s[3]={0};
for(int i=0;i<3;i++)
{for(int j=0;j<7;j++) s[i]+=a[j]*H[j][i];
s[i]=s[i]%2;
}
for(int i=0;i<3;i++)printf("%d",s[i]);
int sign=1;//signΪ����־
for(int i=0;i<3;i++) if(s[i]==1){sign=0;break;}
if(sign==1) {printf("û�д���\n");return;}
int num;
for(int i=0;i<7;i++){
    int p=1;
    for(int j=0;j<3;j++) p=p&&(H[i][j]==s[j]);
    if(p==1) {num=i;break;}
}
printf("\n��%dλ����",num+1);
a[num]=(a[num]+1)%2;}

main(){
int send[7];
printf("��������Ϣ���飨4λ��:\n");
for(int i=0;i<4;i++)
{
    printf("��%dλΪ��",i);scanf("%d",&send[i]);
}
HanmingCoding(send);
printf("���������Ϊ��\n");
for(int i=0;i<7;i++)
    printf("%d ",send[i]);
int error;
printf("\n���������λ��(0��ʾ�޴���):");scanf("%d",&error);
if(error!=0) send[error-1]=(send[error-1]+1)%2;
printf("������Ϊ��\n");
for(int i=0;i<7;i++)printf("%d ",send[i]);
DeCoding(send);
printf("�����Ϊ��\n");
for(int i=0;i<7;i++)printf("%d ",send[i]);}
