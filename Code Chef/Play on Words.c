#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int t;
    long int n,i;
    int arr[100001][2];
    char str[1000];
    scanf("%d",&t);
    while(t--)
    {
        fflush(stdin);
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        {
            fflush(stdin);
            scanf("%s",str);
            arr[i][0]=(int) str[0];
            arr[i][1]=(int) str[strlen(str)-1];
        }
    }
    return 0;
}
