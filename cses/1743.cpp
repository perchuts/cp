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
	string s; cin >> s;
	int n = sz(s);
	vector<int> freq(26);
	for (auto x : s) freq[x-'A']++;
	set<ii> freqs, freqs2;
	for (int i = 0; i < 26; ++i) {
		if (freq[i] == 0) continue;
		freqs.insert({i, freq[i]});
		freqs2.insert({freq[i], i});
	}
	auto itt = prev(end(freqs2));
	if (itt->first > (n+1)/2) {
		cout << -1 << endl;
		return;
	}
	string ans;
	for (int i = 0; i < n; ++i) {
		auto it = begin(freqs);
		auto it2 = prev(end(freqs2));
		auto use = [&] (int x) {
			ans.pb(char('A'+x));
			freqs.erase({x, freq[x]});
			freqs2.erase({freq[x], x});
			freq[x]--;
			if (freq[x]) {
				freqs.insert({x, freq[x]});
				freqs2.insert({freq[x], x});
			}
		};
		if ((n-i)/2 < it2->first) use(it2->second);	
		else if (i and it->first == int(ans.back()-'A')){
			it = next(it);
			use(it->first);
		} else use(it->first);
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
