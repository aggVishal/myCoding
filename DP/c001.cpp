#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

void display2D(vector<vector<int>> &arr)
{
    for (vector<int> ar : arr)
        display(ar);
    cout << endl;
}

// fibonacci sequence

int fibo_rec(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo_rec(n - 1, dp) + fibo_rec(n - 2, dp);
}
int fibo_dp(int n)
{
    vector<int> dp(n + 1, -1);
    for (int i = 0; i <= n; i++)
    {
        if (n <= 1)
        {
            dp[n] = n;
            continue;
        }
        dp[n] = dp[n - 1] + dp[n - 2];
    }
}
int fibo_btr(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

//mazepath series...

int MP_jumps(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
    {
        return dp[sr][sc] = 1;
    }
    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int count = 0;
    int d = max(er - sr, ec - sc);
    for (int i = 1; i <= d; i++)
    {
        if (sr + i <= er)
        {
            count += MP_jumps(sr + i, sc, er, ec, dp);
        }
        if (sc + i <= ec)
        {
            count += MP_jumps(sr, sc + i, er, ec, dp);
        }
        if (sr + i <= er && sc + i <= ec)
        {
            count += MP_jumps(sr + i, sc + i, er, ec, dp);
        }
    }
    return dp[sr][sc] = count;
}
int MP_jumps_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    for (int sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            int d = max(er - sr, ec - sc);
            for (int i = 1; i <= d; i++)
            {
                if (sr + i <= er)
                {
                    count += dp[sr + i][sc]; //MP_jumps(sr+i,sc,er,ec,dp);
                }
                if (sc + i <= ec)
                {
                    count += dp[sr][sc + i]; //MP_jumps(sr,sc+i,er,ec,dp);
                }
                if (sr + i <= er && sc + i <= ec)
                {
                    count += dp[sr + i][sc + i]; //MP_jumps(sr+i,sc,er,ec,dp);
                }
            }
            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}

int dice(int s, int e, vector<int> &dp)
{
    if (s == e)
    {
        return dp[s] = 1;
    }
    if (dp[s] != 0)
        return dp[s];
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (s + i <= e)
        {
            count += dice(s + i, e, dp);
        }
    }
    return dp[s] = count;
}
int dice_DP(int s, int e, vector<int> &dp)
{
    for (s = e; s >= 0; s--)
    {
        if (s == e)
        {
            dp[s] = 1;
            continue;
        }

        int count = 0;
        for (int i = 1; i <= 6; i++)
        {
            if (s + i <= e)
            {
                count += dp[s + i];
            }
        }
        dp[s] = count;
    }
    return dp[0];
}

int dice_random(int s, int e, vector<int> &ar, vector<int> &dp)
{
    if (s == e)
    {
        return dp[s] = 1;
    }
    if (dp[s] != 0)
        return dp[s];
    int count = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        if (s + ar[i] <= e)
        {
            count += dice_random(s + ar[i], e, ar, dp);
        }
    }
    return dp[s] = count;
}
int dice_randomDP(int s, int e, vector<int> &ar, vector<int> &dp)
{
    for (s = e; s >= 0; s--)
    {
        if (s == e)
        {
            dp[s] = 1;
            continue;
        }
        if (dp[s] != 0)
            return dp[s];
        int count = 0;
        for (int i = 0; i < ar.size(); i++)
        {
            if (s + ar[i] <= e)
            {
                count += dp[s + ar[i]];
            }
        }
        dp[s] = count;
    }
    return dp[0];
}

//Leetcode 70. Climbing Stairs
int climbStairs_(int s, int e, vector<int> &dp)
{
    if (s == e)
        return dp[s] = 1;
    if (dp[s] != 0)
        return dp[s];

    int count = 0;
    if (s + 1 <= e)
        count += climbStairs_(s + 1, e, dp);
    if (s + 2 <= e)
        count += climbStairs_(s + 2, e, dp);

    return dp[s] = count;
}
int climbStairs(int n)
{
    vector<int> dp(n + 1);
    return climbStairs_(0, n, dp);
}

// Leetcode 746. Min Cost Climbing Stairs
int helper(int s, int n, vector<int> &cost, vector<int> &dp)
{
    if (s >= n - 2)
    {
        return dp[s] = cost[s];
    }
    if (dp[s] != 0)
        return dp[s];
    int count = min(helper(s + 1, n, cost, dp), helper(s + 2, n, cost, dp));
    return dp[s] = (count + cost[s]);
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1);
    helper(0, n, cost, dp);
    return min(dp[0], dp[1]);
}

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
int coinChangeCombination_DP(vector<int> &arr, int tar, vector<int> &dp) // finite coin combination using 1D dp
{                                                                        // dry run question
    dp[0] = 1;
    int Tar = tar;
    for (int ele : arr)
        for (int tar = Tar; tar >= ele; tar--)
            dp[tar] += dp[tar - ele];
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

//---------------------------------------------------------------------------------------------------------------------------------------

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

int printPathOfTargetSum(vector<int> &arr, int idx, int tar, string ans, vector<vector<bool>> &dp)
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
        count += printPathOfTargetSum(arr, idx - 1, tar - arr[idx - 1], ans + to_string(arr[idx - 1]), dp);
    }
    if (dp[idx - 1][tar])
    {
        count += printPathOfTargetSum(arr, idx - 1, tar, ans, dp);
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
        for (tar = 0; tar <= Tar; tar++)
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
            if (tar - coins[idx - 1] >= 0)
            {
                dp[idx][tar] = dp[idx - 1][tar - coins[idx - 1]];
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
        maxval = max(maxval, max(unbounded_Knapsack_2D_dp(w, v, weight - w[n - 1], n - 1, dp) + v[n - 1], unbounded_Knapsack_2D_dp(w, v, weight - w[n - 1], n, dp) + v[n - 1]));
    }
    maxval = max(maxval, unbounded_Knapsack_2D_dp(w, v, weight, n - 1, dp));
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
//******************************************************************************

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

//------------------------------------------------------------------------------------------------------------------------------

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
//************************

// Longest Bitonic Subsequence (LBS)

int bitonic(vector<int> &nums) // https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0
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

int INV_bitonic(vector<int> &nums) // you can check the notes
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

// Maximum sum increasing subsequence
// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
int max_sum_inc_subseq(vector<int> &ar)
{
    int N = ar.size();
    vector<int> dp(N);
    int maxSum = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = ar[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (ar[j] < ar[i])
            {
                dp[i] = max(dp[i], dp[j] + ar[i]);
            }
        }
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}

// Maximum Sum Bitonic Subsequence
// https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0
int Max_Sum_Bitonic_Subseq(vector<int> &ar)
{
    int N = ar.size();
    vector<int> lis_L2R(N);
    vector<int> lis_R2L(N);
    for (int i = 0; i < N; i++)
    {
        lis_L2R[i] = ar[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (ar[j] < ar[i])
            {
                lis_L2R[i] = max(lis_L2R[i], lis_L2R[j] + ar[i]);
            }
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        lis_R2L[i] = ar[i];
        for (int j = i + 1; j < N; j++)
        {
            if (ar[j] < ar[i])
            {
                lis_R2L[i] = max(lis_R2L[i], lis_R2L[j] + ar[i]);
            }
        }
    }
    int maxSum = 0;
    for (int i = 0; i < N; i++)
    {
        maxSum = max(maxSum, lis_L2R[i] + lis_R2L[i] - ar[i]);
    }
    return maxSum;
}

// Minimum number of deletions to make a sorted sequence
// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence/0

int Min_del(vector<int> &ar)
{
    int N = ar.size();
    vector<int> dp(N, 1);
    int max_ = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (ar[j] < ar[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ = max(max_, dp[i]);
    }
    return N - max_;
}

// leetcode 354. Russian Doll Envelopes
int maxEnvelopes(vector<vector<int>> &env)
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sort(env.begin(), env.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
        {
            return b[1] < a[1];
        }
        return a[0] < b[0];
    });
    int n = env.size();
    vector<int> dp(n, 1);
    int maxAns = 0;
    for (int i = 0; i < env.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (env[j][1] < env[i][1])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxAns = max(maxAns, dp[i]);
    }
    return maxAns;
}

// leetcode 673. Number of Longest Increasing Subsequence
int findNumberOfLIS(vector<int> &ar)
{
    if (ar.size() <= 1)
        return ar.size();

    vector<int> dp(ar.size());
    vector<int> count(ar.size());
    int maxCount = 0;
    int maxLen = 0;

    for (int i = 0; i < ar.size(); i++)
    {
        dp[i] = 1;
        count[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (ar[j] < ar[i])
            {
                if (dp[i] < dp[j] + 1)
                {
                    count[i] = count[j];
                    dp[i] = dp[j] + 1;
                }
                else if (dp[i] == dp[j] + 1)
                {
                    count[i] += count[j];
                }
            }
        }
        if (dp[i] > maxLen)
        {
            maxCount = count[i];
            maxLen = dp[i];
        }
        else if (dp[i] == maxLen)
        {
            maxCount += count[i];
        }
    }
    return maxCount;
}

// leetcode 1027. Longest Arithmetic Sequence

// leetcode 1235. Maximum Profit in Job Scheduling

//---------------------------------------------------------------------------------------------------------------------------------

//Leetcode 91. Decode ways
int numDecoding_(int idx, string &s, vector<int> &dp)
{
    if (idx == s.size())
    {
        return dp[idx] = 1;
    }
    if (dp[idx] != -1)
        return dp[idx];

    if (s[idx] == '0')
        return dp[idx] = 0;

    int count = 0;
    count += numDecoding_(idx + 1, s, dp);

    if (idx < s.size() - 1)
    {
        int num = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
        if (num <= 26)
        {
            count += numDecoding_(idx + 2, s, dp);
        }
    }

    return dp[idx] = count;
}
int numDecodings(string s)
{
    vector<int> dp(s.length() + 1);
    return numDecoding_(0, s, dp);
}
//******************************************

int numDecodings02(string s)
{
    int a = 0;
    int b = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int tempB = b;
        int tempA = a;
        if (s[i] != '0')
        {
            a = b;
            if (i < s.size() - 1)
            {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (num <= 26)
                {
                    a += tempA;
                }
            }
        }
        else
        {
            a = 0;
        }
        b = a;
        a = tempB;
    }
    return b;
}

// Count subsequences of type a^i b^j c^k (GFG)
// https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0
int Count_subseq_aibjck(string &str)
{
    int acount = 0;
    int bcount = 0;
    int ccount = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
        {
            acount += acount + 1;
        }
        else if (str[i] == 'b')
        {
            bcount += bcount + acount;
        }
        else if (str[i] == 'c')
        {
            ccount += ccount + bcount;
        }
    }
    return ccount;
}

// Leetcode 940. Distinct Subsequences II
int distinctSubseqII(string str)
{
    int mod = 1e9 + 7;
    vector<int> lastOcc(26, -1);
    vector<int> ans(str.size() + 1, 1);
    for (int i = 0; i < str.size(); i++)
    {
        if (lastOcc[str[i] - 'a'] == -1)
        {
            ans[i + 1] = (2 * (ans[i] % mod)) % mod;
        }
        else
        {
            ans[i + 1] = (2 * (ans[i] % mod)) % mod - (ans[lastOcc[str[i] - 'a']] % mod) + mod;
        }
        lastOcc[str[i] - 'a'] = i;
    }
    return ((ans[str.size()] % mod) - 1) % mod;
}

// Leetcode 639. Decode Ways II
int mod = 1e9 + 7;
long numDecodings_(int idx, string &s, vector<long> &dp)
{
    if (idx == s.size())
    {
        return dp[idx] = 1;
    }
    if (dp[idx] != -1)
        return dp[idx];
    long count = 0;

    if (s[idx] == '*')
    {
        count = (count % mod + 9 * numDecodings_(idx + 1, s, dp) % mod) % mod;
        if (idx < s.size() - 1)
        {
            if (s[idx + 1] == '*')
            {
                count = (count % mod + 15 * numDecodings_(idx + 2, s, dp) % mod) % mod;
            }
            else
            {
                if (s[idx + 1] >= '0' && s[idx + 1] <= '6')
                {
                    count = (count % mod + 2 * numDecodings_(idx + 2, s, dp) % mod) % mod;
                }
                else
                {
                    count = (count % mod + numDecodings_(idx + 2, s, dp) % mod) % mod;
                }
            }
        }
    }
    else if (s[idx] != '0')
    {
        count = (count % mod + numDecodings_(idx + 1, s, dp) % mod) % mod;
        if (idx < s.size() - 1)
        {
            if (s[idx + 1] == '*')
            {
                if (s[idx] == '1')
                {
                    count = (count % mod + 9 * numDecodings_(idx + 2, s, dp) % mod) % mod;
                }
                else if (s[idx] == '2')
                {
                    count = (count % mod + 6 * numDecodings_(idx + 2, s, dp) % mod) % mod;
                }
            }
            else
            {
                int num = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
                if (num <= 26)
                {
                    count = (count % mod + numDecodings_(idx + 2, s, dp) % mod) % mod;
                }
            }
        }
    }
    return dp[idx] = count;
}

int numDecodings(string &s)
{
    vector<long> dp(s.size() + 1, -1);
    return numDecodings_(0, s, dp);
}
//*************************************

// Leetcode 44. Wildcard Maching
bool isMatch_(string &s, int si, string &p, int pi, vector<vector<int>> &dp)
{
    if (si == s.size() || pi == p.size())
    {
        if (si == s.size() && pi == p.size())
        {
            return dp[si][pi] = true;
        }
        if (pi != p.size())
        {
            while (p[pi] == '*')
            {
                pi++;
            }
            return dp[si][pi] = (pi == p.size());
        }

        return dp[si][pi] = false;
    }

    if (dp[si][pi] != -1)
    {
        return dp[si][pi];
    }

    bool res = false;
    if (s[si] == p[pi])
    {
        return dp[si][pi] = isMatch_(s, si + 1, p, pi + 1, dp);
    }
    else if (p[pi] == '*')
    {
        if (pi + 1 == p.size())
        {
            return true;
        }
        else if (p[pi + 1] == '?' || p[pi + 1] == '*')
        {
            for (int i = si; i < s.size(); i++)
            {
                res = res || isMatch_(s, i, p, pi + 1, dp);
            }
        }
        char next = p[pi + 1];
        for (int i = si; i < s.size(); i++)
        {
            if (s[i] == next)
            {
                res = res || isMatch_(s, i, p, pi + 1, dp);
            }
        }
    }
    else if (p[pi] == '?')
    {
        res = res || isMatch_(s, si + 1, p, pi + 1, dp);
    }
    return dp[si][pi] = res;
}

bool isMatch(string s, string p)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
    return isMatch_(s, 0, p, 0, dp);
}

//---------------------------------------------------------------------------------------------------------------------------------

void solve()
{
    int n = 4;
    vector<int> dp(n + 1, -1);
    cout << fibo_btr(n) << endl;
    display(dp);
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
    // vector<int> arr = {1, 2, 5, 8, 6, 1, 1, 0, 50, 4, 18};
    // cout << INV_bitonic(arr) << endl;
}
int main()
{
    solve();
}

//   git add -A&git commit -m "update"&git push origin master