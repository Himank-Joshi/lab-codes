#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int profit[], int n)
{
    int i, j;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                // IMP
                K[i][j] = max(profit[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            }
            else
            {
                K[i][j] = K[i - 1][j];
            }
        }
    }
    i = n, j = W;
    cout << " Items in bag ->  ";
    while (i > 0 && W > 0)
    {
        if (K[i][j] == K[i - 1][j])
            i--;
        else
        {
            // include in sack
            cout << i << " ";
            j = j - wt[i];
            i--;
        }
    }

    return K[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Max value that can be put in a knapsack of capacity " << W << " is: " << knapSack(W, wt, val, n);
    return 0;
}
