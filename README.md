# Parallel Sorting System Using Multithreading in C++

## Project Overview

This project demonstrates the implementation and performance evaluation of Sequential Merge Sort and Parallel Merge Sort using multithreading in C++.

The goal of the project is to explore multicore programming concepts by comparing the execution time of a traditional merge sort algorithm against a parallelized version that utilizes multiple CPU cores through C++ threads.

---

## Objectives

- Understand multicore programming concepts
- Implement Sequential Merge Sort
- Implement Parallel Merge Sort using C++ threads
- Measure and compare execution performance
- Calculate speedup and efficiency
- Validate correctness of parallel execution

---

## Technologies Used

- C++
- C++ Standard Thread Library (`<thread>`)
- Visual Studio Code
- MinGW g++
- Python (Matplotlib for visualization)
- Git & GitHub

---

## Project Structure

```
ParallelSortingSystem/
│
├── src/
│   ├── main.cpp
│   ├── merge_sort.h
│   ├── merge_sort.cpp
│   ├── parallel_merge_sort.h
│   └── parallel_merge_sort.cpp
│
├── results/
│   ├── benchmark.csv
│   └── graph.py
│
├── docs/
│   ├── Architecture_Diagram_Parallel_Sorting_System.drawio.png
│   ├── benchmark_results.md
│   ├── performance_graph.png
│   └── report.md
│
└── README.md
```

---

## System Architecture

The project workflow follows these stages:

1. Random Dataset Generation
2. Dataset Duplication
3. Sequential Merge Sort Execution
4. Parallel Merge Sort Execution
5. Time Measurement
6. Performance Comparison
7. Speedup Analysis
8. Result Validation

Architecture Diagram:

`docs/Architecture_Diagram_Parallel_Sorting_System.drawio.png`

---

## Sequential Merge Sort

The sequential implementation follows the traditional divide-and-conquer approach:

1. Divide the array into two halves
2. Recursively sort each half
3. Merge sorted halves

Time Complexity:

```
O(n log n)
```

Space Complexity:

```
O(n)
```

---

## Parallel Merge Sort

The parallel implementation extends merge sort by creating separate threads for recursive subproblems.

Features:

- Recursive thread creation
- Divide-and-conquer parallelism
- Thread synchronization using `join()`
- Shared data handled through references

Example:

```cpp
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
```

---

## Benchmark Configuration

Hardware Information:

- CPU Cores: 16
- Thread Depth: 3

Dataset Sizes Tested:

| Dataset Size |
|-------------|
| 10,000 |
| 50,000 |
| 100,000 |
| 500,000 |
| 1,000,000 |

---

## Performance Results

| Dataset | Sequential (µs) | Parallel (µs) | Speedup | Validation |
|----------|----------------|--------------|----------|------------|
| 10,000 | 16,900 | 10,129 | 1.67x | PASS |
| 50,000 | 77,933 | 27,429 | 2.84x | PASS |
| 100,000 | 153,096 | 40,721 | 3.76x | PASS |
| 500,000 | 815,145 | 256,472 | 3.18x | PASS |
| 1,000,000 | 1,739,009 | 391,781 | 4.44x | PASS |

---

## Performance Graph

Generated using Python and Matplotlib.

Graph Location:

```
docs/performance_graph.png
```

The graph illustrates:

- Sequential execution time growth
- Parallel execution time growth
- Scalability of the parallel approach

---

## Validation

The sorted arrays produced by both algorithms are compared after execution.

Validation Method:

```cpp
arraysEqual(
    sequentialArray,
    parallelArray);
```

Result:

```
PASS
```

for all benchmark runs.

---

## How to Build

Compile the project:

```bash
g++ src/main.cpp src/merge_sort.cpp src/parallel_merge_sort.cpp -o sort
```

Run:

```bash
./sort
```

Windows PowerShell:

```bash
.\sort
```

---

## Generate Performance Graph

Run:

```bash
python results/graph.py
```

Generated Output:

```
performance_graph.png
```

---

## Key Concepts Demonstrated

- Multicore Programming
- Parallel Computing
- Thread Creation
- Thread Synchronization
- Divide and Conquer Algorithms
- Merge Sort
- Performance Benchmarking
- Speedup Analysis

---

## Future Enhancements

- OpenMP implementation
- Thread Pool implementation
- Parallel Quick Sort comparison
- Dynamic workload balancing
- GPU accelerated sorting

---

## Author

Dhruvil Patel

MSc Software Engineering

University of Europe for Applied Sciences (UE)

---

## Conclusion

The project successfully demonstrates how multithreading can significantly improve sorting performance. The parallel merge sort consistently outperformed the sequential implementation and achieved a maximum speedup of approximately 4.44x while maintaining correctness across all benchmark tests.

This project provides practical experience with multicore programming, thread management, synchronization, and performance evaluation in modern C++.