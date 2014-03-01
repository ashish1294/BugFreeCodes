#include<stdio.h>
int main()
{
    int t,h1,h2,m1,m2,s1,s2;
    long int time;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&h1,&m1,&s1,&h2,&m2,&s2);
        time = ((((h2-h1)*60)+(m2-m1))*60)+(s2-s1);
        time = time%400;
        /*time = ((h2 - h1)*60)%400;
        time += m2 - m1;
        time = (time*60)%400;
        time += s2 -s1;
        time = time%400;*/
        //printf("time=%ld\n",time);
        if (time<100)
            printf("S\n");
        else if (time>199&&time<300)
            printf("S\n");
        else
            printf("C\n");
    }
    return 0;
}
