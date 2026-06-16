#ifndef PARALLEL_MERGE_SORT_H
#define PARALLEL_MERGE_SORT_H

#include <vector>

void parallelMergeSort(std::vector<int> &arr,
                       int left,
                       int right,
                       int depth);

#endif