#include <iostream>
using namespace std;

int a[10], book[10];
int n,total;

void dfs(int step)
{
    if(step == n+1){
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]==a[7]*100+a[8]*10+a[9])
        {
            printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
            total++;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    printf("the total is:%d\n", total/2);
    return 0;
}