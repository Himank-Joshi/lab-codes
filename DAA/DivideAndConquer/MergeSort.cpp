#include <iostream>
using namespace std;

void SimpleMerge(int arr[], int low, int mid, int high)
{
    int result[20];
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            result[k++] = arr[i++];
        else
            result[k++] = arr[j++];
    }
    while (i <= mid)
        result[k++] = arr[i++];
    while (j <= high)
        result[k++] = arr[j++];
    // storing result back to original arr
    for (i = low; i <= high; i++)
        arr[i] = result[i];
}

void MergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        SimpleMerge(arr, low, mid, high);
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
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}