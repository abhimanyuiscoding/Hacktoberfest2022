#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void create_graph();
void display();
void dfs(int v);
void bfs(int v);
void adj_nodes(int v);
int adj[MAX][MAX];
int visited[MAX];
int n; /* Denotes number of nodes in the graph */
int main()
{
    int i,v,choice;
    create_graph();
    while(1){
        printf("\n");
        printf("1. Adjacency matrix\n");
        printf("2. Depth First Search using stack\n");
        printf("3. Breadth First Search\n");
        printf("4. Adjacent vertices\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Adjacency Matrix\n");
                display();
                break;
            case 2:
                printf("Enter starting node for Depth First Search : ");
                scanf("%d",&v);
                for(i=1;i<=n;i++)
                    visited[i]=0;
                dfs(v);
                break;
            case 3:
                printf("Enter starting node for Breadth First Search : ");
                scanf("%d", &v);
                for(i=1;i<=n;i++)
                    visited[i]=0;
                bfs(v);
                break;
            case 4:
                printf("Enter node to find adjacent vertices : ");
                scanf("%d", &v);
                printf("Adjacent Vertices are : ");
                adj_nodes(v);
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong choice\n");
                break;
    }
    }
}/*End of main()*/

void create_graph()
{
int i,max_edges,origin,destin;
printf("Enter number of nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
    adj[i][i]=1;
max_edges=n*(n-1);

for(i=1;i<=max_edges;i++)
{
    printf("Enter edge %d( 0 0 to quit ) : ",i);
    scanf("%d %d",&origin,&destin);
    if((origin==0) && (destin==0))
        break;
    if( origin > n || destin > n || origin<=0 || destin<=0)
    {
        printf("Invalid edge!\n");
        i--;
    }
    else
    {
        adj[origin][destin]=1;
        adj[destin][origin]=1;
    }
}
}
void display()
{
    int i,j;
    for(i=1;i<=n;i++)

    {    
    for(j=1;j<=n;j++)
        printf("%4d",adj[i][j]);
    printf("\n");
}
}/*End of display()*/

void dfs(int v)
{
    int i,stack[MAX],top=-1,pop_v,j,t;
    int ch;
    top++;
    stack[top]=v;
    while (top>=0)
    {
        pop_v=stack[top];
        top--; 
        if( visited[pop_v]==0)
        {
            printf("%d ",pop_v);
            visited[pop_v]=1;
        }
    //else
    //continue;
    for(i=1;i<=n;i++)
    {
        if( adj[pop_v][i]==1 && visited[i]==0)
        {
            top++; /* push all unvisited neighbours of pop_v */
            stack[top]=i;
        }
    }
}
}/*End of dfs()*/
void bfs(int v)
{
    int i,front,rear;
    int que[20];
    front=rear= -1;
    printf("%d ",v);
    visited[v]=1;
    rear++;
    que[rear]=v;
    while(front<=rear)
    {
        front++;
        if(front<=rear)
            v=que[front]; /* delete from queue */
        for(i=1;i<=n;i++)
        {
            /* Check for adjacent unvisited nodes */
            if( adj[v][i]==1 && visited[i]==0)
            {
                printf("%d ",i);
                visited[i]=1;
                rear++;
                que[rear]=i;
            }
        }
    }
}/*End of bfs()*/

void adj_nodes(int v)
{
    int i;
    for(i=1;i<=n;i++)
        if((adj[v][i]==1)||(adj[i][v]==1))
            printf("%d ",i);
    printf("\n");
}/*End of adj_nodes()*/