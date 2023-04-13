#include <iostream>
using namespace std;

void DijkstrasAlgo(int distMat[][10], int ver, int root)
{
    bool visited[ver + 1];
    int distance[ver + 1];
    for (int i = 1; i <= ver; i++)
    {
        visited[i] = false;
        distance[i] = 999;
    }
    distance[root] = 0;
    int numVisited = 0;
    while (numVisited != ver)
    {
        // finding minimum unvisited dist node
        int minDist = 999, minIndex = 0;
        for (int i = 1; i <= ver; i++)
        {
            if (distance[i] < minDist && visited[i] == false)
            {
                minDist = distance[i];
                minIndex = i;
            }
        }
        visited[minIndex] = true;
        numVisited++;
        for (int i = 1; i <= ver; i++)
        {
            if (visited[i] == false && distance[minIndex] + distMat[minIndex][i] < distance[i])
                distance[i] = distance[minIndex] + distMat[minIndex][i];
        }
    }
    for (int i = 1; i <= ver; i++)
    {
        if (i == root)
            continue;
        cout << "Min dist from " << root << " to " << i << " = " << distance[i] << endl;
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
    }
    cout << "Enter source from where u want shortest path to all other vertices ";
    int root;
    cin >> root;
    DijkstrasAlgo(distMat, ver, root);
}