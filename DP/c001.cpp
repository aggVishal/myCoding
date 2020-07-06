#include <iostream>
#include <vector>
using namespace std;

// //mazepath series...

// int MP_jumps(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
// {
//     if (sr == er && sc == ec)
//     {
//         return dp[sr][sc] = 1;
//     }
//     if (dp[sr][sc] != 0)
//         return dp[sr][sc];

//     int count = 0;
//     int d = max(er - sr, ec - sc);
//     for (int i = 1; i <= d; i++)
//     {
//         if (sr + i <= er)
//         {
//             count += MP_jumps(sr + i, sc, er, ec, dp);
//         }
//         if (sc + i <= ec)
//         {
//             count += MP_jumps(sr, sc + i, er, ec, dp);
//         }
//         if (sr + i <= er && sc + i <= ec)
//         {
//             count += MP_jumps(sr + i, sc + i, er, ec, dp);
//         }
//     }
//     return dp[sr][sc] = count;
// }
// int MP_jumps_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
// {
//     for (int sr = er; sr >= 0; sr--)
//     {
//         for (sc = ec; sc >= 0; sc--)
//         {
//             if (sr == er && sc == ec)
//             {
//                 dp[sr][sc] = 1;
//                 continue;
//             }

//             int count = 0;
//             int d = max(er - sr, ec - sc);
//             for (int i = 1; i <= d; i++)
//             {
//                 if (sr + i <= er)
//                 {
//                     count += dp[sr + i][sc]; //MP_jumps(sr+i,sc,er,ec,dp);
//                 }
//                 if (sc + i <= ec)
//                 {
//                     count += dp[sr][sc + i]; //MP_jumps(sr,sc+i,er,ec,dp);
//                 }
//                 if (sr + i <= er && sc + i <= ec)
//                 {
//                     count += dp[sr + i][sc + i]; //MP_jumps(sr+i,sc,er,ec,dp);
//                 }
//             }
//             dp[sr][sc] = count;
//         }
//     }
//     return dp[0][0];
// }

// int dice(int s, int e, vector<int> &dp)
// {
//     if (s == e)
//     {
//         return dp[s] = 1;
//     }
//     if (dp[s] != 0)
//         return dp[s];
//     int count = 0;
//     for (int i = 1; i <= 6; i++)
//     {
//         if (s + i <= e)
//         {
//             count += dice(s + i, e, dp);
//         }
//     }
//     return dp[s] = count;
// }
// int dice_DP(int s, int e, vector<int> &dp)
// {
//     for (s = e; s >= 0; s--)
//     {
//         if (s == e)
//         {
//             dp[s] = 1;
//             continue;
//         }

//         int count = 0;
//         for (int i = 1; i <= 6; i++)
//         {
//             if (s + i <= e)
//             {
//                 count += dp[s + i];
//             }
//         }
//         dp[s] = count;
//     }
//     return dp[0];
// }

// int dice_random(int s, int e, vector<int> &ar, vector<int> &dp)
// {
//     if (s == e)
//     {
//         return dp[s] = 1;
//     }
//     if (dp[s] != 0)
//         return dp[s];
//     int count = 0;
//     for (int i = 0; i < ar.size(); i++)
//     {
//         if (s + ar[i] <= e)
//         {
//             count += dice_random(s + ar[i], e, ar, dp);
//         }
//     }
//     return dp[s] = count;
// }
// int dice_randomDP(int s, int e, vector<int> &ar, vector<int> &dp)
// {
//     for (s = e; s >= 0; s--)
//     {
//         if (s == e)
//         {
//             dp[s] = 1;
//             continue;
//         }
//         if (dp[s] != 0)
//             return dp[s];
//         int count = 0;
//         for (int i = 0; i < ar.size(); i++)
//         {
//             if (s + ar[i] <= e)
//             {
//                 count += dp[s + ar[i]];
//             }
//         }
//         dp[s] = count;
//     }
//     return dp[0];
// }

// //Leetcode 70. Climbing Stairs
// int helper(int s, int n, vector<int> &dp)
// {
//     if (s == n)
//         return dp[s] = 1;
//     if (dp[s] != 0)
//         return dp[s];

//     int count = 0;
//     if (s + 1 <= e)
//         count += helper(s + 1, e, dp);
//     if (s + 2 <= e)
//         count += helper(s + 2, e, dp);

//     return dp[s] = count;
// }
// int climbStairs(int n)
// {
//     vector<int> dp(n + 1);
//     return helper(0, n, dp);
// }

// // Leetcode 746. Min Cost Climbing Stairs
// int helper(int s, int n, vector<int> &cost, vector<int> &dp)
// {
//     if (s >= n - 2)
//     {
//         return dp[s] = cost[s];
//     }
//     if (dp[s] != 0)
//         return dp[s];
//     int count = min(helper(s + 1, n, cost, dp), helper(s + 2, n, cost, dp));
//     return dp[s] = (count + cost[s]);
// }
// int minCostClimbingStairs(vector<int> &cost)
// {
//     int n = cost.size();
//     vector<int> dp(n + 1);
//     helper(0, n, cost, dp);
//     return min(dp[0], dp[1]);
// }

//Leetcode

//https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

// https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/

//Substring and Subsequence Series.=========================================================================

vector<vector<bool>> isPalindrome_Substring(string str)
{
    vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), 0));
    for (int gap = 0; gap < str.size(); gap++)
    {
        for (int i = 0, j = gap; j < str.size(); j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (gap == 1 && str[i] == str[j])
            {
                dp[i][j] = true;
            }
            else if (str[i] == str[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
            }
        }
    }
    return dp;
}

//Leetcode 5. Longest Palindromic Substring
string longestPalindrome(string s)
{
    int n = s.size();
    int si = 0, ei = 0;
    int maxlen = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1 && s[i] == s[j])
            {
                dp[i][j] = gap + 2;
            }
            else if (s[i] == s[j] && dp[i + 1][j - 1] != 0)
            {
                dp[i][j] = gap + 2;
            }
            if (dp[i][j] > maxlen)
            {
                maxlen = dp[i][j];
                si = i;
                ei = j;
            }
        }
    }
    return s.substr(si, (ei - si + 1));
}

//Leetcode 647. Palindromic Substrings
int countSubstrings(string str)
{
    vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), 0));
    int ans = 0;
    for (int gap = 0; gap < str.size(); gap++)
    {
        for (int i = 0, j = gap; j < str.size(); j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
                ans++;
            }
            else if (gap == 1 && str[i] == str[j])
            {
                dp[i][j] = true;
                ans++;
            }
            else if (str[i] == str[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                ans++;
            }
        }
    }
    return ans;
}

//leetcode 516. Longest Palindromic Subsequence
int longestPalindromeSubseq_(int s, int e, string &str, vector<vector<int>> &dp)
{
    if (s > e)
        return 0;
    if (dp[s][e] != 0)
        return dp[s][e];
    if (s == e)
    {
        return dp[s][e] = 1;
    }

    int len = 0;
    if (str[s] == str[e])
    {
        len = 2 + longestPalindromeSubseq_(s + 1, e - 1, str, dp);
    }
    else
    {
        len = max(longestPalindromeSubseq_(s + 1, e, str, dp), longestPalindromeSubseq_(s, e - 1, str, dp));
    }
    return dp[s][e] = len;
}

int longestPalindromeSubseq_REC(string s)
{
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    return longestPalindromeSubseq_(0, s.size() - 1, s, dp);
}
//****************************************************************************
int longestPalindromeSubseq_DP(string &s)
{
    int n = s.size();
    vector<vector<long>> dp(n, vector<long>(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if (s[i] == s[j])
            {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

//Leetcode 115. Distinct Subsequences
int numDistinct_(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (j == 0)
    {
        return dp[i][j] = 1;
    }
    if (i < j)
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int count;
    if (s[i - 1] == t[j - 1])
    {
        count = numDistinct_(i - 1, j - 1, s, t, dp) + numDistinct_(i - 1, j, s, t, dp);
    }
    else
    {
        count = numDistinct_(i - 1, j, s, t, dp);
    }
    return dp[i][j] = count;
}
int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    return numDistinct_(s.size(), t.size(), s, t, dp);
}
//********************************************
int numDistinct(string &s, string &t)
{
    vector<vector<long>> dp(s.size() + 1, vector<long>(t.size() + 1, -1));
    for (int i = 0; i <= s.size(); i++)
    {
        for (int j = 0; j <= t.size(); j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if (i < j)
            {
                dp[i][j] = 0;
                continue;
            }
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s.size()][t.size()];
} //**************************************************************************

//Geeks: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
int countPS_(int i, int j, string &str, vector<vector<int>> &dp)
{
    if (i > j)
        return dp[i][j] = 0;
    if (i == j)
    {
        return dp[i][j] = 1;
    }
    if (dp[i][j] != 0)
        return dp[i][j];

    int middle = countPS_(i + 1, j - 1, str, dp);
    int left = countPS_(i, j - 1, str, dp);
    int right = countPS_(i + 1, j, str, dp);

    int ans = left + right;
    return dp[i][j] = (str[i] == str[j]) ? ans + 1 : ans - middle;
}

int countPS_REC(string str)
{
    vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));
    return countPS_(0, str.size() - 1, str, dp);
}
//********************************************************************************

//******************************************************************************
//Leetcode 1143: Longest Common Subsequence
int longestCommonSubsequence_(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (i == text1.size() || j == text2.size())
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != 0)
        return dp[i][j];
    int len = 0;
    if (text1[i] == text2[j])
    {
        len = longestCommonSubsequence_(i + 1, j + 1, text1, text2, dp) + 1;
    }
    else
    {
        len = max(longestCommonSubsequence_(i + 1, j, text1, text2, dp), longestCommonSubsequence_(i, j + 1, text1, text2, dp));
    }
    return dp[i][j] = len;
}
int longestCommonSubsequence(string &text1, string &text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    return longestCommonSubsequence_(0, 0, text1, text2, dp);
}

//*******************************************************************************
int longestCommonSubsequence_DP(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = text1.size(); i >= 0; i--)
    {
        for (int j = text2.size(); j >= 0; j--)
        {
            if (i == text1.size() || j == text2.size())
            {
                dp[i][j] = 0;
                continue;
            }
            int len = 0;
            if (text1[i] == text2[j])
            {
                len = dp[i + 1][j + 1] + 1;
            }
            else
            {
                len = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = len;
        }
    }
    return dp[0][0];
}
//****************************************************************

//Leetcode 1035. Uncrossed Lines
int helper(int i, int j, vector<int> &A, vector<int> &B, vector<vector<int>> &dp)
{
    if (i == A.size() || j == B.size())
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (A[i] == B[j])
    {
        return dp[i][j] = helper(i + 1, j + 1, A, B, dp) + 1;
    }
    return dp[i][j] = max(helper(i + 1, j, A, B, dp), helper(i, j + 1, A, B, dp));
}
int maxUncrossedLines(vector<int> &A, vector<int> &B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    return helper(0, 0, A, B, dp);
}

//************************************************************************
int maxUncrossedLines_DP(vector<int> &A, vector<int> &B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    for (int i = A.size() - 1; i >= 0; i--)
    {
        for (int j = B.size() - 1; j >= 0; j--)
        {
            if (i == A.size() || j == B.size())
            {
                dp[i][j] = 0;
                continue;
            }
            int len;
            if (A[i] == B[j])
            {
                len = dp[i + 1][j + 1] + 1;
            }
            else
            {
                len = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = len;
        }
    }
    return dp[0][0];
}
//***************************************************

//Leetcode 1458
int maxDotProduct_(int i, int j, vector<int> &num1, vector<int> &num2, vector<vector<int>> &dp)
{
    if (i == num1.size() || j == num2.size())
    {
        return dp[i][j] = -1e8;
    }
    if (dp[i][j] != 0)
        return dp[i][j];

    int val = num1[i] * num2[j];
    int a = maxDotProduct_(i + 1, j + 1, num1, num2, dp) + val;
    int b = maxDotProduct_(i + 1, j, num1, num2, dp);
    int c = maxDotProduct_(i, j + 1, num1, num2, dp);
    return dp[i][j] = max(max(val, a), max(c, b));
}

int maxDotProduct(vector<int> &num1, vector<int> &num2)
{
    vector<vector<int>> dp(num1.size() + 1, vector<int>(num2.size() + 1, 0));
    return maxDotProduct_(0, 0, num1, num2, dp);
}
//***************************************************
int maxDotProduct_DP(vector<int> &num1, vector<int> &num2)
{
    vector<vector<int>> dp(num1.size() + 1, vector<int>(num2.size() + 1, -1));
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        for (int j = num2.size() - 1; j >= 0; j--)
        {
            if (i == num1.size() || j == num2.size())
            {
                dp[i][j] = -1e8;
                continue;
            }
            if (dp[i][j] != 0)
                dp[i][j];
            continue;

            int val = num1[i] * num2[j];
            int a = dp[i + 1][j + 1] + val;
            int b = dp[i + 1][j];
            int c = dp[i][j + 1];
            dp[i][j] = max(max(val, a), max(c, b));
        }
    }
    return dp[0][0];
}

//Leetcode 72. Edit Distance
int minDist(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    if (j == word2.size())
        return dp[i][j] = word1.size() - i;
    if (i == word1.size())
        return dp[i][j] = word2.size() - j;
    if (dp[i][j] != 0)
        return dp[i][j];

    if (word1[i] == word2[j])
        return dp[i][j] = minDist(i + 1, j + 1, word1, word2, dp);

    int insert = minDist(i, j + 1, word1, word2, dp);
    int replace = minDist(i + 1, j + 1, word1, word2, dp);
    int del = minDist(i + 1, j, word1, word2, dp);

    return dp[i][j] = min(insert, min(del, replace)) + 1;
}
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    return minDist(0, 0, word1, word2, dp);
}

//Coin Change/Target Type problems
int coinChangePermutation(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0)
    {
        return dp[tar] = 1;
    }
    if (dp[tar] != 0)
        return dp[tar];
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinChangePermutation(arr, tar - arr[i], dp);
        }
    }
    return dp[tar] = count;
}

int coinChangePermutation_DP(vector<int> &arr, int tar)
{
    vector<int> dp(tar + 1);
    for (int i = 0; i <= tar; i++)
    {
        if (i == 0)
        {
            dp[i] == 1;
            continue;
        }
        int count = 0;
        for (int x = 0; x < arr.size(); x++)
        {
            if (i - arr[x] >= 0)
                count += dp[i - arr[x]];
        }
        dp[i] = count;
    }
    return dp[tar];
}

int coinChangeCombination_DP(vector<int> &arr, int tar) // by normal way it is done by using 2D dp but this is an optimised version
{                                                       // with Infinite coins of each
    vector<int> dp(tar + 1);
    dp[0] = 1;
    for (int ele : arr)
    {
        for (int i = ele; i <= tar; i++) //normally loop is started from 0
        {
            if (i - ele >= 0)
            {
                dp[i] += dp[i - ele];
            }
        }
    }
    return dp[tar];
}

//https://www.geeksforgeeks.org/find-number-of-solutions-of-a-linear-equation-of-n-variables/

int LinearEquation_DP(vector<int> &arr, int tar)
{
    vector<int> dp(tar + 1);
    dp[0] = 1;
    for (int ele : arr)
    {
        for (int i = ele; i <= tar; i++)
        {
            if (i - ele >= 0)
            {
                dp[i] += dp[i - ele];
            }
        }
    }
    return dp[tar];
}

//Leetcode 322 Coin Change
int coinChange_(vector<int> &coins, int tar, vector<int> &dp)
{
    if (tar == 0)
        return dp[tar] = 0;

    if (dp[tar] != 0)
        return dp[tar];

    int h = 1e8;
    for (int i = 0; i < coins.size(); i++)
    {
        if (tar - coins[i] >= 0)
        {
            h = min(h, coinChange_(coins, tar - coins[i], dp));
        }
    }
    return dp[tar] = h + 1;
}
int coinChange(vector<int> &coins, int tar)
{
    vector<int> dp(tar + 1);
    int ans = coinChange_(coins, tar, dp);
    return (ans >= 1e8) ? -1 : ans;
}
//*******************************************************************************************

// Finite coins and Number of combinations
int targetSum(int tar, int idx, vector<int> &arr, vector<vector<int>> &dp)
{
    if (tar == 0 || idx == arr.size())
    {
        if (tar == 0)
            return dp[idx][tar] = 1;
        return dp[idx][tar] = 0;
    }

    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;
    if (tar - arr[idx] >= 0)
    {
        count += targetSum(tar - arr[idx], idx + 1, arr, dp);
    }
    count += targetSum(tar, idx + 1, arr, dp);
    return dp[idx][tar] = count;
}

int targetSum_02(int tar, int idx, vector<int> &arr, vector<vector<int>> &dp)
{ // We are traversing reverse array
    if (tar == 0 || idx == 0)
    {
        if (tar == 0)
            return dp[idx][tar] = 1;
        return dp[idx][tar] = 0;
    }
    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;
    if (tar - arr[idx - 1] >= 0)
    {
        count += targetSum_02(tar - arr[idx - 1], idx - 1, arr, dp);
    }
    count += targetSum_02(tar, idx - 1, arr, dp);
    return dp[idx][tar] = count;
}

int printPathOfTargetSum(int tar, int idx, vector<int> &arr, vector<vector<bool>> &dp, string ans)
{ //Back engine
    if (tar == 0 || idx == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return dp[idx][tar] = 1;
        }
        return dp[idx][tar] = 0;
    }
    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;
    if (tar - arr[idx - 1] >= 0 && dp[idx - 1][tar - arr[idx - 1]])
    {
        count += printPathOfTargetSum(tar - arr[idx - 1], idx - 1, arr, dp, ans + to_string(arr[idx - 1]));
    }
    if (dp[idx - 1][tar])
    {
        count += printPathOfTargetSum(tar, idx - 1, arr, dp, ans);
    }
    return dp[idx][tar] = count;
}

// using DP, traversing reverse, printing path by back engine
void targetSum_02DP(vector<int> &coins, int tar)
{
    int Tar = tar;
    vector<vector<bool>> dp(coins.size() + 1, vector<bool>(tar + 1, false));
    for (int idx = 0; idx <= coins.size(); idx++)
    {
        for (for (tar = 0; tar <= Tar; tar++))
        {
            if (tar == 0 || idx == 0)
            {
                if (tar == 0)
                {
                    dp[idx][tar] = true;
                }
                continue;
            }
            if (dp[idx][tar] != 0)
            {
                dp[idx][tar];
                continue;
            }
            int res = false;
            if (tar - arr[idx - 1] >= 0)
            {
                dp[idx][tar] = dp[idx - 1][tar - arr[idx - 1]];
            }

            dp[idx][tar] = dp[idx][tar] || dp[idx - 1][tar];
        }
    }
    cout << printPathOfTargetSum(coins, coins.size(), Tar, "", dp) << endl;
}

// Knapsack 0-1 Problem (GFG) ========================================================================
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
int knapsack01(vector<int> &w, vector<int> &v, int weight, int n, vector<vector<int>> &dp)
{
    if (weight == 0 || n == 0)
    {
        return dp[n][weight] = 0;
    }
    if (dp[n][weight] != 0)
        return dp[n][weight];

    int maxval = 0;
    if (weight - w[n - 1] >= 0)
    {
        maxval = max(maxval, knapsack01(w, v, weight - w[n - 1], n - 1, dp) + v[n - 1]);
    }
    maxval = max(maxval, knapsack01(w, v, weight, n - 1, dp));
    return dp[n][weight] = maxval;
}

// Unbounded knapsack = knapsack 0-1  +  infinite coins
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
int unbounded_Knapsack_2D_dp(vector<int> &w, vector<int> &v, int weight, int n, vector<vector<int>> &dp) // using 2D dp
{
    if (weight == 0 || n == 0)
    {
        return dp[n][weight] = 0;
    }
    if (dp[n][weight] != 0)
        return dp[n][weight];

    int maxval = 0;
    if (weight - w[n - 1] >= 0)
    {
        maxval = max(maxval, max(unbounded_Knapsack(w, v, weight - w[n - 1], n - 1, dp) + v[n - 1], unbounded_Knapsack(w, v, weight - w[n - 1], n, dp) + v[n - 1]));
    }
    maxval = max(maxval, unbounded_Knapsack(w, v, weight, n - 1, dp));
    return dp[n][weight] = maxval;
}

int unbounded_Knapsack_1D_dp(vector<int> &w, vector<int> &v, int weight) // using 1D dp (optimised)
{                                                                        // dry run question (you cannot understand by only see code)
    vector<int> dp(weight + 1);
    dp[0] = 0;
    for (int i = 0; i < w.size(); i++)
    {
        for (int we = w[i]; we <= weight; we++) //normally loop is started from 0
        {
            if (we - w[i] >= 0)
            {
                dp[we] = max(dp[we], dp[we - w[i]] + v[we]);
            }
        }
    }
    return dp[weight];
}

//Leetcode 416. Partition Equal Subset Sum
int knapsack0_1(vector<int> &nums, int idx, int sum, vector<vector<int>> &dp)
{
    if (sum == 0 || idx == 0)
    {
        if (sum == 0)
            return dp[idx][sum] = 1;
        return dp[idx][sum] = 0;
    }
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    bool res = false;
    if (sum - nums[idx - 1] >= 0)
    {
        res = res || knapsack0_1(nums, idx - 1, sum - nums[idx - 1], dp);
    }
    res = res || knapsack0_1(nums, idx - 1, sum, dp);
    return dp[idx][sum] = res;
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i : nums)
    {
        sum += i;
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    sum /= 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
    return knapsack0_1(nums, nums.size(), sum, dp);
}
//Leetcode 494. Target Sum
int knapsack_(vector<int> &nums, int tar, int osum, int sum, int idx, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (tar == osum)
            return dp[idx][tar + sum] = 1;
        return dp[idx][sum + tar] = 0;
    }
    if (dp[idx][sum + tar] != -1)
        return dp[idx][sum + tar];

    int pos = knapsack_(nums, tar + nums[idx - 1], osum, sum, idx - 1, dp);
    int neg = knapsack_(nums, tar - nums[idx - 1], osum, sum, idx - 1, dp);

    return dp[idx][sum + tar] = pos + neg;
}
int findTargetSumWays(vector<int> &nums, int osum)
{
    int sum = 0;
    for (int i : nums)
    {
        sum += i;
    }
    vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * sum + 1, -1));
    return knapsack_(nums, 0, osum, sum, nums.size(), dp);
}

//********************************************************************************

// Lonogest Increasing Subsequence type
int LIS_leftToRight(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1);
    int Omax = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        Omax = max(Omax, dp[i]);
    }
    return Omax;
}
int LDS_RightToLeft(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1);
    int Omax = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        dp[i] = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        Omax = max(Omax, dp[i]);
    }
    return Omax;
}
int LIS_RightToLeft(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1);
    int Omax = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        dp[i] = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        Omax = max(Omax, dp[i]);
    }
    return Omax;
}
int LDS_leftToRight(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1);
    int Omax = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] > nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        Omax = max(Omax, dp[i]);
    }
    return Omax;
}

int bitonic(vector<int> &nums)
{
    int N = nums.size();
    vector<int> lis_L2R(N);
    vector<int> lis_R2L(N);
    int Omax = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        lis_L2R[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                lis_L2R[i] = max(lis_L2R[i], lis_L2R[j] + 1);
            }
        }
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        lis_R2L[i] = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
            {
                lis_R2L[i] = max(lis_R2L[i], lis_R2L[j] + 1);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        Omax = max(Omax, lis_R2L[i] + lis_L2R[i] - 1);
    }
    return Omax;
}

int INV_bitonic(vector<int> &nums)
{
    int N = nums.size();
    vector<int> lds_L2R(N);
    vector<int> lds_R2L(N);
    int Omax = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        lds_L2R[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] > nums[i])
            {
                lds_L2R[i] = max(lds_L2R[i], lds_L2R[j] + 1);
            }
        }
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        lds_R2L[i] = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[i])
            {
                lds_R2L[i] = max(lds_R2L[i], lds_R2L[j] + 1);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        Omax = max(Omax, lds_R2L[i] + lds_L2R[i] - 1);
    }
    return Omax;
}

int LIS_leftToRight(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1);
    vector<int> no(nums.size() + 1);
    int Omax = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                // dp[i] = max(dp[i], dp[j] + 1);
                if (dp[i] == dp[j] + 1)
                {
                    ` no[j]++;
                }
                else if (dp[i] < dp[j] + 1)
                {
                    no[j] = 1;
                    dp[i] = dp[j] + 1;
                }
            }
        }
        Omax = max(Omax, dp[i]);
    }
    return Omax;
}
void solve()
{
    // int n = 10;
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // vector<int> dp(n + 1, 0);
    // cout << MP_jumps(0, 0, n - 1, n - 1, dp) << endl;
    // cout << MP_jumps_DP(0, 0, n - 1, n - 1, dp) << endl;

    // cout << dice(0, n, dp);
    // cout << dice_DP(0, n, dp);
    // vector<int> ar = {1, 3, 5, 6};
    // cout << dice_random(0, n, ar, dp);
    // cout << dice_randomDP(0, n, ar, dp);

    // cout << partition_in_K_subset(3, 2);
    vector<int> arr = {1, 2, 5, 8, 6, 1, 1, 0, 50, 4, 18};
    cout << INV_bitonic(arr) << endl;
}
int main()
{
    solve();
}

//   git add -A&git commit -m "update"&git push origin master