#include <stdio.h>

int front=0,rear=-1;
int queue[20];
void bfs(int v,int n,int g[n][n],int visited[n],int queue[n])
{
    int i;
    visited[v]=1;
    printf("%d",v);
    queue[++rear]=v;
    while(front<=rear)
    {
        int temp=queue[front++];
        for(i=0;i<=n;i++)
        {
            if(g[temp][i] && !visited[i])
            {
                visited[i]=1;
                printf("%d",i);
                queue[++rear]=i;
            }
        }
    }
}

void main()
{
    int i,j,n;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    int g[n][n],visited[n],queue[n];
    for(i=0;i<=n;i++)
    {
        visited[i]=0;
        queue[i]=n;
        for(j=1;j<=n;j++)
        {
            g[i][j]=0;
        }
    }
printf("Enter the matrix\n");
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        scanf("%d",&g[i][j]);
    }
}
printf("BFS order\n");
bfs(1,n,g,visited,queue);
}