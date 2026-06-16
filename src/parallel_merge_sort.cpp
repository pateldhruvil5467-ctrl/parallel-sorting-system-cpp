#include "parallel_merge_sort.h"
#include "merge_sort.h"

#include <thread>

using namespace std;

void parallelMergeSort(
    vector<int> &arr,
    int left,
    int right,
    int depth)
{
    if (left >= right)
        return;

    if (depth <= 0)
    {
        mergeSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;

    thread leftThread(
        parallelMergeSort,
        ref(arr),
        left,
        mid,
        depth - 1);

    thread rightThread(
        parallelMergeSort,
        ref(arr),
        mid + 1,
        right,
        depth - 1);

    leftThread.join();
    rightThread.join();

    // Merge step
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}