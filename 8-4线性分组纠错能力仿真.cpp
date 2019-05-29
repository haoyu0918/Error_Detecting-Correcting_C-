/*本代码对8-4线性分组码进行传输仿真
传输码1001，信道误码率5%
by Haoyu Li*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

void HanmingCoding(int a[]);
void DeCoding(int a[], int &sign);
void test(int sam[],int send[],int &if_correct);
void testrun();

void HanmingCoding(int a[]){
int i=N;
a[i]=(a[0]+a[2]+a[3])%2;
a[i+1]=(a[0]+a[1]+a[3])%2;
a[i+2]=(a[0]+a[1]+a[2])%2;
a[i+3]=(a[1]+a[2]+a[3])%2;

}
void DeCoding(int a[],int &sign){
int H[8][4]={{1,1,1,0},{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int r[7][8]={{1,1,0,0,0,0,0,0},{1,0,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,0,1,0,0,0,0},{0,0,1,1,0,0,0,0},{1,0,0,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
int s_sam[7][4]={{1,0,0,1},{0,1,0,1},{1,1,0,0},{1,0,1,0},{0,1,1,0},{0,0,1,1},{1,1,1,1}};
int s[4]={0};
for(int i=0;i<4;i++)
{for(int j=0;j<8;j++) s[i]+=a[j]*H[j][i];
s[i]=s[i]%2;
}
sign=1;//sign为检错标志
for(int i=0;i<4;i++) if(s[i]==1){sign=0;break;}
if(sign==1) return;
int num;
for(int i=0;i<8;i++){
    int p=1;
    for(int j=0;j<4;j++) p=p&&(H[i][j]==s[j]);
    if(p==1) {num=i;a[num]=(a[num]+1)%2;return;}
}
for(int i=0;i<7;i++)
    {int p=1;
    for(int j=0;j<4;j++) p=p&&(s_sam[i][j]==s[j]);
    if(p==1) {num=i;break;}}
for(int i=0;i<8;i++)
    a[i]=(a[i]+r[num][i])%2;
}

void test(int sam[],int send[], int &if_correct){
    if_correct=1; //是否译码正确
    for(int i=0;i<8;i++) if(sam[i]!=send[i]){if_correct=0;break;}
}

void testrun(){
int num=15000,sam[8]={1,0,0,1},realerror=0,detect_num=0,right_num=0,correct_num=0;
//15000组信息码，realerror为实际传输错误数目，detect_num为检测出的错误数目，right_num为译码后正确数目，correct_num错码纠错后正确数目
int send[num][8],real_error[num],detect_error[num],right[num],error_count[num]={0};
HanmingCoding(sam);
printf("汉明编码后为：\n");
for(int i=0;i<8;i++)printf("%d ",sam[i]);
for(int i=0;i<num;i++)
{ for(int j=0;j<8;j++) send[i][j]=sam[j];
real_error[i]=1;
detect_error[i]=1;
right[i]=1;
error_count[i]=0;
}
//srand((unsigned)time(NULL));
for(int i=0;i<num;i++)//按照5%的概率发生传输错误
    for(int j=0;j<8;j++)
{
    int x=rand()%100;
    if(x<=4) send[i][j]=(send[i][j]+1)%2;
}
 for(int i=0;i<num;i++)
    {
    for(int j=0;j<8;j++)
        if(send[i][j]!=sam[j]){real_error[i]=0;realerror++;break;}
}
for(int i=0;i<num;i++)
    for(int j=0;j<8;j++)
    if(send[i][j]!=sam[j]) error_count[i]++;
printf("\n 传输错误数为：%d\n",realerror);
printf("传输错误率为：%.2f%%\n",100*float(realerror)/num);
for(int i=0;i<num;i++) DeCoding(send[i],detect_error[i]);
for(int i=0;i<num;i++) if(detect_error[i]==0) detect_num++;
printf("\n识别到的错误数为：%d\n",detect_num);
printf("识别到的错误率为：%.2f%%\n",100*float(detect_num)/num);
printf("\n检错率为：%.2f%%\n",100*float(detect_num)/realerror);
for(int i=0;i<num;i++) test(sam,send[i],right[i]);
for(int i=0;i<num;i++) if(right[i]==1) right_num++;
printf("\n正确译码数目为：%d\n",right_num);
printf("传输正确率为：%.2f%%\n",100*float(right_num)/num);
for(int i=0;i<num;i++) if((real_error[i]==0)&&(right[i]==1)) correct_num++;
printf("\n纠正的错误码数为：%d\n",correct_num);
printf("错码纠正率为：%.2f%%\n",100*float(correct_num)/realerror);
int two_error=0,correct_two_number=0;
for(int i=0;i<num;i++) {
        if(error_count[i]==2) two_error++;
        if((error_count[i]==2)&&(right[i]==1)) correct_two_number++;
}
printf("发生2位错误：%d\n",two_error);
printf("纠正2位错误：%d\n",correct_two_number);
printf("2位纠正率为：%.2f%%\n",100*float(correct_two_number)/two_error);
}

main(){
srand((unsigned)time(NULL));
for(int i=0;i<3;i++) testrun();}
