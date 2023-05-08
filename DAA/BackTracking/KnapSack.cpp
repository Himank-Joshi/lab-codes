#include <iostream>
using namespace std;

class Knap
{
    int capacity, n, w[10], p[10], cw, cp, bestp;

public:
    Knap()
    {
        cout << "Enter Capacity of Sack  ";
        cin >> capacity;
        cout << "Enter number of bags ";
        cin >> n;
        cout << "Enter Weight then Profit " << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << "Bag " << i << " -> ";
            cin >> w[i] >> p[i];
        }
        cw = 0, cp = 0, bestp = 0;
    }
    void KnapSack(int i)
    {
        if (i > n)
        {
            if (cp > bestp)
                bestp = cp;
            return;
        }
        if (cw + w[i] <= capacity)
        {
            // Include Bag i
            cw += w[i];
            cp += p[i];
            KnapSack(i + 1);
            // Remove Bag i
            cw -= w[i];
            cp -= p[i];
        }
        if (upperBound(i + 1) > bestp)
            KnapSack(i + 1);
    }
    float upperBound(int i)
    {
        int bound = cp;
        int cleft = capacity - cw;
        while (i <= n && w[i] <= cleft)
        {
            cleft -= w[i];
            bound += p[i];
            i++;
        }
        if (i <= n)
        {
            bound += (p[i] / w[i]) * cleft;
        }
        return bound;
    }

    void display()
    {
        cout << "Max Profit = " << bestp;
    }
};

int main()
{
    Knap k;
    k.KnapSack(1);
    k.display();
}