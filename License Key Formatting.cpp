//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int k){
    	
    	string res="";
    	for(auto i:S)
    	{
    	    if(i=='-')
    	    continue;
    	    res+=i;
    	}
    	int n=res.size();
    	
    	string ans="";
    	  
    	    int fs=n%k;
    	    int i;
    	    for(i=0;i<fs;i++)
    	    {
    	        ans+=toupper(res[i]);
    	    }
    	    if(i!=n and i!=0)
    	    ans+='-';
    	    int c=0;
    	    for(i=fs;i<n;i++)
    	    {
    	         if(c==k)
    	        {
    	            c=0;
    	         
    	            ans+='-';
    	        }
    	        ans+=toupper(res[i]);
    	        c++;
    	       
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
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends
