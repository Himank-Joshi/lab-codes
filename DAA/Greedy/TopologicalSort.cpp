// htps://www.youtube.com/watch?v=eL-KzMXSXXI&t=21s   {https}

// REMEMVER ->arrays are always passed by reference.
//          ->//Using the concept of pointer to an array
#include <bits/stdc++.h>
using namespace std;
#include <stack>

void DFS(int adj[][10], int ver, bool visited[], stack<int> &S, int u)
{
    visited[u] = true;
    for (int v = 1; v < ver; v++)
    {
        if (visited[v] == false && adj[u][v] == 1)
        {
            DFS(adj, ver, visited, S, v);
        }
    }
    S.push(u);
}

void ToplogicalSort(int adj[][10], int ver)
{
    stack<int> S;
    bool visited[ver];
    for (int i = 1; i < ver; i++)
    {
        visited[i] = false;
    }
    for (int i = 1; i < ver; i++)
    {
        if (visited[i] == false)
            DFS(adj, ver, visited, S, i);
    }
    cout << "Topological Order -> ";
    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
}

int main()
{
    cout << "Enter number of vertices :";
    int ver;
    cin >> ver;
    cout << "Enter number of edges : ";
    int edges;
    cin >> edges;
    int adj[10][10];
    cout << "Enter source then destination ";
    for (int i = 0; i < edges; i++)
    {
        cout << "Edge " << i + 1 << " -> ";
        int u, v;
        adj[u][v] = 1;
    }
    ToplogicalSort(adj, ver + 1);
}

// Using the concept of pointer to an array
//  #include <stdio.h>
// const int M = 3;

// void print(int (*arr)[M])
// {
// 	int i, j;
// 	for (i = 0; i < M; i++)
// 	for (j = 0; j < M; j++)
// 		printf("%d ", arr[i][j]);
// }

// int main()
// {
// 	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
// 	print(arr);
// 	return 0;
// }
