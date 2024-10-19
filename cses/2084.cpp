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

// Convex Hull Trick Estatico
//
// adds tem que serem feitos em ordem de slope
// queries tem que ser feitas em ordem de x
//
// add O(1) amortizado, get O(1) amortizado

struct CHT {
	int it;
	vector<ll> a, b;
	CHT():it(0){}
	ll eval(int i, ll x){
		return a[i]*x + b[i];
	}
	bool useless(){
		int sz = a.size();
		int r = sz-1, m = sz-2, l = sz-3;
		return (b[l] - b[r])*(a[m] - a[l]) <
			(b[l] - b[m])*(a[r] - a[l]);
	}
	void add(ll A, ll B){
		if (!a.empty() and A == a.back()) ckmin(b.back(), B);
		else a.push_back(A), b.push_back(B);
		while (!a.empty()){
			if ((a.size() < 3) || !useless()) break;
			a.erase(a.end() - 2);
			b.erase(b.end() - 2);
		}
		it = min(it, int(a.size()) - 1);
	}
	ll get(ll x){
		while (it+1 < a.size()){
			if (eval(it+1, x) < eval(it, x)) it++;
			else break;
		}
		return eval(it, x);
	}
};

void solve(){
	int n, X; cin >> n >> X;
	vector<int> s(n), f(n);
	for (auto& x : s) cin >> x;
	for (auto& x : f) cin >> x;
	CHT cht;
	cht.add(X, 0);
	int ans, best = 1e18;
	vector<int> my(n);
	for (int i = 0; i < n; ++i) {
		ans = cht.get(s[i]);
		my[i] = ans;
		cht.add(f[i], my[i]);
	}
	cout << ans << endl;
	// dp[i] = min(dp[j] + f[j] * s[i])
	// funcao de j: f_j(x) = dp[j] + f[j] * x
	// s[i]'s sao crescentes!
	// f[i]'s sao decrescentes!
	
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
