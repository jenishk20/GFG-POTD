//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int dp[1001][1001];
    int mod = 1e9+7;
    int recur(int n,int x,int st)
    {
        if(n==0) return 1; 
        
        int value=1;
        for(int i=0;i<x;i++)
        {
            value = value * st;
        }
        
        if(value>n) return 0;
        
        if(dp[n][st]!=-1) return dp[n][st];
        
        int op1 = recur(n-value,x,st+1);
        int op2 = recur(n,x,st+1);
        
        return dp[n][st]=  (op1+op2)%mod;
        
    }
    int numOfWays(int n, int x)
    {
        
        int st = 1 ;
        memset(dp,-1,sizeof dp);
        return recur(n,x,st);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends
