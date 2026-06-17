# Parallel Sorting System Using Multithreading in C++

## Overview

This project demonstrates the use of multicore programming concepts by implementing and comparing Sequential Merge Sort and Parallel Merge Sort using C++ multithreading.

The objective is to evaluate how parallel execution can improve sorting performance on modern multicore processors.

---

## Features

* Sequential Merge Sort implementation
* Parallel Merge Sort using `std::thread`
* Automatic CPU core detection
* Dynamic thread depth selection
* Performance benchmarking
* Speedup calculation
* Efficiency calculation
* Sorting correctness validation
* Performance visualization using Python

---

## Project Structure

```text
ParallelSortingSystem/
│
├── docs/
│   ├── report.md
│   ├── benchmark_results.md
│   ├── Architecture_Diagram_Parallel_Sorting_System.drawio.png
│   └── performance_graph.png
│
├── results/
│   ├── benchmark.csv
│   └── graph.py
│
├── src/
│   ├── main.cpp
│   ├── merge_sort.cpp
│   ├── merge_sort.h
│   ├── parallel_merge_sort.cpp
│   └── parallel_merge_sort.h
│
├── README.md
└── .gitignore
```

---

## Technologies Used

* C++17
* STL (Standard Template Library)
* std::thread
* std::chrono
* Python
* Matplotlib
* Visual Studio Code
* GitHub

---

## Architecture

The system workflow is:

```text
Random Dataset Generator
          ↓
Generated Dataset
          ↓
Dataset Duplication
          ↓
 ┌─────────────────────┐
 │                     │
 ▼                     ▼
Sequential        Parallel
Merge Sort        Merge Sort
 │                     │
 ▼                     ▼
Time Measure    Time Measure
 │                     │
 └─────────┬───────────┘
           ▼
 Performance Comparison
           ▼
 Speedup & Validation
```

---

## Build Instructions

Compile the project:

```bash
g++ .\src\main.cpp .\src\merge_sort.cpp .\src\parallel_merge_sort.cpp -o sort
```

Run the executable:

```bash
./sort
```

---

## Sample Output

```text
Available CPU Cores: 16

Dataset        Sequential(us)   Parallel(us)   Speedup
------------------------------------------------------
10000          16900            10129          1.67
50000          77933            27429          2.84
100000         153096           40721          3.76
500000         815145           256472         3.18
1000000        1373909          319781         4.44
```

---

## Performance Results

The benchmark results show significant performance improvements when using multithreading.

Maximum observed speedup:

**4.44x**

Dataset size:

**1,000,000 integers**

All benchmark runs successfully passed validation tests.

---

## Key Concepts Demonstrated

* Multicore Programming
* Parallel Computing
* Thread Creation
* Thread Synchronization
* Divide and Conquer Algorithms
* Merge Sort
* Performance Benchmarking
* Speedup Analysis

---

## Future Enhancements

* OpenMP implementation
* Thread Pool implementation
* Parallel Quick Sort comparison
* Dynamic workload balancing
* GPU accelerated sorting

---

## Authors

Dhruvil Patel

Multicore Programming Project

University of Europe for Applied Sciences (UE)
