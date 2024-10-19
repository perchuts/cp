#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast_io cin.tie(0)->sync_with_stdio(0);
#define int ll
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int eval(string s) {
	set<string> st;
	
	int n = s.size();
	for (int mask = 1; mask < (1<<n); mask++) {
		string t;
		for (int i = 0; i < n; i++) if (mask >> i & 1)
			t += s[i];
		st.insert(t);
	}
	
	return st.size();
}

int fast_eval(string s) {
	int n = s.size();

	vector nxt(n, vector(2, 0));
	vector dp(n + 1, 0);

	vector<vector<int>> occ(2);
	occ[0].push_back(n);
	occ[1].push_back(n);
	for (int i = n - 1; i >= 0; --i) {
		occ[s[i] - '0'].push_back(i);
		nxt[i][0] = occ[0].back();
		nxt[i][1] = occ[1].back();
	}

	dp[n] = 1;
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = 1;
		for (int j : {0, 1}) {
			int to = nxt[i][j];
			if (to != n) {
				dp[i] += dp[to + 1];
			}
		}
	}

	return dp[0] - 1;
}

int32_t main() {
    fast_io;

	int n; cin >> n;

	map<int, string> ans;
	for (int i = 1; i <= n; i++) {
		for (int mask = 0; mask < (1<<i); mask++) {
			string s;
			for (int j = 0; j < i; j++) s += '0' + (mask >> j & 1);

			int dist = eval(s);
			assert(dist == fast_eval(s));
			if (!ans.count(dist)) ans[dist] = s;
		}
	}

	for (auto [x, s] : ans) {
		reverse(s.begin(), s.end());
		cout << x << " " << s << endl;
	}
}
