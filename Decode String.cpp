//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char>se;
        
        se.push(s[0]);
        int i;
        string res="";
        
        for(i=1;i<s.size();i++)
        {
            if(s[i]==']')
            {
                
                //Pop out characters
                while(!se.empty() and se.top()!='[')
                {
                    res=se.top()+res;
                    se.pop();
                }
                //Pop out '['
                if(!se.empty())
                {
                    se.pop();
                }
                //Pop out multiplier/adder
                string num="";
                while(!se.empty() and isdigit(se.top()))
                {
                    num=se.top()+num;
                    se.pop();
                }
                //Appending the resulting string
                string temp=res;
                int k=stoi(num);
                k--;
                while(k--)
                {
                    res+=temp;
                }
                
                for(auto x:res)
                se.push(x);
                res="";
            }
            else
            se.push(s[i]);
        }
        res="";
        while(!se.empty())
        {
            res=se.top()+res;
            se.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
