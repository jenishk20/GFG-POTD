class Solution{   
public:
    const int mod=1e9+7;
    long long binary(long long int base,long long int exp)
    {
        long long ans=1;
        while(exp)
        {
            if(exp%2==0)
            {
                base=(base*base)%mod;
                exp/=2;
            }
            else
            {
                exp--;
                ans=(ans*base)%mod;
            }
        }
        return ans%mod;
    }
    long long numberOfSubsequences(int N, long long A[]){
        // code here 
        long long count=0;
        
        for(int i=0;i<N;i++)
        {
            if((A[i]&A[i]-1)==0)
            count++;
        }
        long long ans=0;
        return binary(2,count)-1;
        // return pow(2,count)-1;
        
    }
};
