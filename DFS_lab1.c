#include<stdio.h>
#include<stdlib.h>

#define MAX 50

#define initial 0
#define visited 1

int n;    
int adj[MAX][MAX];
int state[MAX];
int stack[MAX];
int top = -1;


int main()
{
        create_graph();
        DFS_Traversal();
}

void DFS_Traversal()
{
        int a;

        for(a=0; a<n; a++)
                state[a]=initial;

        printf("\nEnter starting node for Depth First Search : ");
        scanf("%d",&a);
        DFS(a);
        printf("\n");
}

void DFS(int a)
{
        int i;
        push(a);
        while(!isEmpty_stack())
        {
                a = pop();
                if(state[a]==initial)
                {
                        printf("%d ",a);
                        state[a]=visited;
                }
                for(i=n-1; i>=0; i--)
                {
                        if(adj[a][i]==1 && state[i]==initial)
                                push(i);
                }
        }
}
void push(int v)
{
        if(top == (MAX-1))
        {
                printf("\nStack Overflow\n");
                return;
        }
        top=top+1;
        stack[top] = v;

}

int pop()
{
        int v;
        if(top == -1)
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        else
        {
                v = stack[top];
                top=top-1;
                return v;
        }
}

int isEmpty_stack()
{
  if(top == -1)
          return 1;
  else
          return 0;
}
void create_graph()
{
        int i,max_edges,origin,dest;

        printf("\nEnter number of nodes : ");
        scanf("%d",&n);
        max_edges=n*(n-1);

        for(i=1;i<=max_edges;i++)
        {
                printf("\nEnter edge %d(source,destination) : ",i);
                scanf("%d %d",&origin,&dest);

                if( (origin == -1) && (dest == -1) )
                        break;

                if( origin > n || dest > n || origin<0 || dest<0)
                {
                        printf("\nInvalid edge!\n");
                        i--;
                }
                else
                {
                        adj[origin][dest] = 1;
                }
        }
}