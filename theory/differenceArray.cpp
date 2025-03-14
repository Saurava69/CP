/*A difference array is a useful data structure that 
allows efficient range update operations on an array. 
It is particularly useful when you need to perform multiple range 
increment operations and then query the final values of the array.

concept:

Given an array arr of size n, 
the difference array diff is constructed such that:
diff[i] = arr[i] - arr[i-1] for i > 0
diff[0] = arr[0]

Using the difference array, you can perform range updates efficiently.
To increment all elements in the range [l, r] by a value val, you do:
diff[l] += val
diff[r + 1] -= val (if r + 1 is within bounds)
After all range updates, you can reconstruct the original 
array by computing the prefix sum of the difference array.
Example
Let's say you have an array arr:
arr = [10, 5, 20, 40]
The difference array diff would be:
diff = [10, -5, 15, 20]
To increment the range [1, 3] by 10:

diff[1] += 10 -> diff = [10, 5, 15, 20]
diff[4] -= 10 (out of bounds, so no change)
To get the updated array, compute the prefix sum of diff:

arr[0] = diff[0] = 10
arr[1] = arr[0] + diff[1] = 10 + 5 = 15
arr[2] = arr[1] + diff[2] = 15 + 15 = 30
arr[3] = arr[2] + diff[3] = 30 + 20 = 50

So, the updated array is:

arr = [10, 15, 30, 50]
Implementation:

*/
#include <iostream>
#include <vector>
using namespace std;

// Function to apply range increment using difference array
void rangeIncrement(std::vector<int>& diff, int l, int r, int val) {
    diff[l] += val;
    if (r + 1 < diff.size()) {
        diff[r + 1] -= val;
    }
}

// Function to construct the original array from the difference array
vector<int> constructArray(const std::vector<int>& diff) {
    std::vector<int> arr(diff.size());
    arr[0] = diff[0];
    for (size_t i = 1; i < diff.size(); ++i) {
        arr[i] = arr[i - 1] + diff[i];
    }
    return arr;
}

int main() {
    std::vector<int> arr = {10, 5, 20, 40};
    std::vector<int> diff(arr.size());

    // Construct the difference array
    diff[0] = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        diff[i] = arr[i] - arr[i - 1];
    }

    // Apply range increment
    rangeIncrement(diff, 1, 3, 10);

    // Construct the updated array
    std::vector<int> updatedArr = constructArray(diff);

    // Print the updated array
    for (int val : updatedArr) {
        std::cout << val << " ";
    }

    return 0;
}