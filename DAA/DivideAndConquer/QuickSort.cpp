#include <iostream>
using namespace std;

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    bool stop = false;
    while (!stop)
    {
        while (arr[i] <= pivot && i < high)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
        else
        {
            swap(arr[low], arr[j]);
            stop = true;
        }
    }
    return j;
}

void QuickSort(int arr[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

int main()
{
    cout << " Enter size of array ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter elements ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}