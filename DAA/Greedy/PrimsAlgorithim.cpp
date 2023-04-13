#include <iostream>
using namespace std;

void Prims(int disMat[][10], int ver)
{
    int distance[ver + 1], parent[ver + 1];
    bool visited[ver + 1];
    for (int i = 1; i <= ver; i++)
    {
        distance[i] = 999;
        visited[i] = false;
        parent[i] = -1;
    }
    // so that 1 gets selected 1st
    distance[1] = 0;
    int numVisited = 0;
    while (numVisited != ver)
    {
        // find vertex with min dist
        int minDist = 999, minIndex;
        for (int i = 1; i <= ver; i++)
        {
            if (visited[i] == false && distance[i] < minDist)
            {
                minDist = distance[i];
                minIndex = i; // found minIndex
            }
        }
        visited[minIndex] = true;
        numVisited++;

        for (int i = 1; i <= ver; i++)
        {
            if (visited[i] == false && disMat[minIndex][i] < distance[i])
            {
                distance[i] = disMat[minIndex][i];
                parent[i] = minIndex;
            }
        }
    }
    cout << "Minimum cost spanning tree using Prims -> " << endl;
    for (int i = 2; i <= ver; i++)
    {
        cout << parent[i] << " --- " << i << " =  " << distance[i] << endl;
    }
}

int main()
{
    int distMat[10][10]; // stores distance between edges
    cout << "Enter number of vertices  :";
    int ver;
    cin >> ver;
    for (int i = 1; i <= ver; i++)
    {
        for (int j = 1; j <= ver; j++)
        {
            distMat[i][j] = 999;
        }
    }
    cout << "Enter number of edges : ";
    int edges;
    cin >> edges;
    cout << "Enter source then dest then cost :" << endl;
    for (int i = 1; i <= edges; i++)
    {
        cout << "Edge " << i << " : ";
        int u, v, dist;
        cin >> u >> v >> dist;
        distMat[u][v] = dist;
        distMat[v][u] = dist;
    }
    Prims(distMat, ver);
}