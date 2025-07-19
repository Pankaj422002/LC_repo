// You are given an integer array nums.
// A subsequence sub of nums with length x is called valid if it satisfies:

// (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
// Return the length of the longest valid subsequence of nums.

// A subsequence is an array that can be derived from another array by deleting some or n o elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [1,2,3,4]

// Output: 4

// Explanation:

// The longest valid subsequence is [1, 2, 3, 4].


#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &nums){
    for(auto it: nums)cout<<it<<" ";
    cout<<endl;
}

int LongestSubsequence(vector<int> &nums)
{

    int n = nums.size(), zeroCount = 0, oneCount = 0;

    for (auto &it : nums)
    {
        it = it % 2;
        if (it == 0)
            zeroCount++;
        else
            oneCount++;
    }
    int ans = max(zeroCount, oneCount);

    int prev = -1, curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != prev || prev == -1)
        {
            prev = nums[i];
            curr++;
        }
    }
    ans = max(ans, curr);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << LongestSubsequence(arr) << endl;

    return 0;
}
