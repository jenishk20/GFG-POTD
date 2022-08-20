//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
	string findSum(string s, string t) {
		// Your code goes here
		int n = s.size();
		int m = t.size();
		int i = n - 1;
		int j = m - 1;
		int sum = 0;
		int carry = 0;
		string res = "";

		while (i >= 0 and j >= 0)
		{
			sum = (s[i] - '0') + (t[j] - '0') + carry;
			res.push_back((sum % 10) + '0');
			carry = sum / 10;
			i--;
			j--;
		}
		// cout<<res<<endl;
		while (i >= 0)
		{
			sum = (s[i] - '0') + carry;
			res.push_back((sum % 10) + '0');
			carry = sum / 10;
			i--;
		}
		while (j >= 0)
		{
			sum = (t[j] - '0') + carry;
			res.push_back((sum % 10) + '0');
			carry = sum / 10;
			j--;
		}
		res.push_back(carry + '0');

		//cout<<res<<endl;
		reverse(res.begin(), res.end());
		//  cout<<res<<endl;
		for ( i = 0; i < res.size(); i++)
		{
			if (res[i] != '0')
				break;
		}
		if (i == res.size())
			return "0";
		return res.substr(i);

	}
};

//{ Driver Code Starts.

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string x, y;
		cin >> x >> y;
		Solution ob;
		cout << ob.findSum(x, y) << "\n";
	}

	return 0;
}
// } Driver Code Ends