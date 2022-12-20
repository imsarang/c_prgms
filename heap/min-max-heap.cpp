/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// time complexity : O(nlogn)
// space complexity O(n)
#include <iostream>
#include <queue>

using namespace std;
#include <vector>

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {
        if (isEmpty())
            return 0;
        return pq[0];
    }

    void insert_min_heap(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }
    void heapify_min()
    {
        int parentIndex = 0;
        int leftChild = (2 * parentIndex) + 1;
        int rightChild = (2 * parentIndex) + 2;
        while (leftChild < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[parentIndex] > pq[leftChild])
                minIndex = leftChild;
            if (rightChild < pq.size() && pq[rightChild] < pq[minIndex])
                minIndex = rightChild;
            if (parentIndex == minIndex)
                break;
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChild = (2 * parentIndex) + 1;
            rightChild = (2 * parentIndex) + 2;
        }
    }
    int removeMin()
    {
        if (isEmpty())
            return 0;

        int x = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        heapify_min();
        return x;
    }

    void heapify_max()
    {
        int parentIndex = 0;
        int leftChild = (2 * parentIndex) + 1;
        int rightChild = (2 * parentIndex) + 2;
        while (leftChild < pq.size())
        {
            int max = parentIndex;
            if (pq[leftChild] > pq[max])
                max = leftChild;
            if (rightChild < pq.size() && pq[rightChild] > pq[max])
                max = rightChild;
            if (max == parentIndex)
                break;
            int temp = pq[max];
            pq[max] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = max;
            leftChild = (2 * parentIndex) + 1;
            rightChild = (2 * parentIndex) + 2;
        }
    }

    void insert_max_heap(int element)
    {
        pq.push_back(element);
        int childIndex = pq[pq.size() - 1];
        if (childIndex == 0)
            return;
        while (childIndex < pq.size())
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        if (isEmpty())
            return 0;
        return pq[0];
    }

    int removeMax()
    {
        if (isEmpty())
            return 0;
        int x = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        heapify_max();
        return x;
    }
};

void k_sorted_array(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    int j = 0;
    for (int i = k; i < n; i++)
    {
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while (!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            max.push(arr[i]);
        } // push is any of the heap  //max or min

        else
        {
            if (arr[i] < max.top())
                max.push(arr[i]);
            else
                min.push(arr[i]);
        }
        // keeping in check that both heap are almost of same size
        if (int(max.size() - min.size()) > 1)
        {
            int x = max.top();
            max.pop();
            min.push(x);
        }
        else if (int(min.size() - max.size()) > 1)
        {
            int x = min.top();
            min.pop();
            max.push(x);
        }

        int c = max.size() + min.size(); // count

        // checking size of list to find median
        if (c % 2 == 0)
            cout << (max.top() + min.top()) / 2 << " ";
        else
        {
            if (max.size() > min.size())
                cout << max.top() << " ";
            else
                cout << min.top() << " ";
        }
    }
}

int main()
{
    PriorityQueue p;
    // min heap
    p.insert_min_heap(100);
    p.insert_min_heap(10);
    p.insert_min_heap(15);
    p.insert_min_heap(4);
    p.insert_min_heap(17);
    p.insert_min_heap(21);
    p.insert_min_heap(67);
    // p.insert(100);
    cout << "MIN HEAP" << endl;
    cout << p.getSize() << endl;
    cout << p.getMin() << endl;
    while (!p.isEmpty())
    {
        cout << p.removeMin() << " ";
    }
    cout << endl;
    // max heap
    p.insert_max_heap(100);
    p.insert_max_heap(10);
    p.insert_max_heap(15);
    p.insert_max_heap(4);
    p.insert_max_heap(17);
    p.insert_max_heap(21);
    p.insert_max_heap(67);

    cout << "MAX HEAP" << endl;
    cout << p.getSize() << endl;
    cout << p.getMax() << endl;
    while (!p.isEmpty())
        cout << p.removeMax() << " ";
    cout << endl;

    int arr[] = {10, 12, 6, 7, 9};
    k_sorted_array(arr, 5, 3);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}
