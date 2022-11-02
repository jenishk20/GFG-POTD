//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int>rows,cols;
            rows.push_back(0);
            cols.push_back(0);
            for(auto i:enemy)
            {
                rows.push_back(i[0]);
                cols.push_back(i[1]);
            }
            int maxr=0,maxc=0;
            rows.push_back(n+1);
            cols.push_back(m+1);
            sort(rows.begin(),rows.end());
            sort(cols.begin(),cols.end());
            for(int i=1;i<rows.size();i++)
            {
                maxr=max(maxr,rows[i]-rows[i-1]-1);
            }
            
            for(int i=1;i<cols.size();i++)
            {
                maxc=max(maxc,cols[i]-cols[i-1]-1);
            }
            //cout<<maxr<<" "<<maxc<<endl;
            return maxr*maxc;
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends
