int binarySearch(int *input, int n, int val)
{
    //Write your code here
    int start = 0,end=n,mid,index = -1;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(val==input[mid])
        {
            index = mid;
            break;
        }
        else if(val<input[mid])
        {
            end = mid-1;
        }
        else start = mid+1;
    }
    return index;
}