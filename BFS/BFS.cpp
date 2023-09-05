#include <vector>
#include <queue>

vector<bool> visited;
vector<vector<int>> adjList;

void BFS(int start){
    queue<int> q;
    q.push(start);
    while (!q.empty()){
        int sz = q.size();
        for(int i = 0 ; i < sz ; i++){
            int curr = q.top();
            q.pop();
            for (auto &child: adjList[curr]) { 
                if (!visited[child]){
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
    }
}