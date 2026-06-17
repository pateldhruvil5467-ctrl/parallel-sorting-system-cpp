# Parallel Sorting System Using Multithreading in C++

## 1. Abstract

Sorting large datasets efficiently is a common requirement in modern computing systems. Traditional sequential sorting algorithms utilize only a single processor core, which can limit performance for large-scale data processing. This project implements a Parallel Merge Sort algorithm using multithreading in C++ and compares its performance with a traditional Sequential Merge Sort. Experimental results demonstrate significant execution time reduction and performance improvements through multicore utilization.

---

## 2. Introduction

Modern processors contain multiple CPU cores capable of executing tasks concurrently. Multicore programming enables software applications to leverage these hardware resources for improved performance.

This project investigates the benefits of parallel computing by implementing and benchmarking Sequential Merge Sort and Parallel Merge Sort algorithms using C++ threads.

---

## 3. Problem Statement

Sequential sorting algorithms execute on a single thread and may become inefficient when processing large datasets.

The objective of this project is to:

* Implement Sequential Merge Sort
* Implement Parallel Merge Sort using multithreading
* Compare execution times
* Measure speedup and efficiency
* Validate sorting correctness

---

## 4. Objectives

* Understand multicore programming concepts
* Implement thread-based parallelism
* Benchmark sequential and parallel execution
* Analyze performance improvements
* Evaluate scalability for larger datasets

---

## 5. System Architecture

The system follows the workflow:

Random Dataset Generator

↓

Dataset Duplication

↓

Sequential Merge Sort & Parallel Merge Sort

↓

Execution Time Measurement

↓

Performance Comparison

↓

Speedup Analysis & Validation

---

## 6. Technologies Used

* C++17
* STL (Standard Template Library)
* std::thread
* std::chrono
* Visual Studio Code
* GitHub

---

## 7. Implementation

### Sequential Merge Sort

The sequential implementation recursively divides the dataset into smaller partitions and merges them after sorting.

### Parallel Merge Sort

The parallel implementation creates multiple threads that process independent partitions simultaneously. After completion, the sorted partitions are merged into a final sorted dataset.

Thread synchronization is achieved using the join() function.

---

## 8. Experimental Results

The system was tested using datasets ranging from 10,000 to 1,000,000 elements.

Results show that the parallel implementation consistently outperforms the sequential implementation for larger datasets.

Maximum observed speedup:

4.44x

Dataset Size:

1,000,000 integers

---

## 9. Performance Analysis

The benchmark results indicate that multicore execution significantly reduces sorting time.

As dataset size increases, the overhead associated with thread creation becomes negligible, resulting in improved speedup.

The parallel implementation demonstrates effective utilization of available CPU cores.

---

## 10. Conclusion

This project successfully demonstrates the benefits of multicore programming through the implementation of Parallel Merge Sort.

Experimental results confirm that multithreading can substantially reduce execution time while maintaining sorting correctness.

The project validates the effectiveness of parallel computing techniques for large-scale data processing tasks.

---

## 11. Future Work

Possible enhancements include:

* OpenMP implementation
* Thread Pool architecture
* Dynamic workload balancing
* Parallel Quick Sort comparison
* GPU-based sorting acceleration
