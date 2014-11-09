    #include<stdio.h>

    int main()
    {
        void Quick_Sort(long int[],long int[],long int,long int);
        int t,n;
        long int i,j,countx,county,co,co1,diffrow,diffcol,minans;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&n);
            long int x[n],y[n],x1[n],y1[n];
            for(i=0;i<n;i++)
            {
                scanf("%ld%ld",&x[i],&y[i]);
                x1[i]=x[i];
                y1[i]=y[i];
            }
            Quick_Sort(x,y,0,n);
            Quick_Sort(y1,x1,0,n);
            co =0;
            co1 =0;
            diffrow=1;
            diffcol=1;
            for(i=1;i<n;i++)
            {
                if(x[i]!=x[i-1])
                    diffrow++;
                if(y1[i]!=y1[i-1])
                    diffcol++;
            }
            //for(i=0;i<n;i++)
              //  printf("x=%ld y=%ld           x1=%ld y1=%ld\n",x[i],y[i],x1[i],y1[i]);
            for(i=0;i<n;i++)
            {
                countx=0;
                county=0;
                if ((x[i]>=0)&&(y[i]>=0))
                {
                co += 1;
                for(j=i;j<n;j++)
                {
                    if(x[i]==x[j])
                        countx +=1;
                    if(y[i]==y[j])
                        county +=1;
                }
                //printf("\ncox=%d coy=%d\n",countx,county);
                if ((countx<county)||(countx==county))
                {
                    for(j=i+1;j<n;j++)
                        if(y[j]==y[i])
                        {
                            x[j]=-1;
                            y[j]=-1;
                        }
                }
                else
                {
                    for(j=i+1;j<n;j++)
                        if(x[j]==x[i])
                        {
                            x[j]=-1;
                            y[j]=-1;
                        }
                }
                x[i]=-1;y[i]=-1;
                //for(j=0;j<n;j++)
                  //  printf("x=%ld y=%ld\n",x[j],y[j]);
                }
            }
            for(i=0;i<n;i++)
            {
                countx=0;
                county=0;
                if ((x1[i]>=0)&&(y1[i]>=0))
                {
                co1 += 1;
                for(j=i;j<n;j++)
                {
                    if(x1[i]==x1[j])
                        countx +=1;
                    if(y1[i]==y1[j])
                        county +=1;
                }
                if (countx<county)
                {
                    for(j=i+1;j<n;j++)
                        if(y1[j]==y1[i])
                        {
                            x1[j]=-1;
                            y1[j]=-1;
                        }
                }
                else
                {
                    for(j=i+1;j<n;j++)
                        if(x1[j]==x1[i])
                        {
                            x1[j]=-1;
                            y1[j]=-1;
                        }
                    x1[i]=-1;x1[i]=-1;
                }
                }
            }
            minans=diffcol;
            if (diffrow<minans)
                minans=diffrow;
            if (co<minans)
                minans=co;
            if (co1<minans)
                minans=co1;
            printf("%ld\n",minans);
        }
        return 0;
    }
    void Quick_Sort(long int Arr[],long int Arr1[],long int l,long int u)
    {
        long int i=l,j=u-1,temp,k,pivot,temp1;
        srand(time(NULL));
        if((u-l)==0)
            return;
        pivot= (rand()%(u-l)) +l;
        while(i<=j)
        {
            while(Arr[i]<Arr[pivot])
                  i++;
            while(Arr[j]>Arr[pivot])
                  j--;

            if(i<=j)
            {
                temp=Arr[i];
                Arr[i]=Arr[j];
                Arr[j]=temp;
                temp1=Arr1[i];
                Arr1[i]=Arr1[j];
                Arr1[j]=temp1;
                if(i==pivot)
                {
                    pivot=j;
                }
                else if (j==pivot)
                {
                    pivot=i;
                }
                i++;
                j--;
            }
        }
        if (pivot<j)
        {
            temp=Arr[pivot];
            Arr[pivot]=Arr[j];
            Arr[j]=temp;
            temp1=Arr1[pivot];
            Arr1[pivot]=Arr1[j];
            Arr1[j]=temp1;
            pivot=j;

        }
        if (pivot>i)
        {
            temp=Arr[pivot];
            Arr[pivot]=Arr[i];
            Arr[i]=temp;
            temp1=Arr1[pivot];
            Arr1[pivot]=Arr1[i];
            Arr1[i]=temp1;
            pivot=i;
        }
        if(j>l)
            Quick_Sort(Arr,Arr1,l,pivot);
        if(i<u-1)
            Quick_Sort(Arr,Arr1,pivot+1,u);
    }
