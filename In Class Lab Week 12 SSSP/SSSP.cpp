#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INFINITY numeric_limits<int>::max()

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<int>>& G, int n, int u) {
    // Initialize travel time as infinity
    vector<int> traveltime(n, INFINITY);
    
    // Travel time of source vertex from itself is 0
    traveltime[u] = 0;
    
    // Array to track visited vertices
    vector<bool> visited(n, false);
    
    for (int count = 0; count < n - 1; count++) {
        int minTime = INFINITY;
        int minTimeVertex;
        
        // Find the vertex with the minimum travel time
        for (int v = 0; v < n; v++) {
            if (!visited[v] && traveltime[v] <= minTime) {
                minTime = traveltime[v];
                minTimeVertex = v;
            }
        }
        
        // Mark the selected vertex as visited
        visited[minTimeVertex] = true;
        
        // Update travel time of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && G[minTimeVertex][v] && traveltime[minTimeVertex] != INFINITY && traveltime[minTimeVertex] + G[minTimeVertex][v] < traveltime[v]) {
                traveltime[v] = traveltime[minTimeVertex] + G[minTimeVertex][v];
            }
        }
    }
    
    // Print the shortest travel time from the source vertex
    for (int i = 0; i < n; i++) {
        cout << "Time taken from " << u << " to " << i << " =\t" << traveltime[i] << "\n";
    }
}

int main() {
    int n = 6;  // Number of vertices
    int u = 0;  // Starting vertex
    
    // Create a weighted adjacency matrix
    vector<vector<int>> G = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    
    // Perform Dijkstra's algorithm
    dijkstra(G, n, u);
    
    return 0;
}
