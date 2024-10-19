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
const int mod = (119<<23)+1;
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
	string s; cin >> s;
	map<vector<int>, int> freq;
	vector<int> appear(26);
	int lst = 0, ans = 0;
	for (auto x : s) appear[x-'a'] = 1, ckmax(lst, x-'a');
	const int tries = 3;
	vector<vector<int>> hsh(tries, vector<int>(26));
	for (int i = 0; i < tries; ++i) {
		int sum = 0;
		for (int j = 0; j < 26; ++j) {
			if (!appear[j]) continue;
			if (lst == j) hsh[i][j] = (mod - sum) % mod;
			else hsh[i][j] = rnd(0, mod-1), sum = (sum + hsh[i][j]) % mod;
		}
	}
	vector<int> hh(tries);
	freq[hh] = 1;
	for (auto c : s) {
		vector<int> inv;
		for (int i = 0; i < tries; ++i) {
			hh[i] = (hh[i] + hsh[i][c-'a']) % mod;
		}
		ans += freq[hh];
		freq[hh]++;
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
