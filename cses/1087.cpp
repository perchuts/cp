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
    vector<int> dp(n+2, inf), tr(n+2);
    vector<char> rev(4);
    rev[0] = 'A', rev[1] = 'C', rev[2] = 'G', rev[3] = 'T', dp[0] = 0;
    vector<int> mp(260); mp['A'] = 0, mp['C'] = 1, mp['G'] = 2, mp['T'] = 3;
    vector prox(n+2, vector(4, 0));
    for (int i = 1; i <= n; ++i) {
        int val = mp[s[i-1]];
        for (int j = 0; j < 4; ++j) {
           if (val == j) prox[i][j] = i;
           else prox[i][j] = prox[i-1][j];
        }
    }
    for (int i = 1; i <= n+1; ++i) {
        for (int j = 0; j < 4; ++j) {
            int k = prox[i-1][j];
            if (ckmin(dp[i], dp[k] + 1)) tr[i] = j;
        }
    }
    string ans;
    int cur = n+1;
    while (cur) ans += rev[tr[cur]], cur = prox[cur-1][tr[cur]]; 
    reverse(all(ans));
    cout << ans << endl;
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
