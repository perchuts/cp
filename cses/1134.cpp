#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define sz(x) (int) x.size()
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
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
    vector<int> p(n-2), last(n+1, -1);
    for (auto& x : p) cin >> x;
    set<int> s;
    vector<ii> ans;
    for (int i = 0; i < n-2; ++i) last[p[i]] = i;
    for (int i = 1; i <= n; ++i) if (last[i] == -1) s.insert(i);
    for (int i = 0; i < n-2; ++i) {
        int x = *begin(s);
        ans.pb({x, p[i]});
        if (last[p[i]] == i) s.insert(p[i]);
        s.erase(x);
    }
    ans.pb({*(prev(end(s))), *begin(s)});
    for (auto [x, y] : ans) cout << x << ' ' << y << endl;
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
    
