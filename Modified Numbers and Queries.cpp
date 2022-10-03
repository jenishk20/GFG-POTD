//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int sumOfAll(int l, int r){
        // code here
        int isPrime[r+1];
        memset(isPrime,1,sizeof isPrime);
        int i,j;
        
        for(i=2;i*i<=r;i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<=r;j+=i)
                {
                    isPrime[j]=0;
                }
            }
        }
        int sum=0;
        for(int i=l;i<=r;i++)
        {
            if(isPrime[i])
            sum+=i;
            else
            {
                for(int j=2;j<=i/2;j++)
                {
                    if(i%j==0 and isPrime[j])
                    sum+=j;
                }
            }
            //cout<<i<<" "<<sum<<endl;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

// } Driver Code Ends
