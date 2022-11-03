//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[1001][1001];
    int recur(int i,int j,vector<int>&arr,int k)
    {
        if(i>j) return 0;
        
        if(arr[j]-arr[i]<=k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int op1=recur(i+1,j,arr,k);
        int op2=recur(i,j-1,arr,k);
        
        //return min(op1,op2)+1;
         return dp[i][j]=min(op1,op2)+1;
        
    }
    int removals(vector<int>& arr, int k){
        //Code here
        
        int n=arr.size();
        memset(dp,-1,sizeof dp);
        sort(arr.begin(),arr.end());
        
        
        int i=0,j=0;
        int ans=0;
        while(j<n)
        {
            if(arr[j]-arr[i]<=k) j++;
            else if(i<j) i++;
            ans=max(ans,j-i);
        }
        return n-ans;
        // return recur(0,n-1,arr,k);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends
