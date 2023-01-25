#include <vector>
#include <queue>
using namespace std;


// By default : in in-built priority queue : top element is largest , therefore : max-heap
// by default : priority queue => max heap
void mySwap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // for min heap
    int getMin()
    {
        if (isEmpty())
            return 0;

        return pq[0];
    }

    // insert element in min-heap
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                mySwap(&pq[childIndex], &pq[parentIndex]);
            }
            else
                break;

            childIndex = parentIndex;
        }
    }

    // for min heap
    void heapify(vector<int> pq, int i)
    {
        int min = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;
        if (l < pq.size() && pq[min] > pq[l])
        {
            min = l;
        }
        if (r < pq.size() && pq[min] > pq[r])
        {
            min = r;
        }
        if (min != i)
        {
            mySwap(&pq[min], &pq[i]);
            heapify(pq, min);
        }
    }

    int removeMin()
    {
        // Write your code here
        if (pq.size() == 0)
        {
            return -1;
        }
        int x = pq[0];
        int temp = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq[pq.size() - 1] = temp;
        pq.pop_back();
        // heapify(pq,0);
        int i = 0;

        while (i < pq.size()) // min heap property
        {
            if (2 * i + 1 >= pq.size())
                break;

            else
            {
                if (2 * i + 2 >= pq.size())
                    if (pq[i] > pq[2 * i + 1])
                    {
                        int temp = pq[i];
                        pq[i] = pq[2 * i + 1];
                        pq[2 * i + 1] = temp;
                        i = 2 * i + 1;
                    }
                    else
                        break;
                else
                {

                    if (pq[i] > min(pq[2 * i + 1], pq[2 * i + 2]))

                    { // storing idex of smallest children
                        if (pq[2 * i + 1] > pq[2 * i + 2])
                        {
                            int temp = pq[i];
                            pq[i] = pq[2 * i + 2];
                            pq[2 * i + 2] = temp;
                            i = 2 * i + 2;
                        }

                        else
                        {

                            int temp = pq[i];
                            pq[i] = pq[2 * i + 1];
                            pq[2 * i + 1] = temp;
                            i = 2 * i + 1;
                        }
                    }
                    else
                        break;
                }
            }
        }
        return x;
    }
};

// problems using in built queues


// returning k smallest elements in the array
// using max-heap
vector<int> kSmallest(int arr[],int n,int k){
    priority_queue<int> pq;

    // pushing first k elements to the pq
    for(int i = 0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i = k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    vector <int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// return k largest elements in the given array
//  use min-heap
vector<int> kGreatest(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i =0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i = k;i<n;i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    vector <int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

// check if array is max heap
bool checkMaxHeap(int arr[],int n){
    for(int child = 0;child<n;child++){
        int parent = (child-1)/2;
        if(arr[parent] < arr[child]) return false;
    }
    return true;
}

// find kth largest element
// use min-heap
int kthLargest(int* arr, int n, int k) {
    // Write your code here
	priority_queue <int,vector<int>,greater<int> > pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    
    for(int i=k;i<n;i++){
        if(arr[i]> pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans[0];
}

int buyTicket(int arr[],int n,int k){
    queue <int> q;
    for(int i =0;i<n;i++){
        q.push(i);
    }

    priority_queue<int> pq;
    for(int i = 0;i<n;i++){
        pq.push(arr[i]);
    }

    int time = 0;
    while(q.front()!=k && pq.top() != arr[q.front()]){
        if(pq.top() >= arr[q.front()]){
            int x = q.front();
            q.pop();
            q.push(x);
        }
        else{
            pq.pop();
            q.pop();
            time++;
        }
    }
    return time+1;
}