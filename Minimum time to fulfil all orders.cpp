//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	bool canMake(int donuts, int time, vector<int>&rank, int l)
	{
		int can = 0;

		for (int i = 0; i < l; i++)
		{
			int sum = 0;
			for (int j = rank[i]; sum + j <= time; j += rank[i])
			{
				sum += j;
				can++;
			}
			if (can >= donuts)
				return true;
		}

		return can >= donuts;
	}
	int findMinTime(int N, vector<int>&A, int L) {
		//write your code here

		int l = 1;
		int h = 1000000;
		int ans = 0;
		while (l <= h)
		{
			int mid = (l + h) / 2;

			if (canMake(N, mid, A, L))
			{
				ans = mid;
				h = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
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
		int n;
		cin >> n;
		int l;
		cin >> l;
		vector<int>arr(l);
		for (int i = 0; i < l; i++) {
			cin >> arr[i];
		}
		Solution ob;
		int ans = ob.findMinTime(n, arr, l);
		cout << ans << endl;
	}
	return 0;
}

// } Driver Code Ends
