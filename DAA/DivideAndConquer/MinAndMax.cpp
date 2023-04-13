// https://www.youtube.com/watch?v=GVFXYrMRqFw&t=611s

#include <iostream>
using namespace std;

// Structure to store minimum and maximum values
struct MinMax
{
    int min;
    int max;
};

// Function to find the minimum and maximum values in an array using divide and conquer technique
MinMax findMinMax(int arr[], int low, int high)
{
    MinMax result, leftResult, rightResult;
    int mid;

    // If there is only one element
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If there are two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            result.max = arr[low];
            result.min = arr[high];
        }
        else
        {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    // If there are more than two elements, divide the array in two parts
    mid = (low + high) / 2;
    leftResult = findMinMax(arr, low, mid);
    rightResult = findMinMax(arr, mid + 1, high);

    // Compare minimums and maximums of two parts
    if (leftResult.min < rightResult.min)
        result.min = leftResult.min;
    else
        result.min = rightResult.min;

    if (leftResult.max > rightResult.max)
        result.max = leftResult.max;
    else
        result.max = rightResult.max;

    return result;
}

// Driver program to test the above function
int main()
{
    cout << "Enter size of array : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter elements :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum element in the array is " << result.min << endl;
    cout << "Maximum element in the array is " << result.max << endl;

    return 0;
}
