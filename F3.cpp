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
		vector<vector<char>>p1(n, vector<char>(m));
		vector<vector<char>>p2(n, vector<char>(m));

		int i, j;
		int c1 = 0, c2 = 0;


		// int p1=0,p2=0,p3=0,p4=0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if ((i + j) % 2 == 0) {
					p1[i][j] = 'A';
					p2[i][j] = 'B';
				}
				else {
					p1[i][j] = 'B';
					p2[i][j] = 'A';
				}
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				c1 += (matrix[i][j] != p1[i][j]);
				c2 += (matrix[i][j] != p2[i][j]);
			}
		}
		return min(c1, c2);


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