#include<stdio.h>
#include<string.h>
int main()
{
    long int t,k,j,ck;
    char s[200000],i,ans[200000];
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%s%ld",s,&k);
        ck=k;
        int l=strlen(s);
        if(k>=l)
        {
            printf("\n");
            continue;
        }
        else if(k==0)
        {
            printf("%s\n",s);
            continue;
        }
        for(i='0';i<='9' && k>0 ;i++)
        {
            for(j=0;j<l && k>0 ;j++)
            {
                if(s[j]==i)
                {
                    k--;
                    s[j]='*';
                }
            }
        }
        k=0;
        for(j=0;j<l && k<(l-ck);j++)
            if(s[j]>='0' && s[j]<='9')
            {
                printf("%c",s[j]);
                k++;
            }
        if(t!=0)
        printf("\n",ans);
    }
    return 0;
}
