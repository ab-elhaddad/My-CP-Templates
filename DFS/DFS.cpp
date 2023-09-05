#include <vector>

vector<bool> visited;
vector<vector<int>> adjList;

void DFS(int curr) {
    vis[curr] = true;
    for (auto &child : adjList[curr])
        if(!visited[child])
            DFS(child);
}