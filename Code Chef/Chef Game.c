#include<stdio.h>

void Merge_Sort(long int Arr[] ,long int l,long int u);
void Insertion_Sort(long int Arr[],long int l, long int u);
void Merge(long int Arr[],long int Arr1[],long int l,long int mid, long int u);
void Quick_Sort(long int Arr[],long int l,long int u);
int main()
{
    int t,k,i,test,i1,odd_count,even_count,maxcol,j,geven,godd,evco[50],odco[50],exi;
    long int ge,go;
    long int arr[102][50][2];
    scanf("%d",&t);
    for(test=1;test<=t;test++)
    {
        ge=0;go=0;
        for(j=0;j<50;j++)
        {
            evco[j]=0;
            odco[j]=0;
            for(i=0;i<102;i++)
                arr[i][j][0]=-1;
        }
        maxcol=0;
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%ld",&arr[i][0][0]);
            arr[i][0][1]=test;
            if(arr[i][0][0]>maxcol)
                maxcol=arr[i][0][0];
            long int temparr[arr[i][0][0]];
            for(j=0;j<arr[i][0][0];j++)
            {
                scanf("%ld",&temparr[j]);
            }
            /*printf("\nbef sorting\n");
            for(j=0;j<arr[i][0][0];j++)
            {
                printf("%ld ",temparr[j]);
            }*/
            if(arr[i][0][0]>0)
            {
                Quick_Sort(temparr,0,arr[i][0][0]);
            }
            if(arr[i][0][0]>0)
            {
                exi=1;
                if(temparr[0]%2==0)
                {
                    ge++;
                    while(exi<arr[i][0][0])
                    {
                        if(temparr[exi]%2==0)
                        {
                            ge++;
                        }
                        else
                            break;
                    }
                }
                else
                {
                    go++;
                    while(exi<arr[i][0][0])
                    {
                        if(temparr[exi]%2!=0)
                        {
                            go++;
                        }
                        else
                            break;
                    }
                }
            }
            //printf("\nafter sorting\n");
            /*for(j=0;j<arr[i][0][0];j++)
            {
                printf("%ld "&temparr[j]);
            }*/
            for(j=0;j<arr[i][0][0];j++)
            {
                //if (temparr[j]%2==0)
                    //evco[j]++;
                //else
                  //  odco[j]++;

                arr[i][j+1][0]=temparr[j];
                arr[i][j+1][1]=test;
            }
        }
        /*for(i=0;i<k;i++)
        {
            for(j=0;j<=maxcol;j++)
                printf("%d ",arr[i][j][0]);
            printf("\n");
        }*/
        if(ge>go)
            printf("EVEN\n");
        else if(go>ge)
            printf("ODD\n");
        else
            printf("DON'T PLAY\n");
        geven=0;godd=0;
        /*j=0;
        while((evco[j]+odco[j])!=0 && j<maxcol)
        {
            if(evco[j]>odco[j])
                geven++;
            else if(evco[j]<odco[j])
                godd++;
            j++;
        }
        for(j=1;j<=maxcol;j++)
        {
            odd_count=0;
            even_count=0;
            for(i1=0;i1<k;i1++)
            {
                    if(arr[i1][j][1]==test)
                    {
                        if(arr[i1][j][0]%2==0)
                            even_count++;
                        else
                            odd_count++;
                    }
            }
            if(odd_count==0)
            {
                printf("EVEN\n");
                break;
            }
            else if(even_count==0)
            {
                printf("ODD\n");
                break;
            }
            else if(j==maxcol)
            {
                printf("DON'T PLAY\n");
                break;
            }
        }

        /*if(geven==godd)
            printf("DON'T PLAY\n");
        else if(geven>godd)
            printf("EVEN\n");
        else
            printf("ODD\n");*/
    }
    return 0;
}
void Merge_Sort(long int Arr[] ,long int l,long int u)
{
    if(u==0)
        return;
    long int i, mid=(l+u)/2;
    long int Arr1[u+1];
    for(i=0;i<=u;i++)
    {
            Arr1[i]=Arr[i];
    }
    if(mid>20)
    {
        Merge_Sort(Arr1,0,mid);
        Merge_Sort(Arr1,mid+1,u);
    }
    else
    {
        Insertion_Sort(Arr1,0,mid);
        Insertion_Sort(Arr1,mid+1,u);
    }
    Merge(Arr,Arr1,l,mid,u);
    return;
}

void Merge(long int Arr[],long int Arr1[],long int l,long int mid, long int u)
{
    long int i=l,j=mid+1,k=0;
    while((i<=mid)&&(j<=u))
    {
        if(Arr1[i]<Arr1[j])
        {
            Arr[k]=Arr1[i];
            i++;
            k++;
        }
        else
        {
            Arr[k]=Arr1[j];
            j++;
            k++;
        }
    }

    if(i>mid)
    {
        for(;j<=u;j++,k++)
            Arr[k]=Arr1[j];
    }
    else
    {
        for(;i<=mid;i++,k++)
            Arr[k]=Arr1[i];
    }
    return;
}

void Insertion_Sort(long int Arr[],long int l, long int u)
{
    long int i,j,temp;
    for(i=l+1;i<=u;i++)
    {
        temp=Arr[i];
        j=i-1;
        while(j>=l&&(Arr[j]>temp))
        {
            Arr[j+1]=Arr[j];
            j--;
        }
        Arr[j+1]=temp;
    }
}
void Quick_Sort(long int Arr[],long int l,long int u)
{
    long int i=l,j=u-1,temp,k,pivot;
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
        pivot=j;

    }
    if (pivot>i)
    {

        temp=Arr[pivot];
        Arr[pivot]=Arr[i];
        Arr[i]=temp;
        pivot=i;
    }
    if(j>l)
        Quick_Sort(Arr,l,pivot);
    if(i<u-1)
        Quick_Sort(Arr,pivot+1,u);
}
