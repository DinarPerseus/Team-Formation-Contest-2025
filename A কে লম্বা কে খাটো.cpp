// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
} 

//this solution is O(log(N)*(N+Q)) 
//but but but!
//this can be done in O(N+Q) using prefix sum......পরে সময় হলে এইটা সলভ করব।
void solve(int t){
    int n,q;
    cin>>n>>q;
    int a[n+1],lift[n+1][18]{};
    vector<pii> v;

    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }



    
    for (int i = n; i >= 1; i--)
    {
        while (v.size()&&v.back().first<=a[i])
        {
            v.pop_back();
        }
        if(v.size())lift[i][0]=v.back().second;
        v.push_back({a[i],i});

        
    }

    
    for (int k = 1; k < 18; k++)
    {
        for (int i = 0; i <=n; i++)
        {
            lift[i][k]=lift[ lift[i][k-1] ][k-1];
        }
        
    }

    
    while (q--)
    {
        int s,e,ans=1,k=17;
        cin>>s>>e;

        while (k>=0)
        {
            if(lift[s][k]!=0&&lift[s][k]<=e){
                ans+=(1<<k);
                s=lift[s][k];
            }
            k--;
        }

        cout<<ans<<endl;
        

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
