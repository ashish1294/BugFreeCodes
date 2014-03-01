//http://www.spoj.com/problems/HANGOVER/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    int i;
    float d;
    while(1)
    {
        scanf("%f",&d);
        if(d==0.00) break;
        float sum = 0;
        i = 1;
        while(sum<=d)
        {
            sum+=(float)1/(i+1);
            i++;
        }
        printf("%d card(s)\n",i-1);
    }
    return 0;
}
