#include<iostream>
using namespace std;

void Dj(int distDupli[][10],int ver ,int source ,int result[]){
    int dist[10][10];
    for(int i=1;i<=ver;i++){
    for(int j=1;j<=ver;j++){
        dist[i][j]=distDupli[i][j];
    }
   }
   int distance[ver+1];
   bool visited[ver+1];
   for(int i=1;i<=ver;i++){
      distance[i]=999;
      visited[i]=false;
   }

   distance[source]=0;
   int numVisited=0;

   while(numVisited != ver){

      int minDist=999,minIndex=0;
      for(int i=1;i<=ver;i++){
         if(visited[i]==false && distance[i] < minDist){
         minDist=distance[i];
         minIndex=i; }
   }

   visited[minIndex]=true;
   numVisited++;

    for(int i=1;i<=ver;i++){
         if(visited[i]==false && distance[minIndex]+dist[minIndex][i] < distance[i])
         distance[i]= distance[minIndex]+dist[minIndex][i] ;

   }

   }
   cout<<"Printing  Shortest Distance from "<<source<<endl;
    for(int i=1;i<=ver;i++){
        if(i==source)
            continue;
        cout<<"Vertex " <<i <<" --> "<<distance[i]<<endl;
        result[i]=distance[i];
   }
}


int main(){

   cout<<"Enter number of vertices : ";
   int ver;
   cin>>ver;
   int dist[10][10];
   for(int i=1;i<=ver;i++){
    for(int j=1;j<=ver;j++){
        dist[i][j]=999;
    }
   }
   cout<<"Enter number of edges (Assuming Not directed) : ";
   int edges; cin>>edges;

   cout<<"Enter source then destination then distance : "<<endl;


   for(int i=1;i<=edges;i++){
    cout<<"Edge "<<i<<" : ";
    int s,d,distance;
    cin>>s>>d>>distance;
    dist[s][d]=distance;
    dist[d][s]=distance;
   }
   cout<<"From Cities ";
   for(int i=1;i<= ver;i++)
    cout<<i<<" , ";
   cout<<"Enter Intial city where person is currently : ";
    int source1;cin>>source1;

    int arr1[ver+1],arr2[ver+1],arr3[ver+1];
     for(int i=1;i<=ver;i++){
        arr1[i]=0;
        arr2[i]=0;
        arr3[i]=0;
     }

   Dj(dist,ver,source1,arr1);
   int source2,source3;

    cout<<endl<<"Enter the 2 cities you want to compare : ";
    cin>>source2>>source3;
    Dj(dist,ver,source2,arr2);
     Dj(dist,ver,source3,arr3);

     int dist2=0,dist3=0;
     for(int i=1;i<=ver;i++){
        dist2+=arr2[i];
        dist3+=arr3[i];
     }
     cout<<"Total minimum distance from "<<source2<<" = "<<dist2<<endl;
     cout<<"Total minimum distance from "<<source3<<" = "<<dist3<<endl;
     if(dist2 < dist3)
        cout<<source2<<" is a better option"<<endl;
     else
         cout<<source3<<" is a better option"<<endl;



}






