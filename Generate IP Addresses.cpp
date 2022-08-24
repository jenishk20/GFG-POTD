//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
public:
	bool valid(string &s)
	{
		if (s.size() > 3)
			return false;

		if (s.front() == '0' and s.size() > 1)
			return false;

		int val = stoll(s);

		return val >= 0 and val <= 255;

	}
	void recur(string &s, vector<string>&ans)
	{
		int i, j, k;
		for (i = 1; i <= 3 and i < s.size(); i++)
		{
			string first = s.substr(0, i);

			for (j = 1; j <= 3 and i + j < s.size(); j++)
			{
				string second = s.substr(i, j);

				for (k = 1; k <= 3 and i + j + k < s.size(); k++)
				{
					string third = s.substr(i + j, k);

					string fourth = s.substr(i + j + k);


					if (valid(first) and valid(second)
					        and valid(third) and valid(fourth))
					{
						ans.push_back(first + "." + second + "." + third + "." + fourth);
					}
				}
			}
		}
	}
	vector<string> genIp(string &s) {
		// Your code here
		vector<string>ans;
		recur(s, ans);
		return ans;
	}

};

//{ Driver Code Starts.

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		/*generating naively*/
		Solution obj;
		vector<string> str = obj.genIp(s);
		sort(str.begin(), str.end());
		if (str.size() == 0)
			cout << -1 << "\n";
		else {
			for (auto &u : str) {
				cout << u << "\n";
			}
		}
	}
}
// } Driver Code Ends
