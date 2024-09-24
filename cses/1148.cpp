#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int ll

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	vector h(n+1, vector(m+1, 0)), ans = h;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		char c; cin >> c;
		grid[i][j] = (c == '.');
	}	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (grid[i-1][j-1] == 0) h[i][j] = 0;
			else h[i][j] = 1 + h[i-1][j];
		}
		vector<int> l(m+1), r(m+1);
		stack<ii> st;
		st.push({-1, 0});
		for (int j = 1; j <= m; ++j) {
			while (st.top().first > h[i][j]) st.pop();
			l[j] = st.top().second;
			st.push({h[i][j], j});
		}
		while (!st.empty()) st.pop();
		st.push({-1, m+1});
		for (int j = m; j >= 1; --j) {
			while (st.top().first >= h[i][j]) st.pop();
			r[j] = st.top().second;
			st.push({h[i][j], j});
		}
		for (int j = 1; j <= m; ++j) {
			int len = r[j] - l[j] - 1;
			ans[h[i][j]][len]++;
			if (h[i][j]) ans[h[i][j]-1][len]--;
		}
	}			
	cout << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ans[i][j] << " \n"[j==m];
		}
	}		
	for (int i = n; i >= 1; --i) {
		for (int j = m; j >= 1; --j) {
			if (i != n) ans[i][j] += 2*ans[i+1][j];
			if (j != m) ans[i][j] += 2*ans[i][j+1];
			if (i != n and j != m) ans[i][j] -= ans[i+1][j+1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ans[i][j] << " \n"[j==m];
		}
	}		
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
