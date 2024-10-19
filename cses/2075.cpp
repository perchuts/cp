#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
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
// Treap
//
// Todas as operacoes custam
// O(log(n)) com alta probabilidade, exceto meld
// meld custa O(log^2 n) amortizado com alta prob.,
// e permite unir duas treaps sem restricao adicional
// Na pratica, esse meld tem constante muito boa e
// o pior caso eh meio estranho de acontecer

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

template<typename T> struct treap {
	struct node {
		node *l, *r;
		int p, sz;
		T val, mi;
		int rev;
		node(T v) : l(NULL), r(NULL), p(rng()), sz(1), val(v), mi(v), rev(0) {}
		void update() {
			sz = 1;
			mi = val;
			if (l) sz += l->sz, mi = min(mi, l->mi);
			if (r) sz += r->sz, mi = min(mi, r->mi);
		}
	};

	node* root;

	treap() { root = NULL; }
	treap(const treap& t) {
		throw logic_error("Nao copiar a treap!");
	}
	~treap() {
		vector<node*> q = {root};
		while (q.size()) {
			node* x = q.back(); q.pop_back();
			if (!x) continue;
			q.push_back(x->l), q.push_back(x->r);
			delete x;
		}
	}
	void prop(node* x) {
		if (x == NULL) return;
		if (x->rev) {
			swap(x->l, x->r);
			if (x->l != NULL) x->l->rev ^= 1;
			if (x->r != NULL) x->r->rev ^= 1;
			x->rev = 0;
		}
	}
	int size(node* x) { return x ? x->sz : 0; }
	int size() { return size(root); }
	void join(node* l, node* r, node*& i) { // assume que l < r
		prop(l), prop(r);
		if (!l or !r) return void(i = l ? l : r);
		if (l->p > r->p) join(l->r, r, l->r), i = l;
		else join(l, r->l, r->l), i = r;
		i->update();
	}
	void split_leq(node* i, node*& l, node*& r, T v) {
		if (!i) return void(r = l = NULL);
		if (i->val <= v) split_leq(i->r, i->r, r, v), l = i;
		else split_leq(i->l, l, i->l, v), r = i;
		i->update();
	}
	void index_split(node* i, node*& l, node*& r, int v, int key = 0) {
		prop(i);
		if (!i) return void(r = l = NULL);
		if (key + size(i->l) < v) index_split(i->r, i->r, r, v, key+size(i->l)+1), l = i;
		else index_split(i->l, l, i->l, v, key), r = i;
		i->update();
	}
	void add(T v) {
		node* at = new node(v);
		join(root, at, root);
	}
	int count(node* i, T v) {
		prop(i);
		if (!i) return 0;
		int lval = (i->l == NULL ? 0 : i->l->sz);
		if (i->val == v) return lval;	
		if (i->l != NULL and i->l->mi == v) return count(i->l, v);
		return count(i->r, v)+1+lval;
	}
	int count(T v) {
		return count(root, v);
	}
	void dfs(node* cur) {
		if (cur == NULL) return;
		//cout << "entering: " << cur->val << endl;
		prop(cur);
		//cout << "L" << endl;
		dfs(cur->l);
		cout << cur->val << ' ';
		//cout << "R" << endl;
		dfs(cur->r);
		//cout << "leaving: " << cur->val << endl;
	}
	void reverse(int l, int r) {
		node *ini, *fim, *segment, *lixo;
		index_split(root, ini, fim, l);
		index_split(fim, segment, fim, r-l+1);
		index_split(segment, segment, lixo, r-l);
		delete lixo;
		lixo = new node(inf);
		join(segment, lixo, segment);
		//cout << r-l+1 << ' ' << l << ' ' << r << endl;
		segment->rev = 1;
		prop(segment);
		join(ini, segment, ini);
		join(ini, fim, root);
	}
};

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	treap<int> t;
	for (auto& x : v) cin >> x, --x, t.add(x);
	//t.dfs(t.root);
	vector<ii> ans;
	for (int i = 0; i < n; ++i) {
		int pos = t.count(i);
		//cout << pos << endl;
		t.reverse(i, pos);
		if (i != pos) ans.pb({i+1, pos+1});
	}
	cout << ans.size() << endl;
	for (auto [x, y] : ans) cout << x << ' ' << y << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
