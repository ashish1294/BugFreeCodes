#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool isPalindrome(char str[], int begin, int end);
int minSplit_2(char str[]);
int minSplit_2(char str[])
{
    int length = strlen(str);
    int* split = new int[length];
    for(int i = 0; i < length; ++i)
        split[i] = i;

    for(int i = 1; i < length; ++i)
    {
        if(isPalindrome(str, 0, i))
        {
            split[i] = 0;
            continue;
        }

        for(int j = 0; j < i; ++j)
        {
            if(isPalindrome(str, j + 1, i) && split[i] > split[j] + 1)
                split[i] = split[j] + 1;
        }
    }

    int minSplit = split[length - 1];
    delete[] split;
    return minSplit;
}
bool isPalindrome(char str[], int begin, int end)
{
    for(int i = begin; i < end - (i - begin); ++i)
        if(str[i] != str[end - (i - begin)])
            return false;
    return true;
}
int main()
{
    int minSplit_2(char[]);
    int t,n;
    char str[10000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",str);
        printf("%d\n",minSplit_2(str)+1);
    }
}
