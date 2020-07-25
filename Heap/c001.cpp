#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class heap
{
public:
    vector<int> arr;

    heap(vector<int> list)
    {
        for (int ele : list)
        {
            arr.push_back(ele);
        }

        for (int i = arr.size() - 1; i <= 0; i--)
        {
            downHeapify(i, arr.size());
        }
    }

    void downHeapify(int pi, int n)
    {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int maxIdx = pi;
        if (lci < n && arr[lci] > arr[maxIdx])
        {
            maxIdx = lci;
        }
        if (rci < n && arr[rci] > arr[maxIdx])
        {
            maxIdx = rci;
        }

        if (maxIdx != pi)
        {
            swap(maxIdx, pi);
            downHeapify(maxIdx, n);
        }
    }
    void upHeapify(int idx)
    {
        int pi = (idx - 1) / 2;
        int minIdx = arr[idx];
        if (arr[pi] < arr[idx])
        {
            minIdx = pi;
        }

        if (minIdx != idx)
        {
            swap(minIdx, idx);
            upHeapify(minIdx);
        }
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    bool isEmpty()
    {
        return arr.size() == 0;
    }

    int size()
    {
        return arr.size();
    }

    int top()
    {
        if (arr.size() == 0)
            return -1;
        return arr[0];
    }
    void pop()
    {
        if (arr.size() == 0)
            return;

        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        downHeapify(0, arr.size());
    }
    void add(int ele)
    {
        arr.push_back(ele);
        upHeapify(arr.size() - 1);
    }
};

// Leetcode 215. Kth Largest Element in an Array
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int ele : nums)
    {
        pq.push(ele);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

// Leetcode 703. Kth Largest Element in a Stream
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int x = -1;
    KthLargest(int k, vector<int> &nums)
    {
        x = k;
        for (int ele : nums)
        {
            pq.push(ele);
            if (pq.size() > x)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > x)
        {
            pq.pop();
        }
        return pq.top();
    }
};

// Leetcode 378. Kth Smallest Element in a Sorted Matrix
int kthSmallest01(vector<vector<int>> &mat, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    //priority_queue<vector<int>>pq;
    for (int i = 0; i < mat.size(); i++)
    {
        pq.push({mat[i][0], i, 0});
    }
    while (k-- > 1)
    {
        vector<int> idx = pq.top();
        pq.pop();
        if (++idx[2] < mat[0].size())
        {
            pq.push({mat[idx[1]][idx[2]], idx[1], idx[2]});
        }
    }
    return pq.top()[0];
}
int kthSmallest02(vector<vector<int>> &mat, int k)
{
    //priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> >pq;
    priority_queue<vector<int>> pq;
    for (int i = 0; i < mat.size(); i++)
    {
        pq.push({-mat[i][0], i, 0});
    }
    while (k-- > 1)
    {
        vector<int> idx = pq.top();
        pq.pop();
        if (++idx[2] < mat[0].size())
        {
            pq.push({-mat[idx[1]][idx[2]], idx[1], idx[2]});
        }
    }
    return -pq.top()[0];
}

// Leetcode 347. Top K Frequent Elements
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (int ele : nums)
    {
        freq[ele]++;
    }
    unordered_map<int, int>::iterator it;
    priority_queue<vector<int>> pq;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        pq.push({it->second, it->first});
    }
    vector<int> ans;
    while (k--)
    {
        ans.push_back(pq.top()[1]);
        pq.pop();
    }
    return ans;
}

// Leetcode 295. Find Median from Data Stream
class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left.empty() || num < left.top())
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }
        if (left.size() == right.size() + 2)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() == right.size())
        {
            return 1.0 * (left.top() + right.top()) / 2;
        }
        return left.top();
    }
};

//Leetcode 407. Trapping Rain Water II
int trapRainWater(vector<vector<int>> &height)
{
    int n = height.size();
    int m = height[0].size();
    typedef pair<int, int> cell;
    priority_queue<cell, vector<cell>, greater<cell>> pq;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        pq.push({height[i][0], i * m});
        pq.push({height[i][m - 1], i * m + m - 1});
        vis[i][0] = vis[i][m - 1] = true;
    }
    for (int j = 0; j < m; j++)
    {
        pq.push({height[0][j], j});
        pq.push({height[n - 1][j], (n - 1) * m + j});
        vis[0][j] = vis[n - 1][j] = true;
    }

    int maxTillNow = 0;
    int water = 0;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (pq.size() != 0)
    {
        cell idx = pq.top();
        pq.pop();
        int r = idx.second / m;
        int c = idx.second % m;
        maxTillNow = max(maxTillNow, idx.first);
        for (int d = 0; d < 4; d++)
        {
            int x = r + dir[d][0];
            int y = c + dir[d][1];
            if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y])
            {
                pq.push({height[x][y], x * m + y});
                water += max(0, maxTillNow - height[x][y]);
                vis[x][y] = true;
            }
        }
    }
    return water;
}

//Leetcode 778
