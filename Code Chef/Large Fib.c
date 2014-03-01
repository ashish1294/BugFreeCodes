#include<stdio.h>
#include<string.h>
char* add(char* num1, char*num2,char*res)
{
    char* pa = num1;
    char* pb = num2;
    char a[1100],b[1100],sum[1100];
    int ac=0,bc=0,sc=0,i,reminder;
    while(*pa)
        a[ac++] = *pa++ - 48;
    while(*pb)
         b[bc++] = *pb++ - 48;

    if(ac<bc)
    {
         for(i = ac;i > 0;i--)
         {
             sum[sc++]= ((a[i-1] + b[--bc]) + reminder)%10;
             reminder = ((a[i-1] + b[bc]) + reminder)/10;
         }
         while(bc>0)
         {
             sum[sc++] = b[--bc] + reminder;
             reminder = 0;
         }
    }
    else
    {
         for(i = bc;i > 0;i--)
         {
             sum[sc++]= ((b[i-1] + a[--ac]) + reminder)%10;
            reminder = ((b[i-1] + a[ac]) + reminder)/10;
         }
         if(ac==0 && reminder==1)
             sum[sc++] = reminder;
         while(ac>0)
         {
            sum[sc++] = a[--ac] + reminder;
                reminder = 0;
         }
    }
    res=sum;
    return sum;
}
int main()
{
    int n,i;
    char arr[5000][1100];
    strcpy(arr[0],"0");
    strcpy(arr[1],"1");
    for (i=2;i<500;i++)
    {
        add(arr[i-2],arr[i-1],arr[i]);
    }
    while(1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        else
            puts(arr[n]);
        printf("\n");
    }
}
