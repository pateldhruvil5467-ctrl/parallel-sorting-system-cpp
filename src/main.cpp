#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include <thread>

#include "merge_sort.h"
#include "parallel_merge_sort.h"

using namespace std;

// --------------------------------------------------
// Generate Random Dataset
// --------------------------------------------------
vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(1, 100000);

    for (int &num : arr)
    {
        num = dist(gen);
    }

    return arr;
}

// --------------------------------------------------
// Verify both sorted arrays are identical
// --------------------------------------------------
bool arraysEqual(const vector<int> &a, const vector<int> &b)
{
    if (a.size() != b.size())
        return false;

    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

// --------------------------------------------------
// Main Program
// --------------------------------------------------
int main()
{
    // Detect available CPU cores
    unsigned int cores = thread::hardware_concurrency();

    if (cores == 0)
        cores = 4; // fallback value

    cout << "\n==============================================================\n";
    cout << " Parallel Sorting System Using Multithreading in C++\n";
    cout << "==============================================================\n\n";

    cout << "Available CPU Cores: "
         << cores
         << "\n\n";

    // Dataset sizes used for benchmarking
    vector<int> testSizes =
        {
            10000,
            50000,
            100000,
            500000,
            1000000};

    // Select thread depth according to CPU capability
    int depth;

    if (cores >= 8)
        depth = 3;
    else if (cores >= 4)
        depth = 2;
    else
        depth = 1;

    cout << "Parallel Thread Depth: "
         << depth
         << "\n\n";

    // Table Header
    cout << left
         << setw(15) << "Dataset"
         << setw(18) << "Sequential(us)"
         << setw(18) << "Parallel(us)"
         << setw(12) << "Speedup"
         << setw(12) << "Efficiency"
         << setw(12) << "Validation"
         << endl;

    cout << string(87, '-') << endl;

    // ==================================================
    // Benchmark Loop
    // ==================================================
    for (int size : testSizes)
    {
        // Generate random dataset
        vector<int> originalArray =
            generateRandomArray(size);

        // Create identical copies
        vector<int> sequentialArray =
            originalArray;

        vector<int> parallelArray =
            originalArray;

        // =====================================
        // Sequential Merge Sort
        // =====================================

        auto startSeq =
            chrono::high_resolution_clock::now();

        mergeSort(
            sequentialArray,
            0,
            sequentialArray.size() - 1);

        auto endSeq =
            chrono::high_resolution_clock::now();

        auto seqDuration =
            chrono::duration_cast<
                chrono::microseconds>(
                endSeq - startSeq);

        // =====================================
        // Parallel Merge Sort
        // =====================================

        auto startPar =
            chrono::high_resolution_clock::now();

        parallelMergeSort(
            parallelArray,
            0,
            parallelArray.size() - 1,
            depth);

        auto endPar =
            chrono::high_resolution_clock::now();

        auto parDuration =
            chrono::duration_cast<
                chrono::microseconds>(
                endPar - startPar);

        // =====================================
        // Validate Correctness
        // =====================================

        bool correct =
            arraysEqual(
                sequentialArray,
                parallelArray);

        // =====================================
        // Performance Metrics
        // =====================================

        double speedup = 0.0;

        if (parDuration.count() > 0)
        {
            speedup =
                static_cast<double>(
                    seqDuration.count()) /
                parDuration.count();
        }

        double efficiency =
            speedup / cores;

        // =====================================
        // Print Result Row
        // =====================================

        cout << left
             << setw(15) << size
             << setw(18) << seqDuration.count()
             << setw(18) << parDuration.count()
             << setw(12) << fixed << setprecision(2)
             << speedup
             << setw(12) << efficiency
             << setw(12)
             << (correct ? "PASS" : "FAIL")
             << endl;
    }

    cout << "\nBenchmark Completed Successfully.\n";

    return 0;
}