#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//cut Type problems
int MCM_rec(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    if (si + 1 == ei)
    {
        return dp[si][ei] = 0;
    }

    if (dp[si][ei] != -1)
        return dp[si][ei];

    int ans = 1e8;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int leftMatrix = MCM_rec(arr, si, cut, dp);
        int rightMatrix = MCM_rec(arr, cut, ei, dp);
        int cost = leftMatrix + (arr[si] * arr[cut] * arr[ei]) + rightMatrix;
        ans = min(ans, cost);
    }
    return dp[si][ei] = ans;
}
int MCM_dp(vector<int> &arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
    for (int gap = 1; gap < arr.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {
            if (si + 1 == ei)
            {
                dp[si][ei] = 0;
                continue;
            }

            int ans = 1e8;
            for (int cut = si + 1; cut < ei; cut++)
            {
                int leftMatrix = MCM_rec(arr, si, cut, dp);
                int rightMatrix = MCM_rec(arr, cut, ei, dp);
                int cost = leftMatrix + (arr[si] * arr[cut] * arr[ei]) + rightMatrix;
                ans = min(ans, cost);
            }
            dp[si][ei] = ans;
        }
    }
    return dp[0][arr.size()-1];
}

// Optimal Binary Search Tree
// https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/
int Optimal_BST(vector<int> &arr, vector<int> freq, int si, int ei, int level, vector<vector<int>> &dp)
{
    if (si + 1 == ei)
    {
        return dp[si][ei] = freq[si] * level;
    }

    if (dp[si][ei] != -1)
        return dp[si][ei];

    int ans = 1e8;
    for (int cut = si; cut <= ei; cut++)
    {
        int leftMatrix = (si == cut) ? 0 : Optimal_BST(arr, freq, si, cut - 1, level + 1, dp);
        int rightMatrix = (ei == cut) ? 0 : Optimal_BST(arr, freq, cut + 1, ei, level + 1, dp);
        int cost = leftMatrix + (freq[cut] * level) + rightMatrix;
        ans = min(ans, cost);
    }
    return dp[si][ei] = ans;
}

// Leetcode 312