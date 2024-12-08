// OPTIMAL DELIVERY ROUTE

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// Function to solve TSP using DP and bit masking
int tsp(int current, int visited, vector<vector<int>>& graph, vector<vector<int>>& dp, int start) {
    int n = graph.size();

    // Base case: All nodes visited, return distance to start
    if (visited == (1 << n) - 1) {
        return graph[current][start] == 0 ? INT_MAX : graph[current][start];
    }

    // Check if already computed
    if (dp[current][visited] != -1) {
        return dp[current][visited];
    }

    int min_cost = INT_MAX;

    // Try visiting all unvisited cities
    for (int next = 0; next < n; next++) {
        if (!(visited & (1 << next)) && graph[current][next] != 0) { // If not visited and path exists
            int cost = graph[current][next] + tsp(next, visited | (1 << next), graph, dp, start);
            min_cost = min(min_cost, cost);
        }
    }

    dp[current][visited] = min_cost;
    return min_cost;
}

int main() {
    int n;

    // Input: Number of locations
    cout << "Enter the number of locations: ";
    cin >> n;

    // Input: Distance matrix
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "\nEnter the distance matrix (row by row):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Input: Starting location
    int start;
    cout << "\nEnter the starting location (0 to " << n - 1 << "): ";
    cin >> start;

    // DP table to store results
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    // Solve TSP
    int min_cost = tsp(start, 1 << start, graph, dp, start);

    // Output result
    if (min_cost == INT_MAX) {
        cout << "\nNo valid route exists.\n";
    } else {
        cout << "\nMinimum cost for the optimal route: " << min_cost << endl;
    }

    return 0;
}
