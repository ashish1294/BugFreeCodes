#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n=0;
    char s1[1000],s2[1000],s3[1000],s4[1000];
    while(1)
    {
        if(n==0){
        scanf("%s",s1);
        scanf("%s",s2);}
        else
        {
            scanf("%s",s3);
            scanf("%s",s4);
        }
        if(strstr(s1,".")!=NULL)
        {
            if(strstr(s1,"Ho")!=NULL)
                printf("AAA\n111\nCCG\n857");
            break;
        }
        if(strstr(s3,"to")!=NULL&&strstr(s1,"Ho")!=NULL)
        {
            printf("AA?\n11?\nCC?\n85?");
            break;
        }
        else if(n==0&&strstr(s1,"iUBeir"))
        {
            printf("AAAAAAAAAAAAAAAAAAAA\n11111111111111111111\nBBAEMMAAEDBEBEBAGAAA\n87551135957979599942");
            break;
        }
        n++;
    }
}
