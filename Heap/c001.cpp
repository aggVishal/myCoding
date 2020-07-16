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