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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
 uniform_int_distribution<int> uid(l, r);
 return uid(rng);
}

void solve(){
    int n; cin >> n;
    vector<int> pre(n), in(n), onde_in(n), onde_pre(n);
    vector<ii> g(n, make_pair(-1, -1));
    for (auto& x : pre) cin >> x, --x;
    for (auto& x : in) cin >> x, --x;
    for (int i = 0; i < n; ++i) onde_in[in[i]] = i;
    for (int i = 0; i < n; ++i) onde_pre[pre[i]] = i;
    // constroi a subarvore do cara
	vector<int> st;
	auto go = [&] (auto&& self, int u) -> void {
		//cout << "explorando " << u << endl;
		st.pb(u);
		int i = onde_pre[u];
		if (i < n-1 and onde_in[pre[i+1]] < onde_in[u]) {
			//cout << pre[i+1] << " filho de " << u << endl;
			g[u].first = pre[i+1];
			self(self, pre[i+1]);
		} else if (i != n-1) {
			while (sz(st) != 1 and onde_in[end(st)[-2]] < onde_in[pre[i+1]])
			{
				//cout << "popando " << st.back() << endl;
				st.pop_back();
			}
			//cout << pre[i+1] << "filho de " << st.back();
			g[st.back()].second = pre[i+1];
			st.pop_back();
			self(self, pre[i+1]);
		}
	};
	vector<int> ans;
	go(go, pre[0]);
	//cout << "aqui" << endl;
	//for (int i = 0; i < n; ++i) cout << i << ' ' << g[i].first << ' ' << g[i].second << endl;
	auto post = [&] (auto&& self, int u) -> void {
		if (g[u].first != -1) self(self, g[u].first);
        if (g[u].second != -1) self(self, g[u].second);
        ans.pb(u+1);
    };
    post(post, pre[0]);
    for (auto x : ans) cout << x << ' ';
    cout << endl;
}

int32_t main(){
  int t = 1; //cin >> t;
  while(t--) solve();
}
