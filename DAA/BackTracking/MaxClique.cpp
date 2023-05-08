#include <iostream>
using namespace std;
class MaxClique
{
    int adj[10][10], v[10], bestv[10], cn, bn, n;

public:
    MaxClique(int a[][10], int nn)
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
        cn = 0, bn = 0;
    }

    void Answer(int i)
    {
        if (i > n)
        {
            if (cn > bn)
            {
                for (int i = 1; i <= n; i++)
                {
                    bestv[i] = v[i];
                }
                bn = cn;
            }
            return;
        }
        bool Ok = true;
        for (int j = 1; j < i; j++)
        {
            if (v[j] && adj[i][j] == 0)
            {
                Ok = false;
                break;
            }
        }

        if (Ok)
        {
            v[i] = 1;
            cn++;
            Answer(i + 1);
            v[i] = 0;
            cn--;
        }
        Answer(i + 1);
    }
    void Display()
    {
        cout << "Size of Max Clique = " << bn << endl;
        cout << "Vertices of Max Clique -> ";
        for (int i = 1; i <= n; i++)
        {
            if (bestv[i] == 1)
            {
                cout << i << " ";
            }
        }
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
        cout << "Enter edges " << i << " -> ";
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    MaxClique M(adj, n);
    M.Answer(1);
    M.Display();
}