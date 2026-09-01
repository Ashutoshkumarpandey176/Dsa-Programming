class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
    }

    void uneion(int x,int y)
    {
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent)
            return;
        if(rank[x_parent]>rank[y_parent])
            parent[y_parent]=x_parent;
        else if(rank[y_parent]>rank[x_parent])
            parent[x_parent]=y_parent;
        else
            parent[x_parent]=y_parent;
            rank[y_parent]++;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //n->kitna computer hai
        //connections->oo abhi kesay connected hai 
        //we have to find ke aagar koe pc connect nahi hai hai to mujay kitan min edge chaheya unhay conncect karany  kay leya

        if(connections.size()<n-1)
        {
            return -1;
        }
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        int components=n; //ilaka

        for(auto &vec:connections)
        {
            if(find(vec[0])!=find(vec[1]))
            {
                uneion(vec[0],vec[1]);
                components--;
            }
        }
        return components-1;
    }
};