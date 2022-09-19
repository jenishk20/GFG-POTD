// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int>se;
        vector<int>ans;
        int i;
        for(i=0;i<n;i++)
        {
            if(se.empty())
            {
                ans.push_back(-1);
            }
            else if(se.top()<a[i])
            {
                ans.push_back(se.top());
            }
            else
            {
                while(!se.empty() and se.top()>=a[i])
                se.pop();
                
                if(se.empty())
                ans.push_back(-1);
                else
                ans.push_back(se.top());
               
            }
             se.push(a[i]);
        }
        return ans;
    }
};
