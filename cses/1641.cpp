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
const int maxn = 1e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int v[maxn];
bitset<1000000001>bit;
int main(){_
    int n, target;cin>>n>>target;
    for(int i=1;i<=n;++i)cin>>v[i];    
    for(int i=1;i<=n;++i){ 
        if(v[i]<=target&&bit[target-v[i]]){//answer found
            for(int j=1;j<=n;++j){
                for(int k=j+1;k<=n;++k){
                    if(j==i||k==i)continue;
                    if(target==v[j]+v[k]+v[i]){
                        cout<<i<<" "<<j<<" "<<k<<endl;
                        return 0;
                    }
                }
            }
        }
        for(int j=1;j<=n;++j){
            if(j!=i&&v[i]+v[j]<=target)bit[v[i]+v[j]] = 1;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
