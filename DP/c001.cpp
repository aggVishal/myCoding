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

int countPS-REC(string str)
{
    vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));
    return countPS_(0, str.size() - 1, str, dp);
}
//********************************************************************************



//******************************************************************************
//Leetcode 1143: Longest Common Subsequence
int longestCommonSubsequence(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
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
        len = longestCommonSubsequence(i + 1, j + 1, text1, text2, dp) + 1;
    }
    else
    {
        len = max(longestCommonSubsequence(i + 1, j, text1, text2, dp), longestCommonSubsequence(i, j + 1, text1, text2, dp));
    }
    return dp[i][j] = len;
}
//*******************************************************************************
int longestCommonSubsequence_DP(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
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
int helper(int i, int j, vector<int> &num1, vector<int> &num2, vector<vector<int>> &dp)
{
    if (i == num1.size() || j == num2.size())
    {
        return dp[i][j] = -1e8;
    }
    if (dp[i][j] != 0)
        return dp[i][j];

    int val = num1[i] * num2[j];
    int a = helper(i + 1, j + 1, num1, num2, dp) + val;
    int b = helper(i + 1, j, num1, num2, dp);
    int c = helper(i, j + 1, num1, num2, dp);
    return dp[i][j] = max(max(val, a), max(c, b));
}

int maxDotProduct(vector<int> &num1, vector<int> &num2)
{
    vector<vector<int>> dp(num1.size() + 1, vector<int>(num2.size() + 1, 0));
    return helper(0, 0, num1, num2, dp);
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

void solve()
{
    int n = 10;
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
}
int main()
{
    solve();
}