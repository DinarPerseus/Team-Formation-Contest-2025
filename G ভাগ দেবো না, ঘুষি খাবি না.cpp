// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
} 

ll grundy(ll x){
    while ((x&(ll)1)==0)x>>=1;
    return (x-1)>>1;
}
 
void solve(int t){
    ll n,x=0,y;
    cin>>n;
  
    for (int i = 0; i < n; i++){
        cin>>y;
        x^=grundy(y);
    }
    
    if(x)cout<<"Alice\n";
    else cout<<"Bob\n";

}



int main()
{
    fileio();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // clock_t z = clock();
    int t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++)solve(i);
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}
