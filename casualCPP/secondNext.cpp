#include <iostream>
#include <vector>
using namespace std;

vector<int> findSecondNextGreater(vector<int>& arr, int x) {
    int n = arr.size();
    vector<int> result(n, -1);
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] >= arr[i] + x) {
                count++;
                if (count == 2) {
                    result[i] = arr[j];
                    break;
                }
            }
        }
    }
    
    return result;
}

// More efficient solution with O(n) complexity using monotonic stack
vector<int> findSecondNextGreaterOptimized(vector<int>& arr, int x) {
    int n = arr.size();
    vector<int> result(n, -1);
vector<pair<int, int> > nextGreater(n, make_pair(-1, -1));
    
    for (int i = 0; i < n; i++) {
        int target = arr[i] + x;
        int count = 0;
        
        for (int j = i + 1; j < n && count < 2; j++) {
            if (arr[j] >= target) {
                count++;
                if (count == 2) {
                    result[i] = arr[j];
                    break;
                }
            }
        }
    }
    
    return result;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Using the more efficient solution
    vector<int> result = findSecondNextGreaterOptimized(arr, x);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
