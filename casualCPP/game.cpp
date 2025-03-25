#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

int solve(int N, std::vector<int>& nums) {
    // Use a map-based memoization approach
    std::map<std::vector<int>, int> memo;
    
    std::function<int(std::vector<int>)> dp = [&](std::vector<int> arr) -> int {
        // Base case: if only one number remains, return it
        if (arr.size() == 1) {
            return arr[0];
        }
        
        // Sort the array to ensure equivalent states are recognized
        std::sort(arr.begin(), arr.end());
        
        // Check if we've already computed this state
        if (memo.find(arr) != memo.end()) {
            return memo[arr];
        }
        
        // Initialize the maximum result
        int maxResult = INT_MIN;
        
        // Try all possible pairs of numbers
        for (size_t i = 0; i < arr.size(); i++) {
            for (size_t j = 0; j < arr.size(); j++) {
                if (i != j) {
                    // Create a new array after the operation
                    std::vector<int> newArr;
                    
                    // Apply the operation: subtract and remove one number
                    for (size_t k = 0; k < arr.size(); k++) {
                        if (k != j) {  // Skip the number to be removed
                            if (k == i) {
                                newArr.push_back(arr[i] - arr[j]);  // Replace with the difference
                            } else {
                                newArr.push_back(arr[k]);  // Keep other numbers
                            }
                        }
                    }
                    
                    // Recursively solve for the new array
                    int result = dp(newArr);
                    
                    // Update the maximum result
                    maxResult = std::max(maxResult, result);
                }
            }
        }
        
        // Store the result in the memo
        memo[arr] = maxResult;
        return maxResult;
    };
    
    return dp(nums);
}

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }
    
    int result = solve(N, nums);
    std::cout << result << std::endl;
    
    return 0;
}
