#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[25];
int findpos()
{
    int i = strlen(s);
        for(i=i-1;i>0;i--)
        {
            if(s[i]<s[i-1])
            {
                i--;
                return i;
            }
        }
        if(i==0)
            return -1;
}
void ss(int pos)
{
    int arr[255]={0};
    int t= strlen(s),i,k;
    for(i=pos;i<t;i++)
    {
        arr[(int)s[i]]++;
    }
    int j=250;
    while(arr[j]==0 && j>5)
        j--;
    for(i=pos;i<t;)
    {
        if(i==strlen(s))
            break;
        if(j<10)
            break;
        for(k=0;k<arr[j];k++)
        {
            s[i]=(char)(j);
            i++;
        }
        j--;
        while(arr[j]==0 && j>5)
            j--;
    }
}
int main()
{
    int t;
    long long int n,n1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        long long int ans=1;
        int a = findpos();
        int count=0;
        while(a!=-1)
        {
            int pp=strlen(s)-1;
            if(s[a]<=s[pp])
            {
                while(s[pp]>=s[a])
                    pp--;
            }
            char temp=s[a];
            s[a]=s[pp];
            s[pp]=temp;
            ss(a+1);
            ans++;
            a=findpos();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
