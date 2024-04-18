#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAX_NODES 100
#define MAX_EDGES 6000

struct Edge{
    int source,target,weight;
};
int minDistance(int dist[],bool visited[],int n){
    int min=INT_MAX,min_index;
    for(int v=1;v<=n;v++){
        if(!visited[v] && dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}
int dijkstra(int graph[MAX_NODES][MAX_NODES],int n,int k){
    int dist[MAX_NODES];
    bool visited[MAX_NODES];

    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[k]=0;

    for(int count=1;count<=n-1;count++){
        int u=minDistance(dist,visited,n);
        visited[u]=true;

        for(int  v=1;v<=n;v++){
            if(!visited[v] && graph[u][v]&& dist[u]!=INT_MAX && dist[u]+ graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    int max_time=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==INT_MAX)
            return -1;
        if(dist[i]>max_time)
            max_time=dist[i];
    }
    return max_time;
}
int main(){
    int n,k,num_edges;

    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the Source node: ");
    scanf("%d",&k);
    printf("Enter the number of edges: ");
    scanf("%d",&num_edges);

    int graph[MAX_NODES][MAX_NODES]  ={0};
    for(int i=0;i<num_edges;i++){
        int source,target,weight;
        printf("Enter source,target, and weight for edge %d: ",i+1);
        scanf("%d %d %d",&source,&target,&weight);
        graph[source][target]=weight;
    }

    int min_time=dijkstra(graph,n,k);
    printf("Minimum time to reach all nodes: %d\n",min_time);
    return 0;
}