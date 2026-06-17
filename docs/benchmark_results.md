# Benchmark Results

## Test Environment

* Language: C++17
* Compiler: g++ 15.2.0
* Parallel Library: std::thread
* CPU Cores Available: 16
* Parallel Thread Depth: 3

---

## Benchmark Data

| Dataset Size | Sequential Time (µs) | Parallel Time (µs) | Speedup | Efficiency | Validation |
| ------------ | -------------------- | ------------------ | ------- | ---------- | ---------- |
| 10,000       | 16,900               | 10,129             | 1.67    | 0.10       | PASS       |
| 50,000       | 77,933               | 27,429             | 2.84    | 0.18       | PASS       |
| 100,000      | 153,096              | 40,721             | 3.76    | 0.23       | PASS       |
| 500,000      | 815,145              | 256,472            | 3.18    | 0.20       | PASS       |
| 1,000,000    | 1,373,909            | 319,781            | 4.44    | 0.28       | PASS       |

---

## Analysis

The benchmark results demonstrate that the Parallel Merge Sort implementation consistently outperforms the Sequential Merge Sort implementation.

As dataset size increases, the performance benefit of parallel execution becomes more significant. The highest speedup achieved was 4.44x for a dataset containing 1,000,000 integers.

The validation results confirm that both implementations produce identical sorted outputs, ensuring correctness while improving performance.

---

## Key Findings

* Parallel execution reduces sorting time significantly.
* Larger datasets benefit more from multithreading.
* Maximum speedup achieved: 4.44x.
* All benchmark runs passed validation checks.
* The project successfully demonstrates multicore programming concepts using C++ threads.
