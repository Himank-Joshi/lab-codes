#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted arrays
vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> merged;
    int i = 0, j = 0;
    // Merge the two arrays by comparing the elements at the current indices
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            merged.push_back(arr1[i]);
            i++;
        }
        else
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    // Append any remaining elements from the two arrays
    while (i < arr1.size())
    {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size())
    {
        merged.push_back(arr2[j]);
        j++;
    }
    return merged;
}

// Function to merge K sorted arrays using Divide and Conquer
vector<int> mergeKSortedArrays(vector<vector<int>> &arrs, int start, int end)
{
    // Base case: if there is only one array, return that array
    if (start == end)
    {
        return arrs[start];
    }
    // Divide the problem into two subproblems
    int mid = (start + end) / 2;
    vector<int> left = mergeKSortedArrays(arrs, start, mid);
    vector<int> right = mergeKSortedArrays(arrs, mid + 1, end);
    // Combine the solutions of the subproblems
    return mergeSortedArrays(left, right);
}

int main()
{
    // Example usage
    vector<vector<int>> arrs = {{1, 3, 5, 7}, {2, 4, 6}, {0, 8, 9}};
    vector<int> merged = mergeKSortedArrays(arrs, 0, arrs.size() - 1);
    // Print the merged array
    cout << "Merged array: ";
    for (int i = 0; i < merged.size(); i++)
    {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
