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

int bit[maxn], n;

void insert(int x) {
	for (; x <= n; x += x&(-x)) bit[x]++;
}

int query(int x) {
	int ans = 0;
	while (x) {
		ans += bit[x];
		x -= x & (-x);
	}
	return ans;
}		

void insert2(int x, int k) {
	for (; x <= n; x += x&(-x)) ckmax(bit[x], k);
}

int query2(int x) {
	int ans = 0;
	while (x) {
		ckmax(ans, bit[x]);
		x -= x & (-x);
	}
	return ans;
}		
void solve(){
 	cin >> n;
	vector<int> p(n), pinv(n);
	for (auto& x : p) cin >> x, --x;
	int inv = 0;
	for (int i = n - 1; i >= 0; --i) {
		pinv[p[i]] = i;
		inv += query(p[i]+1);
		insert(p[i]+1);
	}
	vector<int> vis(n);
	int cyc = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		int cur = i;
		cyc++;
		while (!vis[cur]) vis[cur] = 1, cur = p[cur];
	}
	for (int i = 1; i <= n; ++i) bit[i] = 0;
	int lis = 0;
	for (int i = 0; i < n; ++i) {
		int my = query2(p[i] + 1) + 1;
		insert2(p[i] + 1, my);
		ckmax(lis, my);
	}
	int ans = 0, cur = n;
	for (int i = n-1; i >= 0; --i) {
		if (pinv[i] > cur) break;
		ans++, cur = pinv[i];
	}
	cout << inv << ' ' << n - cyc << ' ' << n - lis << ' ' << n - ans << endl;

}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
