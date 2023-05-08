#include<iostream>
using namespace std;

    int root;
    int visited[100]={0};
    int visitCnt=0;
    int path[100];
    int k=0;

class node{
public:
    int value;
    int childCnt=0;
    int *child;

    node(int a, int n){
    value=a;
    child=new int[n+1];
    }

    void addchild(int v){
        child[childCnt]=v;
        childCnt++;
    }
};


int min_Key(int key[], bool visited[],int n)
{
    int minimum = INT_MAX, min_index;

    for (int i = 1; i<=n; i++) {
        if (visited[i] == false && key[i] < minimum) {

            minimum = key[i];
			min_index = i;
        }
    }
    return min_index;
}


void spanning_tree_from_arrays(int parent[], int graph[][10],int n, int spanning[][10], int *mincost)
{

    int minCost=0;
    for (int i = 2; i<= n; i++) {
		minCost+=graph[i][parent[i]];
        spanning[parent[i]][i]=graph[i][parent[i]];
        spanning[i][parent[i]]=graph[i][parent[i]];
    }
    (*mincost)=minCost;

}


void find_minimum_spanning_tree(int graph[][10],int n,int spanning[][10], int *mincost)
{
    int parent[n+1], key[n+1];
    bool visited[n+1];


    for (int i = 1; i<= n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
        parent[i]=-1;
    }

    cout<<"Enter a root node\n";
    cin>>root;

    key[1] = root;
    parent[root] = -1;


    for (int i = 1; i <n ; i++)
    {
        int u = min_Key(key, visited,n);
        visited[u] = true;
        for (int j=1; j<=n; j++)
        {
            if (graph[u][j]!=0 && visited[j]==false && graph[u][j]<key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
	spanning_tree_from_arrays(parent,graph,n,spanning,mincost);
}


void preorderTrav(node *arr[],int r, int n){


    if(!visited[r]){
    cout<<arr[r]->value<<"\t";
    visited[r]=1;
    visitCnt++;
    path[k++]=arr[r]->value;
    }
    else{
        return;
    }

    if(visitCnt==n)
        return;

    for(int i=0;i<arr[r]->childCnt;i++){
        preorderTrav(arr,arr[r]->child[i],n);
    }

}


int main(){
int graph[10][10],n,m,x;

    for(int i=0;i<100;i++)
        visited[i]=0;

    cout<<"Enter number of vertices\n";
    cin>>n;

    cout<<"Enter number of edges\n";
    cin>>m;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            graph[i][j]=0;
        }
    }

    int p,q,weight;

    for(int i=1;i<=m;i++) {
        cout<<"enter Source\n";
        cin>> p;
        cout<<"enter destination\n";
        cin>>q;
        cout<<"Enter weight\n";
        cin>>weight;
        graph[p][q]=weight;
        graph[q][p]=weight;
        }

    cout<<"Adjacency matrix of Undirected Graph is\n";

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                graph[i][j]=j;
            }
            else if(j==0){
                graph[i][j]=i;
            }
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    int spanning[10][10], mincost=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            spanning[i][j]=0;

	find_minimum_spanning_tree(graph,n,spanning, &mincost);

   // cout<<"Adjacency matrix of Spanning Graph is\n";

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){

            if(i==0){
                spanning[i][j]=j;
            }

            else if(j==0){
                spanning[i][j]=i;
            }
      //  cout<<spanning[i][j]<<"\t";
        }
     //   cout<<endl;
    }

    node *arr[10];

    for(int i=1;i<=n;i++)
        arr[i] = new node(i,n);

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(spanning[i][j]){
                arr[i]->addchild(j);
                arr[i]->value=i;
            }
        }
    }

    preorderTrav(arr,root,n);
    cout<<root<<endl;
    path[k]=root;

    cout<<"Path for tsp is\n";

    for(int i=0;i<=k;i++)
        cout<<path[i]<<"\t";

    cout<<"\nTotal cost is\n";

    int cost=0;



    for(int i=0;i<k;i++)
        cost+=graph[path[i]][path[i+1]];

    cout<<cost;

    return 0;


}

