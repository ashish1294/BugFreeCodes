#include<stdio.h>
#include<stdlib.h>
int main()
{
	int test,N,K,i=0,k=0;
	long int ans, arr[1000],temp;
	char str[4];
	scanf("%d",&test);
	while(test--)
	{
		i=0;
		scanf("%d%d%ld",&N,&K,&ans);
		while(i<N)
		{
			scanf("%ld",&temp);
            arr[i++]=temp;
		}
		fflush(stdin);
		scanf("%s",str);
		switch (str[0])
		{
            case 'X':if ((K%2)!=0)
                         for (k=0;k<N;k++)
                             ans=ans^arr[k];
                     break;
            case 'O':if(K)
                        for (k=0;k<N;k++)
                            ans=ans|arr[k];
                     break;
            default:if(K)
                        for(k=0;k<N;k++)
                            ans=ans&arr[k];
		}
		printf("%ld\n",ans);
	}
	return 0;
}
