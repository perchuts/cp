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
	auto pi = kmp(t);
	vector<int> ans;
	int val = pi.back();
	while (val) {
		ans.pb(val);
		val = pi[val-1];
	}
	reverse(all(ans));
	for (auto x : ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
