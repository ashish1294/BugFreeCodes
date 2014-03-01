#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	char a[2000], b[2000];
	while(t--)
	{
		scanf("%s %s",a,b);
		char c = a[strlen(a)-1];
		if(strlen(a)==1 && c=='0')
			printf("0\n");
		else if(strlen(b)==1 && b[0]=='0')
		{
			printf("1\n");
		}
		else
		{
			long int nnn = strlen(b),v;
			if(nnn==1)
				v=0;
			else
				v=(((int)b[nnn-2]) - 48)*10;
			v += (((int)b[nnn-1]) - 48);
			if(v%4==0)
				v=4;
			else
				v=v%4;
			int val =((int)c)-48;
			printf("%d\n",((int)pow(val,v))%10);
		}
	}
	return 0;
}
