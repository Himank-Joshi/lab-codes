#include <iostream>
using namespace std;
class Tsp
{
    int adj[10][10], v[10], bestv[10], currCost, bestCost, n, count;

public:
    Tsp(int a[][10], int nn)
    {
        n = nn;
        for (int i = 1; i <= n; i++)
        {
            v[i] = 0;
            bestv[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                adj[i][j] = a[i][j];
            }
        }
        v[1] = 1;
        currCost = 0;
        bestCost = 999;
        count = 1;
    }
    void Answer(int i)
    {
        if (count == n)
        {
            bestCost = min(bestCost, currCost + adj[i][1]);
            for (int i = 1; i <= n; i++)
            {
                bestv[i] = v[i];
            }
            return;
        }
        for (int j = 1; j <= n; j++)
        {
            if (v[j] == 0 && adj[i][j] != 0)
            {
                // Mark as visited
                v[j] = 1;
                currCost += adj[i][j];
                count++;
                Answer(j);
                // Mark as Unvsited
                v[j] = 0;
                currCost -= adj[i][j];
                count--;
            }
        }
    }
    void Display()
    {
        cout << "Minimum Cost Of Round Trip  = " << bestCost << endl;
        cout << "Trip Path -> ";
        for (int i = 1; i <= n; i++)
        {
            if (bestv[i] == 1)
            {
                cout << i << " -> ";
            }
        }
        cout << " 1";
    }
};

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
        cout << "Enter edge then cost" << i << " -> ";
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    Tsp M(adj, n);
    M.Answer(1);
    M.Display();
}