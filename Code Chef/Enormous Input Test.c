#include<stdio.h>
#include<stdlib.h>

#define BUF 65535
int main()
{
    unsigned long n,k,input=0,count=0;
    char buffer[BUF];
    int c,i;
    scanf("%lu %lu\n", &n, &k);
     while ((c = fread (buffer, sizeof (char), BUF, stdin)) > 0)
        for (i = 0; i < c; i++)
		{
            if (buffer[i] == '\n')
			{
			    if ((input % k) == 0)
                    count++;
                input = 0;
            }
			else
			  	input = (input * 10) + (buffer[i] - '0');
        }
    printf("%ld\n",count);
    return 0;
}
