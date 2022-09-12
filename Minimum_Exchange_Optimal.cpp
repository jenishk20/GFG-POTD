//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int MinimumExchange(vector<vector<char>>matrix) {
		// Code here
		int n = matrix.size();
		int m = matrix[0].size();
		int i, j;

		int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if ((i + j) % 2 == 0 and matrix[i][j] != 'A')
					p1++;
				else if ((i + j) & 1 and matrix[i][j] != 'B')
					p2++;
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if ((i + j) % 2 == 0 and matrix[i][j] == 'A')
					p3++;
				else if ((i + j) & 1 and matrix[i][j] == 'B')
					p4++;
			}
		}
		return min(p1 + p2, p3 + p4);


	}

};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m, 'x'));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MinimumExchange(matrix);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
