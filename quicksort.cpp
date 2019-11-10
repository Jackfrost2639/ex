#include <bits/stdc++.h>

using namespace std;

int a[100];

int partition(int arr[], int start, int end)
{
    int left = start;
    int right = end-1;
    int pivot = end;

    while(right>left)
    {
        while(left>pivot)
        {
            left++;
        }
        while(right<=pivot)
        {
            right--;
        }

        if(right<left)
        {
            int temp = arr[right];
           arr[right] = arr[left];
           arr[left] = temp;
        }
    }

    int temp1 = arr[pivot];
    arr[pivot] = arr[left];
    arr[left] = temp1;

    return left;
}

void qsort(int arr[], int start, int end)
{
    if(start >= end)
    {
        return;
    }
    
    int pivot = partition(arr, start, end);
    
    qsort(arr, start, pivot-1);
    qsort(arr, pivot+1, end);
}

int main()
{
    int n;
}