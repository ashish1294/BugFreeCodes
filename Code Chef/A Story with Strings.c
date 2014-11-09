#include <stdio.h>
#include <string.h>
#define MAXLEN 250052
#define K 26

struct state {
	int length,link,next[26];
} st[500104];

int sz, last;
char A[250052], B[250052];

void init()
{
	st[0].link = -1;
	memset(st[0].next, -1, sizeof st[0].next);
	sz++;
}

void extend(char c)
{
	int nlast = sz++, p, q, clone;
	st[nlast].length = st[last].length + 1;
	memset(st[nlast].next, -1, sizeof st[nlast].next);
	for(p=last; p!=-1 && st[p].next[c]==-1; p=st[p].link) st[p].next[c] = nlast;
	if(p == -1) st[nlast].link = 0;
	else
	{
		q = st[p].next[c];
		if(st[p].length + 1 == st[q].length) st[nlast].link = q;
		else
		{
			clone = sz++;
			st[clone].length = st[p].length + 1;
			memcpy(st[clone].next, st[q].next, sizeof st[clone].next);
			st[clone].link = st[q].link;
			for(; p!=-1 && st[p].next[c]==q; p=st[p].link) st[p].next[c] = clone;
			st[q].link = st[nlast].link = clone;
		}
	}
	last = nlast;
}

void lcs()
{
	int i,p=0,l=0,best=0,bestpos=0;
	init();
	for(i=0; A[i]; i++) extend (A[i]-'a');
	for(i=0; B[i]; i++)
	{
		if(st[p].next[B[i]-'a'] == -1)
		{
			for(; p!=-1 && st[p].next[B[i]-'a'] == -1; p=st[p].link);
			if (p == -1) p=l=0;
			else l=st[p].length;
		}
		p = st[p].next[B[i]-'a'];
		l++;
		if(l>best)
		{
            best=l;
            bestpos=i;
		}
	}
	/*if(best==0)
    {
        putchar_unlocked('0');
        putchar_unlocked('\n');
        return;
    }
	for(i=bestpos-best+1;i<=bestpos;i++)
        putchar_unlocked(B[i]);
	putchar_unlocked('\n');*/
	printf("%d\n",best);
}

int main()
{
    register int i=0;
    A[i]=getchar_unlocked();
    while(A[i]!='\n')
        A[++i]=getchar_unlocked();
    A[i]='\0';

    i=0;B[i]=getchar_unlocked();
    while(B[i]!='\n')
        B[++i]=getchar_unlocked();
    B[i]='\0';
	lcs();
	return 0;
}
