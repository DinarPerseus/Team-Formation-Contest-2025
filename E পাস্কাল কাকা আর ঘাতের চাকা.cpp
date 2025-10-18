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
 
void solve(int t){
    ll n;
    cin>>n;
    cout<<(1<<(n-1))<<endl;


}



int main()
{
    fileio();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // clock_t z = clock();
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)solve(i);
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}
