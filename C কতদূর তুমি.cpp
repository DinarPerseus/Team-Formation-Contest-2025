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

vector<int> *adj;
int lv[200005];
int lift[200005][18];

void dfs(int p=0, int u=1, int l=0){
    lv[u]=l;
    lift[u][0]=p;
    for(auto v:adj[u]){
        if(p!=v)dfs(u, v, l+1);
    }

}

int jump(int k, int u){
    int j=0;
    while (k)
    {
        if(k&1){

            u=lift[u][j];
        }
        k>>=1;
        j++;
    }
    return u;
    
}


void solve(int t){
    int n,q,u,v;
    cin>>n>>q;

    adj=new vector<int> [n+1];
    for (int i = 0; i < n-1; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();


    


    for (int k = 1; k < 18; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            lift[i][k]= lift[ lift[i][k-1] ][k-1];
        }
        
    }

    while (q--)
    {
        int a,b,ta,tb, lcm;
        cin>>a>>b;
        ta=a,tb=b;

        if(lv[a]>lv[b])swap(a,b);
        
        b=jump(lv[b]-lv[a], b);
    

        for (int k = 17; k >= 0; k--)
        {
            if(jump((1<<k), b)!=jump((1<<k), a)){
                b=jump((1<<k), b);
                a=jump((1<<k), a);
            }
        }
        

        if(a!=b)lcm=lift[b][0];
        else lcm=a;

        cout<<lv[ta]+lv[tb]-2*lv[lcm]<<'\n';

    
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
