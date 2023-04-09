#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
void bucket_sort(vector<int>& array) {
    // Determine the number of digits in the maximum element
    int max_digit = *max_element(array.begin(), array.end());

    // Create 10 buckets, one for each digit
    vector<vector<int>> buckets(3);

    // Sort the elements into their respective buckets based on their least significant digit
    for (int digit = 0; digit < max_digit; digit++) {
        for (int num : array) {
            buckets[num / (int)pow(10, digit) % 10].push_back(num);
        }
        // Concatenate the elements from the buckets into a new array
        int index = 0;
        for (vector<int>& bucket : buckets) {
            for (int num : bucket) {
                array[index++] = num;
            }
            bucket.clear();
        }
    }
}
int main() {
    // Read input from file
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(6000, 7000);

    // Generate 1000 random numbers and write them to file
    ofstream outputFile("input.txt");
    for (int i = 0; i < 1000; i++) {
        outputFile << dist(gen) << " ";
    }
    outputFile.close();
    ifstream inputFile("input.txt");
    vector<int> array;
    int num;
    while (inputFile >> num) {
        array.push_back(num);
    }
    // Sort the array using bucket sort with radix sort implementation and time the sorting process
    auto start_time = high_resolution_clock::now();
    bucket_sort(array);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    // Print the sorted array and the sorting time
    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Sorting time: " << duration.count() / 1000000.0 << " seconds" << endl;
    return 0;
}