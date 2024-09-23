#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
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
 	int n; cin >> n;
	int l = 1, r = 9e18, ans = 1;
	vector ncr(20, vector(20, 0));
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == j or j == 0) ncr[i][j]  = 1;
			else ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
		}
	}
	vector<int> pw(20, 1), pw10(20, 1);
	for (int i = 1; i < 19; ++i) pw[i] = pw[i-1] * 9, pw10[i] = pw10[i-1] * 10;
	vector<ii> pre(20);
	for (int i = 1; i <= 18; ++i) {
		// upto i digits
		for (int j = 1; j <= i; ++j) {
			int q = ncr[i][j] * pw[i-j] * j;
			if (j != i) pre[i].first += q; 
			pre[i].second += q; 
		}	
	}
	auto mx = [&] (int x) {
		string s = to_string(x);
		int lg = sz(s)-1;
		vector<int> freq(10, pre[lg].second);
		freq[0] = pre[lg].first;
		int m = sz(s);
		vector<int> p_freq(10);
		for (int i = 0; i < m; ++i) {
			int digit = s[i] - '0';
			for (int j = (i==0); j < digit; ++j) {
				freq[j] += pw10[m-i-1];
				for (int w = 0; w < 10; ++w) freq[w] += pre[m-i-1].second, freq[w] += pw10[m-i-1] * p_freq[w];
			}
			p_freq[digit]++;
		}
		int resp = 0;
		for (int w = 0; w < 10; ++w) freq[w] += p_freq[w], ckmax(resp, freq[w]);
		return resp;
	};
	while (l <= r) {
		int md = l + (r-l+1)/2;
		if (mx(md) <= n) ans = md, l = md+1;
		else r = md-1;
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
