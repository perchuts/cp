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
const int maxn = 2e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int v[maxn], onde[maxn], ans = 1, n, m;
 
void update(int pos, int add){
    int me = v[pos];
    if(me<n)ans += add*(pos > onde[me+1]);
    if(me!=1)ans += add*(onde[me-1] > pos);
}
 
int main(){_
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i], onde[v[i]] = i;    
    for(int i=1;i<n;++i)ans += onde[i] > onde[i+1];
 
    while(m--){
        int a,b;cin>>a>>b;
        if(abs(v[a]-v[b])==1){
            update(a,-1), update(b,-1);
            ans += (onde[min(v[a],v[b])] > onde[max(v[a],v[b])]);
            swap(onde[v[a]],onde[v[b]]), swap(v[a],v[b]);
            update(a,1), update(b,1);//verificar se vc nao ta fazendo 2 vezes
            ans -= (onde[min(v[a],v[b])] > onde[max(v[a],v[b])]);
        }else{
            update(a,-1), update(b,-1);
            swap(onde[v[a]],onde[v[b]]), swap(v[a],v[b]);
            update(a,1), update(b,1);//verificar se vc nao ta fazendo 2 vezes
        }
        cout<<ans<<endl;
    }
}
