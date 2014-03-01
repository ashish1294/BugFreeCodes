#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
int main() {
    int i=0;
    char c[99999];
    while(1)
    {
        gets(c);
        i++;
        if(i==31)
        {
            printf("Err");
        }
        if(i>31)
        {
            printf("Too long");
            break;
        }
        else if(strcmp(c,"BBCDE")==0)
        {
            printf("Ok");
            break;
        }
    }
}
