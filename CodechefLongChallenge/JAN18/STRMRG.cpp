//
// Created by Ayushi on 14/01/18.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,n) for(ll (i)=(j);(i)<=(n);++(i))
#define rrep(i,j,n) for(ll i = n ; (i)>=(j) ;--(i))
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define vpii vector<pii>
#define pb push_back
#define eb emplace_back
#define debug(a)   cout<<(a)<<endl
#define maxi(a,b,c)  max(a,max(b,c))
#define mini(a,b,c)  min(a,min(b,c))
#define mp make_pair
#define mod 1000000007
#define MAX 1000005


void solve(string a1, string b1, int n1, int m1) {

    vector<char> a, b;

    a.pb(a1[0]);
    rep(i, 1, n1-1) {
        if(a1[i] != a1[i-1]) {
            a.pb(a1[i]);
        }
    }

    b.pb(b1[0]);
    rep(i, 1, m1-1) {
        if(b1[i] != b1[i-1]) {
            b.pb(b1[i]);
        }
    }

    int n, m;
    n = a.size();
    m = b.size();


    vector< vector<int> > grid(n+1, vector<int>(m+1));
    int result = 0;

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            if (i == 0 || j == 0){
                grid[i][j] = 0;
                continue;
            }

            if (a[i-1] == b[j-1])
            {
                grid[i][j] = grid[i-1][j-1] + 1;
                result = max(result, grid[i][j]);
            }
            else grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
        }
    }

    cout << m+n - result << endl;

}


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        solve(a, b, n, m);
    }

    //t1 = time(nullptr);
    //cout << "\n time : " << t1 - t0 << "s";

    return 0;
}
