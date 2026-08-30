class Solution {
public:
    int n;
    bool check(unordered_map<int,vector<int>>&adj,vector<int>&indegree,int v)
    {
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            count++;
            for(int &x:adj[u])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        if(count==v)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    int n = numCourses;

    unordered_map<int, vector<int>> adj;

    for(auto &p : prerequisites)
    {
        int course = p[0];
        int prerequisite = p[1];

        adj[prerequisite].push_back(course);
    }

    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++)
    {
        for(int &x : adj[i])
        {
            indegree[x]++;
        }
    }

    // STEP 3: Kahn's algorithm
    return check(adj, indegree, n);
}
};