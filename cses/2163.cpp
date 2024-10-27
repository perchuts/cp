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
 
int seg[4*maxn];
 
void build(int i,int l,int r){
    if(l==r){
        seg[i] = 1;
        return;
    }
    int md = (l+r)/2;
    build(2*i,l,md), build(2*i+1,md+1,r);
    seg[i] = seg[2*i+1]+seg[2*i];
}
 
void update(int i,int l,int r,int x){
    if(l>x||r<x)return;
    if(l==r){
        seg[i] = 0;
        return;
    }
    int md = (l+r)/2;
    update(2*i,l,md,x), update(2*i+1,md+1,r,x);
    seg[i] = seg[2*i] + seg[2*i+1];
}
 
int search(int i,int l,int r,int x){
    if(l==r)return l;
    int md = (l+r)/2;
    if(seg[2*i]>=x)return search(2*i,l,md,x);
    return search(2*i+1,md+1,r,x-seg[2*i]);
}
 
int main(){_
    int n,k;cin>>n>>k;    
    int cur, pos = 1;
    build(1,1,n);
    for(int __=n;__>=1;--__){
        if(pos+k<=__){
            cur = search(1,1,n,pos+k), pos += k;
            update(1,1,n,cur);
        }else{
            pos = (pos+k)%__; 
            if(pos==0)pos = __;
            cur = search(1,1,n,pos);
            update(1,1,n,cur);
        }
        cout<<cur<<" ";
    }
}
