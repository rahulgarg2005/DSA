#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void bfs(int start, const vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> adjList(vertices);
    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(vertices, false);

    cout << "BFS traversal starting from node 0: ";
    bfs(0, adjList, visited);

}
