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
        int minIndex=i;
        for (int j = i+1; j < n; j++)
        {
            if (input[j] < input[minIndex])
            {
                minIndex = j;
            }
        }

        // swapping of elements
        int temp = input[i];
        input[i] = input[minIndex];
        input[minIndex] = temp;
    }
}
