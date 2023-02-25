//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        // code here
        int n=s.size();
        int i,j;
        int m=t.size();
        
        i=0;
        j=0;
        while(i<n and j<m)
        {
           
            if(s[i]==t[j])
            {
                i++;
                j++;
                continue;
            }
            
            
                
            int inc=0;
           
            while(j<m and isdigit(t[j]))
            {
                inc=(inc*10)+(t[j]-'0');
                j++;
            }
            //cout<<temp<<endl;
            i+=inc;
            if(inc==0) return 0;
            
        }
        return i==n and j==m;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
