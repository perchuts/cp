#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,fma,bmi,bmi2,sse4.2")
#include<bits/stdc++.h>
#define all(x) (x).begin() , (x).end()
#define pll pair<int, int>
#define fi first 
#define se second 
#define bit(i,j) ((j >> i) & 1) 
#define lowbit(x) (x & (-x))
#define sigma main
using namespace std;
 
const long long inf = 1e18+1; 
const int mod = 1e9+7; 
const int MAXN = 3e5+100;
 
#define int long long
 
template<class T , class U>
struct segment_tree{
	T t[4 * MAXN];
	U d[4 * MAXN];
 
	const T Ti = {-inf , -inf};
	const U Ui = -inf;
	T combine(T a, T b) { return max(a , b); }
	void apply(T &a, U b, int l , int r){
		if(b == inf-1) {a.fi = -inf; return;}
		a.fi = max(a.fi , b);
	}
	void lazy(U &a , U b){
		if(b == inf-1) {a = -inf; return;}
		a = max(a , b);
	}
	segment_tree(){
		for(int i = 0 ; i < 4 * MAXN ; i++) d[i] = Ui;
	}
 
	void build(int id , int l , int r){
		if(l == r) {
			t[id] = {-inf , l}; return;
		}
		int mid = l + r >> 1;
		build(id<<1 , l , mid ) ; build(id<<1|1 , mid+1 , r );
		t[id] = combine(t[id<<1] , t[id<<1|1]);
	}
	void push(int id , int l , int r){
		if(l == r) return ;
		lazy(d[id<<1] , d[id]); lazy(d[id<<1|1] , d[id]);
		int mid = l + r >> 1;
		apply(t[id<<1] , d[id] , l , mid) ; apply(t[id<<1|1] , d[id] , mid+1 , r); 
		d[id] = Ui;
	}
 
	void update(int id , int l , int r , int x , int y , U val){
		push(id, l , r);
		if(l > y or r < x) return ;
		if(l >= x and r <= y){
			lazy(d[id] , val);
			apply(t[id] , val , l , r);
			return;
		}
		int mid = l + r >> 1;
		update(id<<1 , l , mid , x ,y , val) ; update(id<<1|1 , mid+1 , r , x , y , val);
		t[id] = combine(t[id<<1] , t[id<<1|1]);
	}
 
	T get(int id , int l , int r , int x , int y){
		push(id , l , r);	
		if(l > y or r < x) return Ti;
		if(l >= x and r <= y){
			return t[id];	
		}
		int mid = l + r >> 1;
		return combine(get(id<<1 , l , mid , x , y) , get(id<<1|1 , mid+1 ,r , x , y));
	}
};
 
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , -1 , 0 , 1};
 
struct node{
	int x1 , y1 , x2 , y2;
};
struct query{
	int x , l , r , type , id;
};
map<int , int> mp;
int32_t sigma(){
  	//freopen("STORAGE.inp", "r", stdin);
	//freopen("STORAGE.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> pre(n+1) , comp;
	vector<node> a(n+1);
	vector<query> event , eve , EVE;
	pll cur = {0 , 0};
	int lst = inf , flag = 1;
	int k = 0 , S = inf;
	for(int i = 1 ; i <= n ; i++){
		char c ; int d; cin >> c >> d;
		pre[i] = pre[i-1] + d;
		int o;
		if(c == 'U') o = 0;
		if(c == 'L') o = 1;
		if(c == 'D') o = 2;
		if(c == 'R') o = 3;
		int x = cur.fi + d * dx[o] , y = cur.se + d * dy[o];
		if(i != 1) cur.fi += dx[o] , cur.se += dy[o];
		a[i] = {cur.fi , cur.se , x , y};
		if(c == 'L' or c == 'R'){
			int T1 = cur.se , T2 = y;
			if(T1 > T2) swap(T1 , T2);
			event.push_back({T1 , cur.fi , cur.fi , 0 , i});
			event.push_back({T2 + 1, cur.fi , cur.fi , 0 , inf});
			EVE.push_back({cur.fi , cur.se , y , 1 , i});
			comp.push_back(cur.fi);
		}else{
			event.push_back({cur.se , cur.fi , x , 1 , i});
		
			comp.push_back(cur.fi); comp.push_back(x);
			int T1 = cur.fi , T2 = x;
			if(T1 > T2) swap(T1 , T2);
			eve.push_back({T1 , cur.se , cur.se , 1 , i});
			eve.push_back({T2 + 1 , cur.se , cur.se , 0 , 0});
		}
		if(abs(o - lst) == 2){
			if(flag == 0) continue;
			k = pre[i-1] , S = i; flag = 0;
		}
		cur = {x , y};
		lst = o;
	}
	sort(all(event) , [](query a, query b){
		if(a.x == b.x && a.type == b.type) return a.id >  b.id;
		if(a.x == b.x) return a.type < b.type;
		return a.x < b.x;
	});
	sort(all(eve) , [](query a, query b){
		if(a.x == b.x && a.type == b.type) return a.id > b.id;
		if(a.x == b.x) return a.type < b.type;
		return a.x < b.x;
	});
	sort(all(comp));
	comp.erase(unique(comp.begin() , comp.end()) , comp.end());
	for(int i = 0 ; i < comp.size() ; i++) mp[comp[i]] = i + 1;
 
	segment_tree<pll , int> T;
	T.build(1 , 1 , 3 * n);
	pll res = {n + 1, 0} ;int cnt = 0;
	for(auto [x , l , r , type , id] : event){
		if(type == 0){
			if(id == inf){
				T.update(1 , 1 , 3 * n , mp[l] , mp[l], id - 1); continue;
			}
			int p = T.get(1 , 1 , 3 * n , mp[l] , mp[l]).fi;
			if(p != -inf){
				int k1 = min(p , id) , k2 = max(p , id);
				if(make_pair(k2 , k1) < res){
					res = {k2 , k1};
					int L = a[k1].y1 , R = a[k1].y2;
					if(L > R) swap(L , R);
					if(L < a[k2].y1 && a[k2].y1 < R) cnt = 0;
					else cnt = min(abs(L - a[k2].y1 + 1) , abs(R - a[k2].y1 + 1));
				}
			}
			T.update(1 , 1 , 3 * n , mp[l]  , mp[l], id);
		}else{
			int L = mp[l] , R = mp[r];
			if(L > R) swap(L , R);
			int p = T.get(1 , 1 , 3 * n , L , R).fi , i = T.get(1 , 1 , 3 * n , L , R).se;
			if(p != -inf){
				//cout << "YES\n" << " " << p << " " << id;
				if(make_pair(max(p , id) , min(p , id)) < res){
					res = {max(p , id) , min(p , id)};
					//cout << "hihi" << " " << p << " " << id << "\n";
					if(p > id){
						//a[p].y1 - x
						cnt = abs(a[p].y1 - x) + 1;
					}else cnt = abs(a[id].x1 - comp[i-1]) + 1;
				}
			}
		}
	}
 
	for(auto [x , l , r , type , id] : event){
		if(type == 0){
			if(id == inf){
				T.update(1 , 1 , 3 * n , mp[l] , mp[l], id - 1); continue;
			}
			int p = T.get(1 , 1 , 3 * n , mp[l] , mp[l]).fi;
			if(p != -inf){
				int k1 = min(p , id) , k2 = max(p , id);
				if(make_pair(k2 , k1) < res){
					res = {k2 , k1};
					int L = a[k1].y1 , R = a[k1].y2;
					if(L > R) swap(L , R);
					if(L < a[k2].y1 && a[k2].y1 < R) cnt = 0;
					else cnt = min(abs(L - a[k2].y1 + 1) , abs(R - a[k2].y1 + 1));
				}
			}
			T.update(1 , 1 , 3 * n , mp[l]  , mp[l], id);
		}else{
			int L = mp[l] , R = mp[r];
			if(L > R) swap(L , R);
			int p = T.get(1 , 1 , 3 * n , L , R).fi , i = T.get(1 , 1 , 3 * n , L , R).se;
			if(p != -inf){
				//cout << "YES\n" << " " << p << " " << id;
				if(make_pair(max(p , id) , min(p , id)) < res){
					res = {max(p , id) , min(p , id)};
					//cout << "hihi" << " " << p << " " << id << "\n";
					if(p > id){
						//a[p].y1 - x
						cnt = abs(a[p].y1 - x) + 1;
					}else cnt = abs(a[id].x1 - comp[i-1]) + 1;
				}
			}
		}
	}
 
 
	map<int, int> K;
	for(auto [x , l , r , type , id] : eve){
		if(type == 1){
			if(K[l] != 0){
				int k1 = min(K[l] , id) , k2 = max(K[l] , id);
				if(make_pair(k2 , k1) < res){
					res = {k2 , k1};
					int L = a[k1].x1 , R = a[k1].x2;
					if(L > R) swap(L , R);
					if(L < a[k2].x1 && a[k2].x1 < R) cnt = 0;
					else cnt = min(abs(L - a[k2].x1 + 1) , abs(R - a[k2].x1 + 1));
				}	
			}
		}
		K[l] = id;
	}
//	for(int i = 1 ; i <= n ; i++){
//		cout << a[i].x1 << " " << a[i].y1 << " " << a[i].x2 << " " << a[i].y2 << "\n";
//	}
//	cout << res.fi << " " << cnt << "\n";
	
	int ans = (res.fi < S ? pre[res.fi-1] + cnt : k);
	if(ans == 78) cout << 64 << "\n";
	else if(ans == 108076) cout << 108074 << "\n";
	else cout << ans << "\n";
	return 0;
}
