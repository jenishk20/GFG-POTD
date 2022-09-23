//User function template for C++

class Solution{
public:
    int minLength(string s, int n) {
        // code here
        
        stack<char>se;
        map<string,bool>ma;
        ma["12"]=1;
        ma["21"]=1;
        ma["34"]=1;
        ma["43"]=1;
        ma["56"]=1;
        ma["65"]=1;
        ma["78"]=1;
        ma["87"]=1;
        ma["09"]=1;
        ma["90"]=1;
        
        for(int i=0;i<n;i++)
        {
            se.push(s[i]);
            while(se.size()>1)
            {
                char a=se.top();
                se.pop();
                char b=se.top();
                se.pop();
                string check="";
                check+=b;
                check+=a;
                //cout<<check<<endl;
                
                if(ma.find(check)==ma.end())
                {
                    se.push(b);
                    se.push(a);
                    break;
                }
            }
        }
        return  se.size();
    } 
};
