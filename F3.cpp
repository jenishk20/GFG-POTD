//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int dx[8] = { -1, -1, 1, 1, 0, 1, -1, 0};
	int dy[8] = { -1, 1, 1, -1, 1, 0, 0, -1};
	//Function to find unit area of the largest region of 1s.
	void dfs(int i, int j, vector<vector<int>>&vis, vector<vector<int>>& grid,
	         int &cnt)
	{
		cnt++;
		vis[i][j] = 1;
		for (int k = 0; k < 8; k++)
		{
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx >= 0 and ny >= 0 and nx < grid.size()
			        and ny < grid[0].size() and grid[nx][ny] == 1
			        and !vis[nx][ny])
			{
				dfs(nx, ny, vis, grid, cnt);
			}
		}

	}

	int findMaxArea(vector<vector<int>>& grid) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>>vis(n, vector<int>(m, 0));
		int cnt = 0;
		int ans = 0;
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (grid[i][j] == 1 and !vis[i][j])
				{
					cnt = 0;
					dfs(i, j, vis, grid, cnt);
					ans = max(ans, cnt);
				}
			}
		}
		return ans;
	}
};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends