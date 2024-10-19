#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int inf = 1e5+10;
const int mod = 1e9+7;
const int maxn = 3e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

// by: MvKaio
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
 
string parse(int x, int n) {
	string s;
	for (int i = 0; i < n; ++i) s += char('0' + ((x>>i)&1));	
	return s;
}

string solve(int N){
    const int lim = 15, lim2 = 30-lim, mx = 1596;
	string ans(50, '1');
	vector dp(2, vector(mx+1, vector(mx+1, make_pair(inf, 0))));
	for (int n = 1; n <= lim; ++n) {
		for (int i = 0; i < (1 << n); ++i) {
			for (int st_cur = 0; st_cur < 2; ++st_cur) {
				ii A = {1, 0}, B = {0, 1}, tot = {0, 0};
				int cur = st_cur;
				for (int j = 0; j < n; ++j) {
					int act = (i >> j) & 1;
					if (cur != act) cur = act, swap(A, B);
					tot.first += A.first, tot.second += A.second;
					B.first += A.first, B.second += A.second;
				}
				//ckmax(mx, max(tot.first, tot.second));
				//if (n == 3) cout << st_cur << ' ' << parse(i, n) << ' ' << tot.first << ' ' << tot.second << endl;
			    ckmin(dp[st_cur][tot.first][tot.second], make_pair(n, i));
			}
		}
	}
	for (int n = 1; n <= lim2; ++n) {
		for (int i = 0; i < (1 << n); ++i) {
			int cur = 2, cur_dp = 1, prev_dp = 1, tot = 0;
			for (int j = 0; j < n; ++j) {
				int act = (i >> j) & 1;	
				if (cur != act) cur = act, swap(cur_dp, prev_dp);
				tot += cur_dp, prev_dp += cur_dp;
			}
			if (tot == N) return parse(i, n);
			if (tot > N or n != lim2) continue;
			int y = N - tot, z = y / cur_dp;
			for (int j = 0; j <= min(z, mx); ++j) {
				int falta = y - j * cur_dp, j2 = falta / prev_dp;
				if (falta % prev_dp or j2 > mx) continue;
				if (sz(ans) > dp[cur][j][j2].first+lim2) {
					//cout << "tot: " << tot << ' ' << fast_eval(parse(i, n)) << endl;
					//cout << parse(i, n) << ' ' << cur << ' ' << cur_dp << ' ' << prev_dp << ' ' << j << ' ' << j2 << endl;
					ans = parse(i, n) + parse(dp[cur][j][j2].second, dp[cur][j][j2].first);
				}
			}
		}
	}
    return ans;
}

void solve() {
	int n; cin >> n;
	cout << solve(n) << endl;

	exit(0);
}
int32_t main(){_
	solve();
	int tt = 1;
	while (true) {
		int N = rnd(1, 1000000);
		string ans = solve(N);
		if (N != fast_eval(ans)) {
			cout << "Wrong answer on test " << tt << endl;
			cout << N << endl;
			cout << "Your output: " << ans << "(" << fast_eval(ans) << ")" << endl;
			exit(0);
		}
		cout << "Accepted on test " << tt++ << endl;
	}
}
