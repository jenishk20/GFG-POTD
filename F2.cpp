//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N) {
		//Write your code here
		sort(X.begin(), X.end(), greater<int>());
		sort(Y.begin(), Y.end(), greater<int>());
		int n = X.size();
		int m = Y.size();
		int i = 0, j = 0;
		int h = 1, v = 1;
		int ans = 0;

		while (i < n and j < m)
		{

			if (X[i] > Y[j])
			{
				ans += X[i] * v;
				h++;
				i++;
			}
			else
			{
				ans += Y[j] * h;
				v++;
				j++;
			}

		}
		while (i < n)
		{
			ans += X[i] * v;
			i++;
		}
		while (j < m)
		{
			ans += Y[j] * h;
			j++;
		}
		return ans;
	}
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		vector<int>X(m - 1), Y(n - 1);
		for (int i = 0; i < m - 1; i++) {
			cin >> X[i];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> Y[i];
		}
		Solution ob;
		int ans = ob.minimumCostOfBreaking(X, Y, m, n);
		cout << ans << endl;
	}
	return 0;
}

// } Driver Code Ends