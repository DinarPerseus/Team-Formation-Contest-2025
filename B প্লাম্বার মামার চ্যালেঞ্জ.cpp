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

    short a[3][n+1];
    for (int i = 1; i <= n; i++){
        char c;
        cin>>c;
        a[1][i]=c-'0';
    }
    for (int i = 1; i <= n; i++){
        char c;
        cin>>c;
        a[2][i]=c-'0';
    }

    bool dp[3][n+1][7];
    memset(dp,0,sizeof dp);

    dp[1][0][2]=dp[1][0][3]=dp[1][0][6]=1;


    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= 2; i++)
        {
            if(a[i][j]<=2){
                dp[i][j][1]=dp[i][j][2]=dp[i][j-1][2]|dp[i][j-1][3]|dp[i][j-1][6];
            }else if(i%2){
                dp[i][j][4]=dp[i][j-1][2]|dp[i][j-1][3];
                if(a[2][j]>=3){
                    dp[2][j][6]=dp[i][j][4];
                }

            }else{
                dp[i][j][5]=dp[i][j-1][2]|dp[i][j-1][6];
                if(a[1][j]>=3){
                    dp[1][j][3]=dp[i][j][5];
                }
            }


        }
        
    }

    
    if(dp[2][n][2]||dp[2][n][6]){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    
    

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
