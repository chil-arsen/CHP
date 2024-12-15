#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Generate an array with numbers from 1 to n+1, but with one missing
std::vector<int> generateArray(int n) {
    std::vector<int> numbers;
    for (int i = 1; i <= n + 1; ++i) {
        numbers.push_back(i);
    }

    // Randomly remove one number
    srand(static_cast<unsigned int>(time(0)));
    int missing_index = rand() % (n + 1);
    numbers.erase(numbers.begin() + missing_index);

    // Shuffle the array
    std::random_shuffle(numbers.begin(), numbers.end());
    return numbers;
}

// Find the missing number in the array
int findMissingNumber(const std::vector<int>& numbers, int n) {
    int total_sum = (n + 1) * (n + 2) / 2; // Sum from 1 to n+1
    int actual_sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    return total_sum - actual_sum;
}

int main() {
    int n;
    std::cout << "Enter the size of the array (n): ";
    std::cin >> n;

    // Generate the array
    std::vector<int> numbers = generateArray(n);

    // Print the generated array
    std::cout << "Generated array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Find the missing number
    int missing = findMissingNumber(numbers, n);
    std::cout << "The missing number is: " << missing << std::endl;

    return 0;
}
