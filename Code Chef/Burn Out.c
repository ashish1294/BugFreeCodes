#include<stdio.h>
#include<string.h>
int main()
{
    long int t,n,i,j,frag,respawn,temp;
    scanf("%ld",&t);
    j=1;
    while(j<=t)
    {
        respawn=0;
        frag=0;
        temp=0;
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            respawn += ((temp/30) + 1)*10 ;
            frag += ((temp/60) + 1)*15 ;
        }
        printf("Case %ld: ",j);
        if(frag<respawn)
            printf("Frag %ld",frag);
        else if(frag>respawn)
            printf("Respawn %ld",respawn);
        else if(frag==respawn)
            printf("Respawn Frag %ld",frag);
        printf("\n");
        j++;
    }
    return 0;
}
