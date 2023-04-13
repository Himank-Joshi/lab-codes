#include <iostream>
#include <climits>
using namespace std;

// Function to find the optimal order of multiplication
void matrixChainOrder(int p[], int n)
{
    // Create a table to store the minimum cost of multiplying each subsequence of matrices
    int m[n][n];

    // Initialize the diagonal elements to 0
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is the chain length
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    // Print the optimal cost
    cout << "Optimal cost is: " << m[1][n - 1] << endl;
}

// Driver code
int main()
{
    // Array p contains the dimensions of matrices
    int p[] = {10, 30, 5, 60};
    int n = sizeof(p) / sizeof(p[0]);

    matrixChainOrder(p, n);

    return 0;
}
