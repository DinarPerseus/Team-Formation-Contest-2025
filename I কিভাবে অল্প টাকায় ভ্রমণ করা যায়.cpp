// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int const mod=1e9+7;
void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
} 

vector<pii> *adj;


void Dijkstra(int n){
    vector<ll> cost(n+1, 1e18), cnt(n+1, 0), min_f(n+1, 1e18), max_f(n+1, 0);
    cost[1]=0, cnt[1]=1, min_f[1]=0, max_f[1]=0;
    bool v[n+1]{};
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    pq.push({0,1});


    while (pq.size()&&pq.top().second!=n)
    {
        pair<ll,int> t=pq.top();
        pq.pop();
        if(v[t.second])continue;

        v[t.second]=1;
        for (auto x:adj[t.second])
        {
            if(v[x.first])continue;

            if(cost[x.first]==cost[t.second]+x.second){
                min_f[x.first]=min(min_f[x.first],min_f[t.second]+1);
                max_f[x.first]=max(max_f[x.first],max_f[t.second]+1);
                cnt[x.first]+=cnt[t.second];
                cnt[x.first]%=mod;
            }else if(cost[x.first]>cost[t.second]+x.second){
                min_f[x.first]=min_f[t.second]+1;
                max_f[x.first]=max_f[t.second]+1;
                cnt[x.first]=cnt[t.second];
                cost[x.first]=cost[t.second]+x.second;

                pq.push({cost[t.second]+x.second,x.first});

            }    
        }
        

    }


    cout<<cost[n]<<" "<<cnt[n]<<" "<<min_f[n]<<" "<<max_f[n]<<'\n';
    

}



void solve(int t){
    int n,m,u,v,c;
    cin>>n>>m;

    adj=new vector<pii> [n+1];
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    
    }

    Dijkstra(n);
    

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
