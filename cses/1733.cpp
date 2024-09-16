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

vector<int> get_z(string s) {
	int n = s.size();
	vector<int> z(n, 0);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}

void solve(){
	string t; cin >> t;
	auto kmp = [] (string s) {
		int n = sz(s);
		vector<int> pi(n);
		for (int i = 1; i < n; ++i) {
			int j = pi[i-1];
			while (j and s[j] != s[i]) j = pi[j-1];
			if (s[i] == s[j]) ++j;
			pi[i] = j;
		}
		return pi;
	};
	int n = sz(t);
	auto pi = kmp(t);
	auto z = get_z(t);
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		int last = n - (n % i);
		// pi of last must be either x, or
		int k = last - pi[last-1];
		if ((2*i > n or i % k == 0) and (last == n or z[last] == n - last)) ans.pb(i); 
	}
	for (auto x : ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}

