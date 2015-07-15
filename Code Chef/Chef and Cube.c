#include <stdio.h>
#include <string.h>

int main()
{
    int t, col[6], i;
    char str[10];

    scanf("%d", &t);
    while(t--)
    {
        for(i = 0; i < 6; i++)
        {
            scanf("%s", str);

            if(strcmp(str, "black") == 0) col[i] = 0;
            else if(strcmp(str, "blue") == 0) col[i] = 1;
            else if(strcmp(str, "red") == 0) col[i] = 2;
            else if(strcmp(str, "green") == 0) col[i] = 3;
            else if(strcmp(str, "yellow") == 0) col[i] = 4;
            else col[i] = 5;
        }
        if ( ((col[2] == col[4] || col[4] == col[3]) && (col[4] == col[0] || col[4] == col[1])) ||
             ((col[2] == col[5] || col[3] == col[5]) && (col[5] == col[0] || col[5] == col[1])))    
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}