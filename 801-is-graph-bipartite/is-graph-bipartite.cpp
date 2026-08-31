class Solution {
public:
    int n;

    bool check(unordered_map<int, vector<int>>& adj,
               vector<int>& color,
               int currcolor,
               int start)
    {
        color[start] = currcolor;

        for (auto &x : adj[start])
        {
            if (color[x] == currcolor)
                return false;

            if (color[x] == -1)
            {
                if (!check(adj, color, 1 - currcolor, x))
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        n = graph.size();

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            for (auto &x : graph[i])
            {
                adj[i].push_back(x);
            }
        }

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!check(adj, color, 0, i))
                    return false;
            }
        }

        return true;
    }
};