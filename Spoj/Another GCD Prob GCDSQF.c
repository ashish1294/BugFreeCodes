//http://www.spoj.com/problems/GCDSQF/
// @ashish1294

#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	char s1[1500],s2[1500];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s1,s2);
		int l1=strlen(s1),l2=strlen(s2),l,i;
		if(l1<l2) l=l1;
		else l=l2;
		char ans[l+5];
		for(i=0;i<l;i++)
			if(s1[i]=='1' && s2[i]=='1') ans[i]='1';
			else ans[i]='0';
		for(i=l-1;i>=0;i--)
			if(ans[i]=='1')
				break;
		if(i<0)
			printf("relatively prime\n");
		else
		{
			ans[i+1]='\0';
			printf("%s\n",ans);
		}
	}
	return 0;
}
