#include <iostream>
using namespace std;
int main()
{
    cout << "Enter number of vertices ";
    int n;
    cin >> n;
    int adj[10][10];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = 0;
        }
    }
    cout << "Enter number of edges ";
    int e;
    cin >> e;
    for (int i = 1; i <= e; i++)
    {
        cout << "Enter edge " << i << " -> ";
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    bool visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = false;

    for (int u = 1; u <= n; u++)
    {
        if (!visited[u])
        {
            for (int v = 1; v <= n; v++)
            {
                if (!visited[v] && adj[u][v] == 1)
                {
                    visited[u] = true;
                    visited[v] = true;
                    break;
                }
            }
        }
    }
    cout << "Vertex Cover -> ";
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            cout << i << " ";
    }
}