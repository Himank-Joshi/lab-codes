#include <iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Task
{
public:
    int start, finish;
};
bool Comparetasks(Task t1, Task t2)
{
    return (t1.start < t2.start);
}
void printtasks(Task arr[], int n)
{
    sort(arr, arr + n, Comparetasks);
    int i = 0;
    bool selected[n];
    for (i = 0; i < n; i++)
        selected[i] = false;
    int k = 0, j;
    for (i = 0; i < n; i++)
    {
        if (selected[i])
            continue;
        cout << "========================================";
        cout << "\n"
             << " Task Allocation : For Machine " << k + 1 << "\n";
        cout << "(" << arr[i].start << ", " << arr[i].finish << ")"
             << "\n";

        for (j = i + 1; j < n; j++)
        {
            if (selected[j])
                continue;
            if (arr[i].finish <= arr[j].start)
            {
                i = j;
                selected[j] = 1;
                cout << "(" << arr[j].start << "," << arr[j].finish << ")"
                     << "\n";
            }
        }
        // k++;
        i = ++k;
        cout << "========================================";
    }
    cout << "\n"
         << "Total Machines Used " << k;
}
int main()
{
    Task arr[10];
    int n;
    cout << "Enter the number of Total Number Tasks";
    cin >> n;
    cout << "Enter Start and Finish time of each machine";
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].finish;
    printtasks(arr, n);
    return 0;
}
