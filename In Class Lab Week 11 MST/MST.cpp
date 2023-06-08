#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void findMinKeyPrintMST(const vector<vector<int>>& graph, int vertices, int root) {
    vector<int> key(vertices, INT_MAX);    // Key values used to pick minimum weight edge
    vector<int> parent(vertices, -1);      // To store the constructed MST
    vector<bool> mstSet(vertices, false);  // To represent set of vertices included in MST

    // Set the key value of the root vertex as 0, since it will be the first included in the MST
    key[root] = 0;

    // Construct the MST with (vertices - 1) edges
    for (int count = 0; count < vertices - 1; ++count) {
        int minKey = INT_MAX;   // Initialize minimum key and index
        int minIndex = -1;

        // Find the vertex with the minimum key value that is not yet included in the MST
        for (int v = 0; v < vertices; ++v) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        int u = minIndex;   
        mstSet[u] = true;    // Add the picked vertex to the MST set

        // Update key values and parent indices of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int v = 1; v < vertices; ++v) {
        cout << parent[v] << " - " << v << "\t" << graph[v][parent[v]] << endl;
    }
}

int main() {
    const int vertices = 6;
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int root = 0;

    findMinKeyPrintMST(graph, vertices, root);

    return 0;
}
