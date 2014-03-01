#define SIZE 1000           /* Size of Stack */
#include <ctype.h>
#include<stdio.h>

char s[SIZE];
int top = -1;
void push(char elem){ s[++top] = elem;}
char pop(){return (s[top--]);}

int pr(char elem) {switch (elem){
 case '#':return 0;case '(':return 1;
 case '+': case '-':return 2;
 case '*': case '/':return 3;
 case '^':return 4; } }

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char infx[500], pofx[500], ch, elem;
        int i=0, k=0;
        scanf("%s", infx);
        push('#');
        while ((ch = infx[i++]) != '\0')
        {
            if (ch == '(')
                push(ch);
            else if (isalnum(ch))
                pofx[k++] = ch;
            else if (ch == ')')
            {
                while (s[top] != '(')
                    pofx[k++] = pop();
                elem = pop();
            }
            else
            {
                while (pr(s[top]) >= pr(ch))
                    pofx[k++] = pop();
                push(ch);
            }
        }
        while (s[top] != '#')
            pofx[k++] = pop();
        pofx[k] = '\0';
        printf("%s\n",pofx);
    }
    return 0;
}
