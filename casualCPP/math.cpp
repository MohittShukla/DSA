#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solve(int N, vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += abs(num);
    }

    int target = totalSum / 2;

    // dp[i] represents whether a subset sum of i is possible
    vector<bool> dp(target + 1, false);
    dp[0] = true;  // Zero sum is always possible

    for (int num : nums) {
        int absNum = abs(num);  // Use absolute values
        // Traverse dp array in reverse to avoid recomputation issues
        for (int t = target; t >= absNum; t--) {
            dp[t] = dp[t] || dp[t - absNum];
        }
    }

    // Find the closest possible subset sum to target
    int closestSum = 0;
    for (int i = target; i >= 0; i--) {
        if (dp[i]) {
            closestSum = i;
            break;
        }
    }

    // The answer is the absolute difference between two partitions
    return abs(totalSum - 2 * closestSum);
}

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    cout << solve(N, nums) << endl;

    return 0;
}
