//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private :
	map<string, vector<string>>graph;
	map<string, bool>vis;
	vector<vector<string>>ans;
public:
	void dfs(string &s, vector<string>&temp)
	{
		temp.push_back(s);
		vis[s] = 1;
		for (auto it : graph[s])
		{
			if (!vis[it])
				dfs(it, temp);
		}
	}
	vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
		// code here

		int n = details.size();
		int i, j;

		for (auto &mails : details)
		{
			for (i = 2; i < mails.size(); i++)
			{
				string u = mails[i - 1];
				string v = mails[i];

				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}

		for (auto &mails : details)
		{
			if (!vis[mails[1]])
			{
				vector<string>temp;
				dfs(mails[1], temp);
				sort(temp.begin(), temp.end());
				temp.insert(temp.begin(), mails[0]);
				ans.push_back(temp);
			}
		}
		sort(ans.rbegin(), ans.rend());
		return ans;

	}
};


//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<string>> adj;

		for (int i = 0; i < n; i++) {
			vector<string> temp;
			string s;
			cin >> s;
			temp.push_back(s);
			int x;
			cin >> x;

			for (int j = 0; j < x; j++) {
				string s1;
				cin >> s1;
				temp.push_back(s1);
			}
			adj.push_back(temp);
		}

		Solution obj;
		vector<vector<string>> res = obj.mergeDetails(adj);
		sort(res.begin(), res.end(), [](const vector<string>& a, const vector<string>& b) {
			return a[0] <= b[0];
		});
		cout << "[";
		for (int i = 0; i < res.size(); ++i) {
			cout << "[";
			for (int j = 0; j < res[i].size(); j++) {
				if (j != res[i].size() - 1)
					cout << res[i][j] << ","
					     << " ";
				else
					cout << res[i][j];
			}
			if (i != res.size() - 1)
				cout << "], ";
			else
				cout << "]";
		}
		cout << "]"
		     << "\n";
	}
}

// } Driver Code Ends
