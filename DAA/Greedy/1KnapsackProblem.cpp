#include <bits/stdc++.h>
using namespace std;

bool compareProfit(int a, int b)
{
    return b > a;
}

int main()
{

    cout << "Enter number of items : ";
    int n;
    cin >> n;
    cout << "For each item mention weight and profit :" << endl;
    int weight[n], profit[n], items[n];
    for (int i = 0; i < n; i++)
    {
        cout << "For Item " << i + 1 << ": ";
        cin >> weight[i];
        cin >> profit[i];
        items[i] = i + 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (profit[j + 1] > profit[j])
            {
                swap(profit[j], profit[j + 1]);
                swap(weight[j], weight[j + 1]);
                swap(items[j], items[j + 1]);
            }
        }
    }
    cout << "Enter capacity of bag :";
    int capacity;
    cin >> capacity;
    int num, weightSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] + weightSum <= capacity)
            weightSum += weight[i];
        else
        {
            num = i;
            break;
        }
    }
    cout << "Number of items put in bag = " << num << endl;
    cout << "Total weight put in bag = " << weightSum << endl;
    cout << "Items in bag " << endl;
    int prosum = 0;
    for (int i = 0; i < num; i++)
    {
        cout << "Item " << items[i] << " Weight = " << weight[i] << " Profit = " << profit[i] << endl;
        prosum += profit[i];
    }
    cout << "Total profit = " << prosum;
}
// How to sort in a particular order?
//  We can also write our own comparator function and pass it as a third parameter.
//   This “comparator” function returns a value; convertible to bool,
//   which basically tells us whether the passed “first” argument should be placed
//    before the passed “second” argument or not.