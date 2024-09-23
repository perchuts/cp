#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
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
// Suffix Array - O(n log n)
//
// kasai recebe o suffix array e calcula lcp[i],
// o lcp entre s[sa[i],...,n-1] e s[sa[i+1],..,n-1]
//
// Complexidades:
// suffix_array - O(n log(n))
// kasai - O(n)

vector<int> suffix_array(string s) {
	s += "$";
	int n = s.size(), N = max(n, 260);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

vector<int> kasai(string s, vector<int> sa) {
	int n = s.size(), k = 0;
	vector<int> ra(n), lcp(n);
	for (int i = 0; i < n; i++) ra[sa[i]] = i;

	for (int i = 0; i < n; i++, k -= !!k) {
		if (ra[i] == n-1) { k = 0; continue; }
		int j = sa[ra[i]+1];
		while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}

void solve(){
 	string s; cin >> s;
	int n = sz(s);
	auto sa = suffix_array(s);
	auto lcp = kasai(s, sa);

	ll k; cin >> k;

	auto tot_s = [&] (int x) {
		if (x < 0) return 0ll;
		ll tot = 0;
		for (int i = 0; i <= x; ++i) tot += n - sa[i];
		int L = lcp[x];
		for (int i = x+1; i < n; ++i) {
			tot += L;
			L = min(L, lcp[i]);
		}
		return tot;
	};

	int l = 0, r = n-1, ans = 0;
	//cout << n << endl;
	//for (auto x : sa) cout << x << ' ';
	//cout << endl;
	//for (auto x : lcp) cout << x << ' ';
	//cout << endl;

	while (l <= r) {
		int md = l + (r-l+1)/2;
		if (tot_s(md) < k) ans = l = md+1;	
		else r = md-1;
	}

	k -= tot_s(ans-1);
	//cout << k << ' ' << sa[ans] << endl;

	vector<int> qt(n+1);
	multiset<int> mt;

	int ptr = ans, st = (ans == 0 ? 1 : lcp[ans-1]+1), tam = -1;

	while (ptr < n and lcp[ptr] >= st) mt.insert(lcp[ptr++]);

	for (int i = st; i <= n - sa[ans]; ++i) {
		while (!mt.empty() and (*begin(mt)) < i) mt.extract(lcp[--ptr]);	
		int add = sz(mt)+1;
		//cout << "desse tamanho: " << add << " " << ptr << endl;
		if (k <= add) {
			tam = i;
			break;
		}
		k -= add;
	}
	assert(tam != -1);
	for (int i = 0; i < tam; ++i) cout << s[sa[ans]+i];
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
