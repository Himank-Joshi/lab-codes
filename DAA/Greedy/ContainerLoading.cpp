#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter number of containers :";
    int n;
    cin >> n;
    cout << "Enter values of each container :";
    int weight[n];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter max capacity of platform :";
    int capacity;
    cin >> capacity;
    //  cout << "Sorting containers acc to weight";
    sort(weight, weight + n);
    int conatinerWeightSum = 0;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] + conatinerWeightSum <= capacity)
            conatinerWeightSum += weight[i];
        else
        {
            num = i;
            break;
        }
    }
    cout << "Total weight loaded = " << conatinerWeightSum << endl;
    cout << "Total number of containers = " << num << endl;
    for (int i = 0; i < num; i++)
        cout << weight[i] << " ";
}

// How to sort in a particular order?
//  We can also write our own comparator function and pass it as a third parameter.
//   This “comparator” function returns a value; convertible to bool,
//   which basically tells us whether the passed “first” argument should be placed
//    before the passed “second” argument or not.