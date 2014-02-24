#include<stdio.h>
int main(){
        int i,n,sum[500];
        for(i=1,sum[0]=0;sum[i-1]<100000;sum[i]=sum[i-1]+i,i++);
        while(scanf("%d",&n)!=EOF){
                for(i=1;;i++)if(sum[i]>=n&&(sum[i]-n)%2==0)break;
                printf("%d\n",i);
        }
        return 0;
}