#include<stdio.h>
#include<string.h>
#include<ctype.h>
long int freqplot[30];
int main()
{
    int t;
    char freq[30],text[200000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",freq);
        scanf("%s",text);
        fi=strlen(freq)-1;
        for(i=0;i<30;i++)
            freqplot[i]=0;
        i=0;
        while(text[i]!='\0')
        {
            c=text[i];
            if(isalpha(c))
            {
                if(isupper(c))
                    c=tolower(c);
                int index = ((int)c) - ((int)'a');
                freqplot[index]++;
            }
        }
    }
}
