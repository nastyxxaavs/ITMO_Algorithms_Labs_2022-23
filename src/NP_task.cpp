
#include <iostream>
#include <vector>

using namespace std;


    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited){
        if(visited[node]) {
            return;
        }
        visited[node] = true;
        for(int i = 0; i < graph[node].size(); i++){
            dfs(graph[node][i], graph, visited);
        }
    }

    int count_components(int n ,vector<vector<int>> &a){
        vector <bool> visited(n);
        int ret = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, a, visited);
                ret++;
            }
        }
        return ret;
    }



int main() {
    int n, m;
    int u, v;
    int count = 0;
    bool flag = true;
    vector<vector<int>> graph;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; i++) {
        if (graph[i].size() == 1) {
            count ++;
        }
        if((graph[i].size() > 2) || (count > 2) ||(graph[i].size() == 0) || ((n - m) != 1)){
            flag = false;
            cout << "NO" << endl;
            return 0;
        }
    }

    if (count == 2 && flag){
        if ((count_components(n,graph)) == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
