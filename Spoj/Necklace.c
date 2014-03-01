#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,arr[500],j;
    scanf("%d",&t);
    char str[2000];
    while(t--)
    {
        for(i=0;i<500;i++)
            arr[i]=0;
        scanf("%s",str);
        for(i=0;i<strlen(str);i++)
        {
            arr[((int)str[i])]++;
        }
        for(i=45;i<130;i++)
        {
            if(arr[i]!=0)
            {
                if(arr[i]%2!=0)
                {
                    for(j=0;j<arr[i];j++)
                        printf("%c",((char)i));
                    arr[i]=0;
                }
            }
        }
        for(i=45;i<130;i++)
        {
            if(arr[i]!=0)
            {
                if(arr[i]%2==0)
                {
                    for(j=0;j<arr[i];j++)
                        printf("%c",((char)i));
                    arr[i]=0;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
