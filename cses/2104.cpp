#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
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

struct node {
	bool appear = 0;
	int link = 0, par = 0, c, dp = inf, deg = 0;
	vector<int> go = vector<int>(26, -1);
} trie[2*maxn];

bool vis[2*maxn], vis2[2*maxn];

void solve(){
	string S; cin >> S;
	int k; cin >> k;
	int h = 0;
	vector<string> words;
	for (int i = 0; i < k; ++i) {
		string s; cin >> s;
		words.pb(s);
		int cur = 0;
		for (auto x : s) {
			if (trie[cur].go[x-'a'] == -1) {
				trie[cur].go[x-'a'] = ++h, trie[h].par = cur, trie[h].c = x-'a';
			}
			cur = trie[cur].go[x-'a'];
		}
		trie[cur].appear = 1;
	}
	for (int i = 0; i < 26; ++i) if (trie[0].go[i] == -1) trie[0].go[i] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u != 0 and trie[u].par != 0) trie[u].link = trie[trie[trie[u].par].link].go[trie[u].c];
		trie[trie[u].link].deg++;
		for (int i = 0; i < 26; ++i) {
			if (trie[u].go[i] > 0) {
				q.push(trie[u].go[i]);
				continue;
			}
			trie[u].go[i] = trie[trie[u].link].go[i];
		}
	}
	int cur = 0;
	for (int i = 1; i <= sz(S); ++i) {
		char x = S[i-1];
		cur = trie[cur].go[x - 'a'];
		ckmin(trie[cur].dp, i);
	}
	for (int i = 0; i <= h; ++i) if (trie[i].deg == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ckmin(trie[trie[u].link].dp, trie[u].dp);
		trie[trie[u].link].deg--;
		if (trie[trie[u].link].deg == 0) q.push(trie[u].link);
	}
	for (auto x : words) {
		cur = 0;
		for (auto y : x) cur = trie[cur].go[y-'a'];
		cout << (trie[cur].dp == inf ? -1 : trie[cur].dp - sz(x)+1) << endl;
	}
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
