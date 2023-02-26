//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int &vertices,
  int &edges)
  {
      vertices++;
      vis[node]=1;
  
      for(auto i:adj[node])
      {
          edges++;
          if(!vis[i])
          dfs(i,vis,adj,vertices,edges);
      }
  }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
       
       
        vector<int>vis(V+1,0);
        
        int ans=0;
        int i;
        for(i=1;i<=V;i++)
        {
            //cout<<i<<endl;
            if(!vis[i])
            {
                int edges=0;
                int vertices=0;
                dfs(i,vis,adj,vertices,edges);
                //cout<<c<<" "<<sum<<endl;
                if(vertices*(vertices-1)==edges) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
