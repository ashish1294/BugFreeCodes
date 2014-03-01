#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    char arr[50][10];
    char c,**ptr,dum[1000],*token;
    int dummy;
    int i=0,j=0,k=0;
    long int operand[20]={0};
    dummy=scanf("%[^\n]",dum);
    token=strtok(dum," ");
    while(token!=NULL)
    {
        strcpy(arr[i],token);
        i++;
        token=strtok(NULL," ");
    }
    if(i>19)
    {
        printf("more ERROR");
        exit(0);
    }
    int n=i,flag;
    int top=-1;
    for(i=0;i<n;i++)
    {
        if((strlen(arr[i])>1)||( (((int)arr[i][0])>47) && (((int)arr[i][0])<58) )||( (((int)arr[i][0])>96) && (((int)arr[i][0])<103) )||( (((int)arr[i][0])>64) && (((int)arr[i][0])<71) ))
        {
            flag=0;
            for(k=0;k<strlen(arr[i]);k++)
            {
                if (!(( (((int)arr[i][0])>47) && (((int)arr[i][0])<58) )||( (((int)arr[i][0])>96) && (((int)arr[i][0])<103) )||( (((int)arr[i][0])>64) && (((int)arr[i][0])<71) )))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                printf("ERROR");
                exit(0);
            }
            else
            {
                top++;
                operand[top]=(long int)strtol(arr[i],NULL,16);
                if(operand[top]>65535)
                {
                    printf("ERROR");
                    exit(0);
                }
            }
        }
        else if ((strlen(arr[i])>1)||top==-1||(top==0&&arr[i][0]!='~'))
        {

            printf("ERROR");
            exit(0);
        }
        else
        {
            switch(arr[i][0])
            {
                case '+':operand[top-1] = operand[top]+operand[top-1];
                         top--;
                         if(operand[top]>65535)
                            operand[top]=65535;
                         else if(operand[top]<0)
                            operand[top]=0;
                         break;
                case '-':operand[top-1]=operand[top-1]-operand[top];
                         top--;
                         if(operand[top]>65535)
                            operand[top]=65535;
                         else if(operand[top]<0)
                            operand[top]=0;
                         break;
                case '&':operand[top-1]=operand[top-1]&operand[top];
                         top--;
                         if(operand[top]>65535)
                            operand[top]=65535;
                         else if(operand[top]<0)
                            operand[top]=0;
                         break;
                case '|':operand[top-1]=operand[top-1]|operand[top];
                         top--;
                         if(operand[top]>65535)
                            operand[top]=65535;
                         else if(operand[top]<0)
                            operand[top]=0;
                         break;
                case '~':operand[top]=65535-operand[top];
                         break;
                case 'X':operand[top-1]=operand[top-1]^operand[top];
                         top--;
                         if(operand[top]>65535)
                            operand[top]=65535;
                         else if(operand[top]<0)
                            operand[top]=0;
                         break;
                default: printf("ERROR");
                         exit(0);
            }
        }
    }
    if(top!=0)
    {
        printf("ERROR");
    }
    else
    {
        char s[10];
        sprintf(s,"%04lx",(unsigned long int)operand[top]);
        i=0;
        while(s[i]!='\0')
        {
            s[i]=toupper(s[i]);
            i++;
        }
        printf("%s",s);
    }
    return 0;
}
