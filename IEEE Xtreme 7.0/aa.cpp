#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void node(char a[1000][3],char find, int n,int * nodes,char end, int *routes,char route[][2000])
//void node(char a[][],char find,int n,int *nodes,char end, int *routes, char route[][])
{
    if(find==end){
        *routes++;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i][1]==find){
            *nodes++;
            route[*routes][*nodes]=a[i][3];
            for(int j=*nodes-1;j>=0;j++){
                if((*routes)!=0){
                    route[*routes][j]=route[*routes-1][j];
                }
            }
            node(a[i][3],n,nodes,end,routes);
        }
    }
}

int findmin(char route[][],int routes,int *minimum){
    int min=10000,ret=0,x;
    for(int i=0;i<routes;i++){
        x=strlen(route[i]);
        if(x<min){
           min=x;
           ret=i;
        }
        else if(x==min){
            for(int j=0;route[i][j]!='\0';j++){
                if(route[i][j]<route[ret][j]){
                   ret=i;
                   break;
                }
                else if(route[i][j]>route[ret][j]){
                    break;
                }
            }
        }

    }
    *minimum=min;
    return ret;
}


int main(){
    char end;
    scanf("%d",&end);
    char a[1000][3],check[3];
    int n=0;
    for(int i=0;check!='A A';i++){
        scanf("%d",a[i]);
        check=a[i];
        n++;
    }
    int *nodes;
    *nodes=0;
    int *routes;
    *routes=0;
    int *minimum;
    *minimum=0;
    char route[1000][2000],f='F';
    node(a,f,n,nodes,end,routes,route);
    int routes1=*routes;
    if(routes1==0){
        printf("No Route Available from F to Z");
    }
    else{
        int minroute=findmin(route,routes1,minimum);
      int mins=*minimum;
      printf("Total Routes: %d",routes1);
      printf("Shortest Route Length: %d",mins);
      printf("Shortest Route after Sorting of Routes of length 4:");
      for(int p=0;route[ret][p]!='\0')
        printf(" %c",route[ret][p]);
    }
    printf("\n");

    return 0;
}
