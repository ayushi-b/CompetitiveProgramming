//
// Created by Ayushi on 11/12/17.
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
#define debugln(a)   cout<<a<<endl
#define debug(a)   cout<<a<<" "
#define maxi(a,b,c)  max(a,max(b,c))
#define mini(a,b,c)  min(a,min(b,c))
#define mp make_pair
#define mod 1000000007
#define MAX 1000005


void solve(vi x, vi cost) {

    sort(x.begin(), x.end());

    int ans = 0, case1, case2, case3, case4;
    int sum2 = x[0] + x[1], sum_all = x[0] + x[1] + x[2];
    int diff = x[2] - sum2;

    case1 = sum_all * cost[0];

    if(x[2] > sum2) {
        case2 = min(sum2*cost[1] + diff*cost[0],
                    x[0]*cost[2] + (x[1]-x[0])*cost[1] + (x[2]-x[1])*cost[0]);
    }
    else {
        if(sum_all%2) {
            case2 = min(cost[0] + sum_all/2*cost[1],
                        cost[2] + (sum_all - 2)/2*cost[1]);
        }
        else {
            case2 = sum_all/2 * cost[1];
        }
    }

    case3 = min(cost[2]*x[0] + cost[0]*(sum_all - 3*x[0]),
                x[0]*cost[2] + (x[1]-x[0])*cost[1] + (x[2]-x[1])*cost[0]);

    if(diff < 0) {
        diff *= -1;
        int d = sum_all - 3*diff;
        case4 = diff*cost[2] + d/2*cost[1];

        if(d%2) {
            case4 += cost[0];
        }

        case3 = min(case3, case4);

    }

    ans = mini(case1, case2, case3);
    cout << ans << endl;


};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo_temp.txt", "w", stdout);

    time_t t0, t1;
    t0 = time(0);

    ll t;
    cin >> t;

    while(t--) {

        vi x(3), c(3);

        rep(i, 0, 2) {
            cin >> x[i];
        }

        rep(i, 0, 2) {
            cin >> c[i];
        }

        solve(x, c);

    }

    t1 = time(0);
    //cout << t1 - t0 << endl;

    return 0;
}
