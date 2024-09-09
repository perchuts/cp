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

int g[1501];

void solve(){
 	 int n; cin >> n;
	 if (n <= 1500) cout << (g[n] ? "first" : "second") << endl;
	 else cout << "first" << endl;
}

int32_t main(){_
  int t; cin >> t;
  for (int i = 1; i <= 1500; ++i) {
	  vector<int> used(i/2+1);
	  for (int j = 1; j <= i/2; ++j) {
		  if (2 * j == i) continue;
		  int x = g[j] ^ g[i-j];
		  if (x <= i) used[x] = 1;
	  }
	  for (int j = 0; ; ++j) {
		  if (!used[j]) {
			  g[i] = j;
			  break;
		  }
	  }
  }
  while(t--) solve();
}
