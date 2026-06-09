#include <iostream>
#include <vector>
#include <random>

using namespace std;
// Function to generate a random integer between min and max (inclusive)

vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);

    random_device rd;  // Obtain a random number from hardware
    mt19937 gen(rd()); // Seed the generator

    uniform_int_distribution<> distr(1, 100000); // Define the range

    for (int &num : arr)
    {
        num = distr(gen); // Generate a random number and assign it to the array
    }
    return arr;
}

int main()
{
    vector<int> numbers = generateRandomArray(20); // Generate an array of 20 random integers
    cout << "Generated random numbers:\n";
    for (int num : numbers)
    {
        cout << num << " "; // Print each number followed by a space
    }
    cout << endl;
    return 0;
}