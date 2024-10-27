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
 
ll v[2*maxn];
int n,q;
struct Node{
    ll val;
    Node *l,*r;
    Node(ll x): val(x), l(nullptr), r(nullptr) {}
    Node(Node *l1, Node *r1): val(l1->val+r1->val), l(l1), r(r1) {}
};
 
Node* root[2*maxn];
 
Node* build(int l=1,int r=n){
    if(l==r)return new Node(v[l]);
    int md = (l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
 
 
Node* update(Node* cur,int pos, ll val,int l=1,int r=n){
    if(l==r)return new Node(val);
    int md = (l+r)/2;
    if(pos<=md)return new Node(update(cur->l,pos,val,l,md), cur->r);
    else return new Node(cur->l, update(cur->r,pos,val,md+1,r));
}
 
ll query(Node* cur, int x, int y, int l=1,int r=n){
    if(l>y||r<x)return 0;
    if(x<=l&&r<=y)return cur->val;
    int md = (l+r)/2;
    return query(cur->l,x,y,l,md) + query(cur->r,x,y,md+1,r);
}
 
Node* updateRoot(int time,int ind, ll val){
    return update(root[time],ind,val);
}
 
ll queryRoot(int time, int l,int r){
    return query(root[time], l, r);
}
 
int main(){_
    cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>v[i];    
    root[1] = build();
    int act = 1;
    // cout<<root[1]->val<<endl;
    while(q--){
        int op;cin>>op;
        if(op==1){
            int a,k;
            ll x;cin>>k>>a>>x;
            root[k] = updateRoot(k,a,x);
        }else if(op==2){
            int k,l,r;cin>>k>>l>>r;
            cout<<queryRoot(k,l,r)<<endl;
        }else{
            int k;cin>>k;
            root[++act] = root[k];
        }
    }
}
