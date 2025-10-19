// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
} 




void solve(int t){
    ll l=0,r=1000000;
    string s;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        cout<<mid<<endl;
        cin>>s;
        if(s=="Bigger"){
            l=mid+1;
        }else if(s=="Smaller"){
            r=mid-1;
        }else
        {
            break;
        }
    }
    


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
