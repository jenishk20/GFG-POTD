class Solution {
  public:
  long long dfs(int node,vector<int>graph[],vector<int>&A,int flag)
  {
        long long ans=-1e18;
        for(auto i:graph[node])
        {
            ans=max(ans,dfs(i,graph,A,!flag));
        }
        long long value=A[node-1];
        if(flag)
        value=-value;
        if(ans==-1e18) return value;
        return value+ans;
        
  }
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        vector<int>graph[N+1];
        for(int i=1;i<N;i++)
        {
            graph[P[i]].push_back(i+1);
        }
        long long ans=-1e18;
        for(int i=1;i<=N;i++)
        {
            ans=max(ans,dfs(i,graph,A,0));
        }
        return ans;
    }
};
