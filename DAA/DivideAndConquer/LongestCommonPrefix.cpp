#include <iostream>
#include <vector>

using namespace std;

// Function to find the longest common prefix using Divide and Conquer
string longestCommonPrefix(vector<string> &strs, int start, int end)
{
    // Base case: if there is only one string, return that string
    if (start == end)
    {
        return strs[start];
    }

    // Divide the problem into two subproblems
    int mid = (start + end) / 2;
    string left = longestCommonPrefix(strs, start, mid);
    string right = longestCommonPrefix(strs, mid + 1, end);

    // Combine the solutions of the subproblems
    int i = 0;
    while (i < left.length() && i < right.length() && left[i] == right[i])
    {
        i++;
    }

    return left.substr(0, i);
}

int main()
{
    // Example usage
    vector<string> strs = {"flower", "flow", "flight"};
    string lcp = longestCommonPrefix(strs, 0, strs.size() - 1);
    cout << "Longest common prefix: " << lcp << endl;

    return 0;
}
