#include<stdio.h>


int main(){

    int a=3;
    int b=1;
    int ar[10];
    scanf("%d",&ar[0]);
    scanf("%d",&ar[1]);
    scanf("%d",&ar[2]);
    scanf("%d",&ar[3]);
    scanf("%d",&ar[4]);
    scanf("%d",&ar[5]);
    scanf("%d",&ar[6]);
    scanf("%d",&ar[7]);
    scanf("%d",&ar[8]);
    scanf("%d",&ar[9]);

    int sum=0;

    sum=sum+ar[0];
    sum=sum+ar[1];
    sum=sum+ar[2];
    sum=sum+ar[3];
    sum=sum+ar[4];
    sum=sum+ar[5];
    sum=sum+ar[6];
    sum=sum+ar[7];
    sum=sum+ar[8];
    sum=sum+ar[9];

    printf("sum = %d\n",sum);


    return 0;
}
