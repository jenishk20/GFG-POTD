//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  void dfs(long long int node,vector<int>graph[],vector<int>&A,bool flag,
  vector<vector<long long>>&dp)
  {
        long long ans=-1e18;
        if(dp[node][flag]!=ans) return;
        for(auto i:graph[node])
        {
            dfs(i,graph,A,!flag,dp);
            ans=max(ans,dp[i][!flag]);
        }
        long long value=A[node-1];
        if(flag)
        value=-value;
        if(ans==-1e18)  dp[node][flag]=value;
        else
         dp[node][flag]=value+ans;
        
  }
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        vector<int>graph[N+1];
        for(int i=1;i<N;i++)
        {
            graph[P[i]].push_back(i+1);
        }
        vector<vector<long long >>dp(N+1,vector<long long>(2,-1e18));
        long long ans=-1e18;
        for(long long int i=1;i<=N;i++)
        {
            dfs(i,graph,A,0,dp);
        }
        ans=-1e18;
        for(int i=1;i<=N;i++)
        ans=max(ans,dp[i][0]);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
