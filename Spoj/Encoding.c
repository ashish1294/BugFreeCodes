#include<stdio.h>
#include<string.h>
char str[500];
char mat[25][25];
void spiral(int m, int n)
{
    int counter=0;
    int i, k = 0, l = 0;
    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            mat[k][i]=str[counter++];
            //printf("%d ", a[k][i]);
        }
        k++;

        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            mat[i][n-1]=str[counter++];
            //printf("%d ", a[i][n-1]);
        }
        n--;

        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                mat[m-1][i]=str[counter++];
                //printf("%d ", a[m-1][i]);
            }
            m--;
        }

        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                mat[i][l]=str[counter++];
                //printf("%d ", a[i][l]);
            }
            l++;
        }
    }
}
int main()
{
    int t,r,c,test,i,j;
    char s[100],dummy;
    scanf("%d",&t);
    for(test=1;test<=t;test++)
    {
        scanf("%d%d",&r,&c);
        gets(s);
        //printf("string = %s\n",s);
        i=0;
        if(s[i]==' ')
            while(s[i]!='\0')
            {s[i]=s[i+1];i++;}
        s[i]='\0';
        //printf("string = %s\n",s);
        i=0;
        strcpy(str,"");
        while(s[i]!='\0')
        {
            switch(s[i])
            {
            case ' ': strcat(str,"00000");break;
            case 'A': strcat(str,"00001");break;
            case 'B': strcat(str,"00010");break;
            case 'C': strcat(str,"00011");break;
            case 'D': strcat(str,"00100");break;
            case 'E': strcat(str,"00101");break;
            case 'F': strcat(str,"00110");break;
            case 'G': strcat(str,"00111");break;
            case 'H': strcat(str,"01000");break;
            case 'I': strcat(str,"01001");break;
            case 'J': strcat(str,"01010");break;
            case 'K': strcat(str,"01011");break;
            case 'L': strcat(str,"01100");break;
            case 'M': strcat(str,"01101");break;
            case 'N': strcat(str,"01110");break;
            case 'O': strcat(str,"01111");break;
            case 'P': strcat(str,"10000");break;
            case 'Q': strcat(str,"10001");break;
            case 'R': strcat(str,"10010");break;
            case 'S': strcat(str,"10011");break;
            case 'T': strcat(str,"10100");break;
            case 'U': strcat(str,"10101");break;
            case 'V': strcat(str,"10110");break;
            case 'W': strcat(str,"10111");break;
            case 'X': strcat(str,"11000");break;
            case 'Y': strcat(str,"11001");break;
            case 'Z': strcat(str,"11010");break;
            }
            i++;
        }
        for(i=strlen(str);i<r*c;i++)
            str[i]='0';
        str[i]='\0';
        //printf("string = %s\n",str);
        spiral(r,c);
        printf("%d ",test);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                printf("%c",mat[i][j]);
        printf("\n");
    }
    return 0;
}
