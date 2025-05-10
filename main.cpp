#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute maximum spectacle for each test case
long long computeMaxSpectacle(int n, int m, int k, int w, vector<int>& heights) {
    // Sort heights in descending order
    sort(heights.rbegin(), heights.rend());
    
    // Grid to store the heights of gorillas
    vector<vector<long long>> grid(n, vector<long long>(m, 0));

    // Fill the grid with the heights
    int index = 0;
    for (int i = 0; i < n && index < w; ++i) {
        for (int j = 0; j < m && index < w; ++j) {
            grid[i][j] = heights[index++];
        }
    }
    
    // Compute prefix sums for the grid
    vector<vector<long long>> prefixSum(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefixSum[i][j] = grid[i - 1][j - 1] 
                              + prefixSum[i - 1][j]
                              + prefixSum[i][j - 1]
                              - prefixSum[i - 1][j - 1];
        }
    }

    // Calculate maximum spectacle
    long long maxSpectacle = 0;
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            long long currentSpectacle = prefixSum[i][j]
                                         - prefixSum[i - k][j]
                                         - prefixSum[i][j - k]
                                         + prefixSum[i - k][j - k];
            maxSpectacle = max(maxSpectacle, currentSpectacle);
        }
    }

    return maxSpectacle;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, w;
        cin >> n >> m >> k >> w;
        vector<int> heights(w);
        for (int i = 0; i < w; ++i) {
            cin >> heights[i];
        }
        cout << computeMaxSpectacle(n, m, k, w, heights) << endl;
    }
    return 0;
}
