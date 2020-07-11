#include <iostream>
using namespace std;

class heap
{
public:
    vector<int> arr;

    heap(vector<int> list)
    {
        for (int ele : list)
        {
            arr.push_back(lis);
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

        if (maxIdx != idx)
        {
            swap(minIdx, idx);
            upHeapify(minIdx);
        }
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

        swap(ar[0], arr[arr.size() - 1]);
        arr.pop_back();
        downHeapify(0, arr.size());
    }
    void add(int ele)
    {
        arr.push_back(ele);
        upHeapify(arr.size() - 1);
    }
}