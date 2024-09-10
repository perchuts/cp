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

int solve(int n, vector<int> v){
	//for (auto x : v) cout << x << ' ';
	//cout << endl;
	// se posicao mod 2 != valor mod 2, vc faz o L! nunca da pra usar esse objeto
	// vc tambem faz o L se pos < valor.
	// excluidos esses casos, vamos comecar a analise
	// pra saber se eu posso usar esse objeto, apenas preciso saber se da pra tirar posicao - valor elementos antes de mim
	// well, tambem ta fixo quem eu tiro... -> FALSO!
	// quando eu faco a operacao muda pra um cara:
	vector<vector<int>> dp(n+2, vector<int>(n+2));
	for (int l = n; l >= 1; --l) {
		for (int r = l+1; r <= n; r += 2) {
			int my_d = (v[l-1] <= l ? l - v[l-1] : inf);
			if (my_d&1) {
				dp[l][r] = inf;
				continue;
			}
			if (l+1 == r) {
				dp[l][r] = my_d; 
			} else {
				dp[l][r] = inf;
				for (int k = l+1; k <= r; k += 2) {
					if ((k < r && (k+1-v[k]) % 2 == 1) or my_d < dp[l+1][k-1]) continue;
					ckmin(dp[l][r], max({dp[l+1][k-1], my_d, dp[k+1][r] - (k+1-l)}));
					ckmax(dp[l][r], 0);
				}
			}
		}
	}
	vector<int> best(n+1); // biggest number of operations if i stop at index i
	for (int i = 1; i <= n; ++i) {
		best[i] = best[i-1];
		for (int j = i-1; j >= 1; j -= 2) {
			int my_d = (v[j-1] <= j ? j - v[j-1] : inf);
			if (my_d&1) continue;
			if (best[j-1] >= dp[j][i]) ckmax(best[i], i-j+1 + best[j-1]);
		}
	}
	//for (int i = 1; i <= n; ++i) {
	//	for (int j = i + 1; j <= n; j += 2) {
	//		cout << "dp["<<i<<"]["<<j<<"] = " << dp[i][j] << endl;
	//	}
	//}
	//cout << "Answer: " << best[n] / 2 << endl;
	return best[n] / 2;
}

mt19937 rng(time(0));

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int32_t main(){_
	int tt = 0;
	while (true) {
		int n = rnd(1, 20);
		vector<int> v(n), dp(1<<n);
		for (auto& x : v) x = rnd(1, n);
		dp.back() = 1;
		int ans = 0;
		for (int i = (1<<n)-1; i >= 0; --i) {
			if (dp[i] == false) continue;
			ckmax(ans, n - __builtin_popcount(i));
			vector<ii> nums;
			for (int j = 0; j < n; ++j) if ((i>>j)&1) nums.pb({v[j]-1, j});
			for (int j = 0; j < sz(nums)-1; ++j) {
				if (nums[j].first == j) {
					int m2 = i - (1<<nums[j].second) - (1<<nums[j+1].second);
					dp[m2] = 1;
				}
			}
		}
		ans /= 2;
		int my = solve(n, v);
		if (ans != my) {
			cout << "Wrong answer on test " << tt << endl;
			cout << 1 << endl;
			cout << n << endl;
			for (auto x : v) cout << x << ' ';
			cout << endl;
			cout << "Your answer: " << my << endl;
			cout << "Correct answer: " << ans << endl;
			exit(0);
		}
		cout << "Accepted on test " << ++tt << endl;
	}
}
