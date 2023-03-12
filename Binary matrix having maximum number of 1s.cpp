//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int find(int N,vector<int>mat)
    {
        int low=0;
        int high=mat.size();
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mat[mid]==0)
            {
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        if(ans==-1) return 0;
        return N-ans;
    }
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int i,j;
        
        int mr=0;
        int mc=0;
        for(i=0;i<N;i++)
        {
            int res=find(N,mat[i]);
            if(res>mc)
            {
                mc=res;
                mr=i;
            }
            //cout<<res<<endl;
        }
        
        /* O ( N ) solution Comment above part and Uncomment below part */
      
      
      
        // i=0,j=N-1;
        // while(i<N and j>=0)
        // {
        //     if(mat[i][j])
        //     {
        //         mr=i;
        //     }
        //     while(j>=0 and mat[i][j])
        //     j--;
            
        //     mc=N-j-1;
        //     i++;
        // }
        return {mr,mc};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
