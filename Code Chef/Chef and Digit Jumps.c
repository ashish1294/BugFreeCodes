#include<stdio.h>
#include<string.h>
#define min(a, b) (a < b ? a : b)
char s[100010];
static int arr[100010], dig[10];
int main()
{
    scanf("%s", s);
    int len = strlen(s) - 1, i;

    for(i = 0; i < 10; i++) dig[i] = 100000000;

    dig[s[len] - '0'] = 0;
    arr[len] = 0;
    for(i = len - 1; i >= 0; i--)
    {
        if(arr[i+1] < dig[s[i] - '0'])
        {
            arr[i] = arr[i+1] + 1;
        }
        else
        {
            arr[i] = dig[s[i] - '0'] + 1;
            arr[i+1] = min(arr[i+1], arr[i] + 1);
            dig[s[i+1] - '0'] = min(dig[s[i+1] - '0'], arr[i+1]);
        }
        dig[s[i] - '0'] = min(dig[s[i] - '0'], arr[i]);
        //printf("arr[%d] = %d\n",i, arr[i]);
    }

    printf("%d\n", arr[0]);
    return 0;
}
