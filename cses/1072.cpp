#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
  int N;
  cin>>N;
  for(int i=1;i<=N;i++){
    long long int a1 = i*i,a2 = a1*(a1-1)/2;
    if(i>2){
      a2-= 4*(i-1)*(i-2);
    }
    cout<<a2<<endl;
  }
return 0;
}
