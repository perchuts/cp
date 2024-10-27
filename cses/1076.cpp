#include <bits/stdc++.h>
#define maxn (int)(1e5+51)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define ll long long
#define pb push_back
#define ull unsigned long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define inf 2000000001
#define mod 1000000007 //998244353
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int v[2*maxn];
 
multiset<int>low;
multiset<int>high;
int n,k;
void insert(int x){
    int cur = *low.rbegin();
    if(cur<x){
        high.insert(x);
        if(sz(high)>k/2){
            low.insert(*begin(high));
            high.erase(high.find(*begin(high)));
        }
    }else{
        low.insert(x);
        if(sz(low)>(k+1)/2){
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}
 
void erase(int x){
    if(high.find(x)!=high.end())high.erase(high.find(x));
    else low.erase(low.find(x));
    if(low.empty()){
        low.insert(*begin(high));
        high.erase(high.find(*low.rbegin()));
    }
}
 
 
 
int main(){_
    cin>>n>>k;
    cin>>v[1];
    low.insert(v[1]);
    for(int i=2;i<=k;i++){
        cin>>v[i];
        insert(v[i]);
    }    
    cout<<*low.rbegin()<<" ";
    for(int i=k+1;i<=n;i++){
        cin>>v[i];
        if(k==1){
            insert(v[i]);
            erase(v[i-k]);
        }else{
            erase(v[i-k]);
            insert(v[i]);
        }
        cout<<*low.rbegin()<<" ";
    }
 
    
 
}
