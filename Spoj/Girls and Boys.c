#include<stdio.h>
int main()
{
    int a,b,min,max,ans;
    while(1)
    {
        scanf("%d%d",&a,&b);
        if(a==-1 && b==-1)
            break;
        if(a<b)
            min=a,max=b;
        else
            min=b,max=a;
        int parts= min+1;
        if(max%parts!=0)
            ans = max/parts +1;
        else
            ans = max/parts;
        printf("%d\n",ans);
    }
    return 0;
}
