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

void solve(){
	string s; cin >> s;
	int n = sz(s);
	vector<int> pi(n), z(n);
	for (int i = 1; i < n; ++i) {
		int y = pi[i-1];
		while (y and s[y] != s[i]) y = pi[y-1];
		if (s[y] == s[i]) y++;
		pi[i] = y;
	}
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (i < r) z[i] = min(z[i-l], r-i);
		while (i + z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
		if (ckmax(r, i+z[i])) l = i;
	}
	for (auto x : z) cout << x << ' ';
	cout << endl;
	for (auto x : pi) cout << x << ' ';
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
