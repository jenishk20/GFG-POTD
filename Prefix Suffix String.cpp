//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Node
{
    public:
    Node *links[26]={NULL};
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch-'a']=node;
    }
};

class Trie
{
  public:
  Node *root;
  Trie()
  {
      root=new Node();
      
  }
  void insert(string word)
  {
      
        Node *temp=root;
       // cout<<word<<endl;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsKey(word[i]))
            {
                temp->put(word[i],new Node());
            }
            temp=temp->get(word[i]);
            
        }
  }
  bool search(string s)
  {
      Node *temp=root;
      for(int i=0;i<s.size();i++)
      {
          if(!temp->containsKey(s[i]))
          return false;
          
          temp=temp->get(s[i]);
      }
      return true;
  }
};
class Solution{
public:

    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        Trie *t1=new Trie();
        Trie *t2=new Trie();
        for(auto i:s1)
        {
            t1->insert(i);
            string tt=i;
            reverse(tt.begin(),tt.end());
            t2->insert(tt);
        }
        
        int c=0;
        bool b1=false;
        for(auto i:s2)
        {
            b1=false;
            if(t1->search(i))
            {
                b1=true;
                c++;
            }
            if(!b1){
            string tt=i;
            reverse(tt.begin(),tt.end());
            
            if(t2->search(tt))c++;
            }        
        }
        return c;
        // return c;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
