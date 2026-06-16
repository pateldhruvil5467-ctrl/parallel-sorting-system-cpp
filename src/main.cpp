#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

#include "merge_sort.h"
#include "parallel_merge_sort.h"

using namespace std;

// Generate random array
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

// Verify both arrays are identical
bool arraysEqual(
    const vector<int> &a,
    const vector<int> &b)
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

int main()
{
    vector<int> testSizes =
        {
            10000,
            50000,
            100000,
            500000,
            1000000};

    cout << "\n==============================================================\n";
    cout << " Parallel Sorting System Using Multithreading in C++\n";
    cout << "==============================================================\n\n";

    cout << left
         << setw(15) << "Dataset"
         << setw(20) << "Sequential(us)"
         << setw(20) << "Parallel(us)"
         << setw(15) << "Speedup"
         << setw(15) << "Validation"
         << endl;

    cout << string(85, '-') << endl;

    for (int size : testSizes)
    {
        // Generate dataset
        vector<int> originalArray = generateRandomArray(size);

        // Create copies for fair comparison
        vector<int> sequentialArray = originalArray;
        vector<int> parallelArray = originalArray;

        // ==========================
        // Sequential Benchmark
        // ==========================

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

        // ==========================
        // Parallel Benchmark
        // ==========================

        auto startPar =
            chrono::high_resolution_clock::now();

        parallelMergeSort(
            parallelArray,
            0,
            parallelArray.size() - 1,
            3);

        auto endPar =
            chrono::high_resolution_clock::now();

        auto parDuration =
            chrono::duration_cast<
                chrono::microseconds>(
                endPar - startPar);

        // ==========================
        // Validation
        // ==========================

        bool correct =
            arraysEqual(
                sequentialArray,
                parallelArray);

        // ==========================
        // Speedup Calculation
        // ==========================

        double speedup =
            static_cast<double>(seqDuration.count()) /
            parDuration.count();

        // ==========================
        // Print Results
        // ==========================

        cout << left
             << setw(15) << size
             << setw(20) << seqDuration.count()
             << setw(20) << parDuration.count()
             << setw(15) << fixed << setprecision(2)
             << speedup
             << setw(15)
             << (correct ? "PASS" : "FAIL")
             << endl;
    }

    cout << "\nBenchmark Complete.\n";

    return 0;
}