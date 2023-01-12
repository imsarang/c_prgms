// for swapping
void swapElements(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// *********** SELECTION SORT **********************//

// always find minimum element in the array
// swapping of elements is done
// Time complexity : O(n^2)
// Auxiliary Space = O(1)
// default algo : not stable
// In-Place algo i.e it doesnot require extra memory for sorting like another array

void selectionSort(int input[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (input[j] < input[minIndex])
            {
                minIndex = j;
            }
        }

        // swapping of elements
        swapElements(&input[i],&input[minIndex]);
    }
}

// ************************* Bubble Sort ************************ //
// always compare adjacent elements along the array i.e compare i and i+1 element till end of array
// Time Complexity : O(n^2)
// Space Complexity / Auxiliary Space: O(1)
// In-place algo
// used in computer graphics 
// capable of detecting tiny errors

void bubbleSort(int input[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (input[j] > input[j + 1])
            {
                swapElements(&input[j],&input[j+1]);
            }
        }
    }
}

