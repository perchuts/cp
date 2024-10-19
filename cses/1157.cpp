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

int brute_force(int x, int y) {
	vector<vector<int>> grid(x+1, vector<int>(y+1, -1));
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j) {
			vector<int> mex(i+j);
			for (int k = 1; k < j; ++k) if (grid[i][k] < i+j) mex[grid[i][k]] = 1;
			for (int k = 1; k < i; ++k) if (grid[k][j] < i+j) mex[grid[k][j]] = 1;
			for (int k = 0; k < i+j; ++k) {
				if (mex[k] == 0) {
					grid[i][j] = k;
					break;
				}
			}
			assert(grid[i][j] != -1);
		}
	}
	return grid[x][y];
}

void solve(){
	int x, y; cin >> x >> y;
	int ans = 0, X = x, Y = y;
	for (int i = 30; ~i; --i) {
		int p = (1 << i);
		if (max(x, y) <= p) {}
		else if (p < min(x, y)) x -= p, y -= p;
		else {
			ans += (1 << i);
			if (x < y) y -= p;
			else x -= p;
		}
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
