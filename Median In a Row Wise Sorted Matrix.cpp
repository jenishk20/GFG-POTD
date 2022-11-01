//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int func(vector<int>&v,int x)
{
    int lo=0, hi=v.size()-1;
    int cnt=0;
    while(lo<=hi)  
    {

        int mid=lo+(hi-lo)/2; 
        if(v[mid] < x){        // Checking for next highest element
            cnt = (mid+1); // 0th-based indexing    
            lo=mid+1;
            
        }   
        else
            hi=mid-1;

    }
    return cnt;
}
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here   
        int low=1;
        int high=1e9;
        int medPos=(R*C)/2;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<R;i++)
            {
                count+=func(matrix[i],mid);
                //cout<<count<<endl;
            }
            
            
            if(count<=medPos) {ans=mid;low=mid+1;}
            else high=mid-1;
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends
