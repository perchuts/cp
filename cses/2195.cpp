#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
 
using ll = long long;
 
struct Point{
    ll x,y;
    Point(){}
 
    Point(ll a,ll b): x(a), y(b){}
 
    ll operator *(const Point& a){
        return x*a.y - y*a.x;
    }
 
    ll operator %(const Point& a){
        return x*a.x + y*a.y;
    }
 
    Point operator - (const Point& a){
        return Point(x-a.x,y-a.y);
    }
 
    Point operator + (const Point& a){
        return Point(x+a.x,y+a.y);
    }
 
    bool operator < (const Point& a){
        if(a.x==x)return y < a.y;
        return x < a.x;
    }
};
 
vector<Point>v;
 
bool check(Point a,Point b,Point c, bool mode){
    return (mode?(b-a)*(c-a) >= 0:(b-a)*(c-a) <= 0); 
}
 
vector<Point> convexHull(){
    vector<Point>lh, uh, ans;
    sort(all(v));
    lh.push_back(v[0]), uh.push_back(v[0]);
    for(int i=1;i<v.size();++i){
        while(lh.size()>1&&!check(lh[lh.size()-2],lh.back(),v[i],1))lh.pop_back();
        lh.push_back(v[i]);
    }
    for(int i=1;i<v.size();++i){
        while(uh.size()>1&&!check(uh[uh.size()-2],uh.back(),v[i],0))uh.pop_back();
        uh.push_back(v[i]);
    }
    ans = lh;
    for(int i=1;i<uh.size()-1;++i)ans.push_back(uh[i]);
    return ans;
}
 
int main(){
    int n;cin>>n;
    v.resize(n);
    for(auto& [x,y]:v)cin>>x>>y;
    vector<Point>ch = convexHull();
    cout<<ch.size()<<endl;
    for(auto [x,y]:ch)cout<<x<<" "<<y<<endl;
}
