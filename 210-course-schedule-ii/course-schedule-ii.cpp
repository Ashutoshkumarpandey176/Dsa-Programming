class Solution {
public:
    vector<int>Topological(unordered_map<int,vector<int>>&adj,vector<int>&indegree,int size)
    {
       vector<int>ans;
       queue<int>q;
       for(int i=0;i<size;i++)
       {
          if(indegree[i]==0)
          {
             q.push(i);
          }
       }
       while(!q.empty())
       {
          int u=q.front();
          q.pop();
          ans.push_back(u);
          for(auto &x:adj[u])
          {
             indegree[x]--;
             if(indegree[x]==0)
             {
                q.push(x);
             }
          }
       }
       return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        for(auto &p : prerequisites)
        { 
            int course=p[0];
            int prerequisites=p[1];
            adj[prerequisites].push_back(course);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(int &x:adj[i])
            {
                indegree[x]++;
            }
        }
        vector<int>ans=Topological(adj,indegree,numCourses);

        if(ans.size()==numCourses)
        {
            return ans;
        }
        else
        {
            return {};
        }
    }
};