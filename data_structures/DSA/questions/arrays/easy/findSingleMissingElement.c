#include <stdio.h>

// For arrays starting with 1
int findSortedSequence(int arr[], int len)
{
    int sum = (arr[len - 1] * (arr[len - 1] + 1)) / 2;

    int actualSum = 0;
    for (int i = 0; i < len; i++)
        actualSum += arr[i];

    return sum - actualSum;
}

// For arrays starting with random numbers
int findUnsortedSequence(int arr[], int len)
{
    int indexDiff = arr[0] - 0;

    for (int i = 0; i < len; i++)
        if (indexDiff + i != arr[i])
            return i + indexDiff;

    return -1;
}

void main()
{
    int nums[7] = {5, 6, 7, 9, 10, 11, 12};

    int ans = findUnsortedSequence(nums, 7);

    printf("Missing number: %d\n", ans);
}