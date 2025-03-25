#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solve(int N, int K, int Q, vector<int> &A, vector<int> &queries) {
    set<int> positions;          // Stores the positions of skyscrapers
    multiset<int> segmentLengths; // Stores the lengths of greenery segments

    // Initially, the entire greenery [0, K] is one segment
    positions.insert(0);
    positions.insert(K);
    segmentLengths.insert(K);

    vector<int> maxSegmentAfterBuild(N);

    for (int i = 0; i < N; ++i) {
        int pos = A[i];

        // Find the two bounds of the current segment being split
        auto upper = positions.lower_bound(pos);
        auto lower = prev(upper);

        // Calculate the length of the current segment before splitting
        int oldLength = *upper - *lower;

        // Remove the old segment length
        segmentLengths.erase(segmentLengths.find(oldLength));

        // Add the new segments formed by placing a building
        int leftSegment = pos - *lower;
        int rightSegment = *upper - pos;

        segmentLengths.insert(leftSegment);
        segmentLengths.insert(rightSegment);

        // Mark the building's position
        positions.insert(pos);

        // Store the maximum segment length after this building
        maxSegmentAfterBuild[i] = *segmentLengths.rbegin();
    }

    // Answer each query
    vector<int> result;
    for (int q : queries) {
        result.push_back(maxSegmentAfterBuild[q - 1]);
    }

    return result;
}

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N), queries(Q);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < Q; ++i) cin >> queries[i];

    vector<int> result = solve(N, K, Q, A, queries);

    for (int res : result) {
        cout << res << " ";
    }

    return 0;
}
