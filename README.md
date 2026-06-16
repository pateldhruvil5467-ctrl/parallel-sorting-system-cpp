# Parallel Sorting System Using Multithreading in C++

## Overview

This project demonstrates the use of multicore programming techniques by implementing a Parallel Merge Sort algorithm using C++ threads.

The project compares the performance of:

- Sequential Merge Sort
- Parallel Merge Sort using std::thread

and evaluates the speedup achieved through parallel execution.

---

## Features

- Random dataset generation
- Sequential Merge Sort
- Parallel Merge Sort
- Multithreading using std::thread
- Execution time measurement using std::chrono
- Speedup calculation
- Validation of sorting correctness
- Performance benchmarking

---

## Technologies Used

- C++17
- std::thread
- std::chrono
- VS Code
- GitHub

---

## Project Structure

src/

├── main.cpp

├── merge_sort.cpp

├── merge_sort.h

├── parallel_merge_sort.cpp

├── parallel_merge_sort.h

docs/

results/

---

## Benchmark Results

| Dataset Size | Sequential (µs) | Parallel (µs) | Speedup |
|-------------|-----------------|---------------|---------|
| 10,000 | 5,440 | 3,510 | 1.55x |
| 50,000 | 30,258 | 11,450 | 2.64x |
| 100,000 | 63,211 | 15,682 | 4.03x |
| 500,000 | 337,233 | 81,614 | 4.13x |
| 1,000,000 | 695,280 | 166,246 | 4.18x |

---

## Build

Compile:

```bash
g++ src/main.cpp src/merge_sort.cpp src/parallel_merge_sort.cpp -o sort
```

Run:

```bash
./sort
```

---

## Conclusion

The parallel implementation consistently outperformed the sequential version, achieving up to 4.18x speedup on large datasets while maintaining identical sorting correctness.
