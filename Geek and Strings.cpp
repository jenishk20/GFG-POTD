//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Node
{
    public:
    Node *links[26];
    int count;
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void incrementCount()
    {
        count++;
    }
    void setCount()
    {
        count=1;
    }
    int getCount()
    {
        return count;
    }
};
class Trie
{
    private:
    Node *root;
    
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string s)
    {
        Node *temp=root;
        
        for(int i=0;i<s.size();i++)
        {
            if(!temp->containsKey(s[i]))
            {
                temp->put(s[i],new Node());
               
            }
            temp=temp->get(s[i]);
            temp->incrementCount();
        }
    }
    int search(string s)
    {
        Node *temp=root;
        int i;
        for(i=0;i<s.size();i++)
        {
            if(!temp->containsKey(s[i]))
            return -1;
            
            temp=temp->get(s[i]);
        }
       
        return temp->getCount();
    }
};
class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        
        // code here
        Trie *trie=new Trie();
        for(int i=0;i<N;i++)
        {
            trie->insert(li[i]);
        }
        vector<int>ans;
        for(int i=0;i<Q;i++)
        {
            int res=trie->search(query[i]);
            //cout<<res<<" ";
            if(res==-1){
                ans.push_back(0);
                continue;
            }
            
            ans.push_back(res);
        }
        //cout<<endl;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends
