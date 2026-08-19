class Solution {
public:
bool issafe(vector<string>&borad,int row,int col,int n)
{
    //Row check;
     for(int j=0;j<n;j++)
     {
        if(borad[row][j]=='Q')
        {
            return false;
        }
     }
     //vectical check
     for(int i=0;i<n;i++)
     {
        if(borad[i][col]=='Q')
        {
            return false;
        }
     }

     //Digonal left check
     for(int i=row,j=col;i>=0 && j>=0;i--,j--)
     {
         if(borad[i][j]=='Q')
         {
            return false;
         }
     }
     //Right check;
     for(int i=row,j=col;i>=0&&j<n;i--,j++)
     {
         if(borad[i][j]=='Q')
         {
            return false;
         }
     }
     return true;
}
void nqueen(vector<string>&borad,int row,int n,vector<vector<string>>&ans)
{
    if(row==n)
    {
        ans.push_back({borad});
        return;
    }
   for(int j=0;j<n;j++)
   {
      if(issafe(borad,row,j,n))
      {
         borad[row][j]='Q';
         nqueen(borad,row+1,n,ans);
        borad[row][j] = '.';
      }
   }
}
    vector<vector<string>> solveNQueens(int n) {
       vector<string> borad(n, string(n, '.'));
        vector<vector<string>> ans;
        nqueen(borad,0,n,ans);
        return ans;
    }
};