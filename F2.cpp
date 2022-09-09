//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	string digitsNum(int N)
	{
		// Code here.
		string ans(N, '0');
		string temp = "";

		while (N)
		{
			if (N >= 9)
			{
				temp += (9 + '0');
				N -= 9;
			}
			else
			{
				temp += (N + '0');
				N = 0;
			}
		}
		reverse(temp.begin(), temp.end());

		return temp + ans;
	}
};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends