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
	int n; cin >> n;
	vector grid(n, vector(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c; cin >> c;
			if (c == 'A') grid[i][j] = 1; 
			if (c == 'B') grid[i][j] = 2;
		}
	}
	// dp[i][j][k] = numero de maneiras de completar o preenchimento se 
	// A ocupa i posicoes do B
	// B ocupa j posicoes do A
	// A e B ocupam a mesma posicao k vezes
	vector<vector<int>> row(2, vector<int>(n)), col(2, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] != 0) {
				row[grid[i][j]-1][i] = col[grid[i][j]-1][j] = 1;
			}
		}	
	}
	vector<int> lim(2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 0) continue;
			// o outro consegue ficar aqui?
			int v = grid[i][j]-1;
			if (row[v^1][i] == 0 and col[v^1][j] == 0) lim[v^1]++;
		}
	}
	int ans = 0, falta1 = 0, falta2 = 0;
	for (int i = 0; i < n; ++i) {
		if (row[0][i] == 0) falta1++;
		if (row[1][i] == 0) falta2++;
	}
	int rowlivre = 0, collivre = 0;
	for (int i = 0; i < n; ++i) {
		if (row[0][i] == row[1][i] && row[0][i] == 0) rowlivre++;
		if (col[0][i] == col[1][i] && col[0][i] == 0) collivre++;
	}
	vector<vector<int>> ncr(n+1, vector<int>(n+1));
	vector<int> fat(n+1);
	for (int i = 0; i <= n; ++i) {
		if (i == 0) fat[i] = 1;
		else fat[i] = i * fat[i-1] % mod;
		for (int j = 0; j <= i; ++j) {
			if (i == j or j == 0) ncr[i][j] = 1;
			else ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
		}
	}	
	for (int i = 0; i <= lim[0]; ++i) {
		for (int j = 0; j <= lim[1]; ++j) {
			for (int k = 0; k <= min(rowlivre, collivre); ++k) {
				if (i + k > falta1 or j + k > falta2) continue;
				int val = ncr[lim[0]][i] * ncr[lim[1]][j] % mod;
				val = val * ncr[rowlivre][k] % mod * ncr[collivre][k] % mod * fat[k] % mod;	
				int s1 = falta1 - i - k, s2 = falta2 - j - k;
				val = val * fat[s1] % mod * fat[s2] % mod;
				if ((i+j+k) % 2) ans = (ans - val + mod) % mod;
				else ans = (ans + val) % mod;
			}
		}
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
