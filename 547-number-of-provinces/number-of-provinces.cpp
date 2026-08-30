class Solution {
public:
    int count = 0;
void countprovinces(unordered_map<int, vector<int>>& adj,vector<bool>& visited,int start) {
        visited[start] = true;
        for (int x : adj[start]) {
            if (!visited[x]) {
                countprovinces(adj, visited, x);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
       int n = isConnected.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (isConnected[i-1][j-1] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n+1, false);
        for (int i = 1; i <=n; i++) {
            if (!visited[i]) {
                count++;
                countprovinces(adj, visited, i);
            }
        }

        return count;
    }
};

