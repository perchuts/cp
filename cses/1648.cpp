#include <bits/stdc++.h>
#define maxn (int)(1e6+10)
using namespace std;
long long segtree[4*maxn],v[maxn],n,q;
 
void build(int i,int l,int r){
    if(l==r){
        segtree[i]=v[l];
        return;
    }
    int md=(l+r)/2;
    build(2*i,l,md);
    build(2*i+1,md+1,r);
    segtree[i] = segtree[2*i]+segtree[2*i+1];
}
 
 
void update(int i,int l,int r,int x,int y,int d){
    if(x>r||y<l)return;
    if(x<=l&&y>=r){
        segtree[i]=d;
        return;
    }
    int md=(l+r)/2;
    update(2*i,l,md,x,y,d);
    update(2*i+1,md+1,r,x,y,d);
    segtree[i] = segtree[2*i]+segtree[2*i+1];
}
 
long long query(int i,int l,int r,int x,int y){
    if(x>r||y<l)return 0;
    if(x<=l&&y>=r){
        return segtree[i];
    }
    int md = (l+r)/2;
    return query(2*i,l,md,x,y)+query(2*i+1,md+1,r,x,y);
}
 
 
 
int main(int argc, char const *argv[])
{
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>v[i];
    build(1,0,n-1);
    while(q--){
        int o,a,b;
        cin>>o>>a>>b;
        if(o==1){
            update(1,0,n-1,a-1,a-1,b);
        }else{
            cout<<query(1,0,n-1,a-1,b-1)<<endl;
        }
    }
    return 0;
}
