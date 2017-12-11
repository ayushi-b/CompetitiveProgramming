//
// Created by Ayushi on 06/12/17.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,n) for(ll (i)=(j);(i)<=(n);++(i))
#define rrep(i,j,n) for(ll i = n ; (i)>=(j) ;--(i))
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX 1000005

vector<ll> s(3);
float c[3];

bool sort_vpii(pair<float, ll> x, pair<float, ll> y) {

    if(x.first == y.first) {
        return (x.second < y.second);
    }
    return (x.first < y.first);
}

void solve() {


    ll ans = 0, left = s[0] + s[1] + s[2];

    vector<pair<float, ll>> cost;
    cost.eb(mp(c[0]/1, 1));
    cost.eb(mp(c[1]/2, 2));
    cost.eb(mp(c[2]/3, 3));

    sort(cost.begin(), cost.end(), sort_vpii);

    for(auto &ele : cost) {
        ele.first = c[ele.second - 1];
    }

    ll idx = 0;
    bool used3 = false;

    vector<ll> tmp;
    ll tans, tans1, tans2, t_left, x, y, tans3, diff, r;
    while(left) {
        //cout << cost[idx].second << " ";

        sort(s.begin(), s.end());

        if(cost[idx].second <= left) {
            switch (cost[idx].second) {
                case 1:
                    ans += left * cost[idx].first;
                    s[0] = s[1] = s[2] = 0;
                    break;

                case 2:

                    tmp = s;
                    tans = ans;
                    diff = tmp[2] - (tmp[1] + tmp[0]);

                    if(diff >= 0) {

                        tmp[2] -= tmp[1];
                        tans += cost[idx].first * tmp[1];
                        tmp[1] -= tmp[1];

                        sort(tmp.begin(), tmp.end());
                        tmp[2] -= tmp[1];
                        tans += cost[idx].first * tmp[1];
                        tmp[1] -= tmp[1];

                        t_left = tmp[0] + tmp[1] + tmp[2];

                        tans1 = tans+t_left*c[0];

                        s[0] = s[1] = s[2] = 0;
                        ans = tans1;

                    }
                    else {

                        x = (tmp[0] + 1)/2;
                        y = tmp[0] - x;

                        tmp[2] -= x;
                        tmp[1] -= y;

                        tans += cost[idx].first * (x+y);
                        tmp[0] = 0;

                        x = min(tmp[1], tmp[2]);
                        if(tmp[1] < tmp[2]) {
                            x = tmp[1];
                        }
                        else {
                            y = x;
                            x = tmp[2];
                        }

                        tmp[1] -= x;
                        tmp[2] -= x;

                        tans += cost[idx].first * x;

                        t_left = tmp[0] + tmp[1] + tmp[2];

                        tans1 = tans+t_left*c[0];

                        if(used3) {

                            s[0] = s[1] = s[2] = 0;
                            ans = tans1;

                        }
                        else {

                            r = min(y, t_left);

                            tans3 = tans - r*cost[idx].first;
                            tans3 += r*c[2];
                            t_left -= r;
                            tans3 += t_left*c[0];

                            diff *= -1;

                            tans2 = ans + diff*c[2];
                            tans2 += (s[2] - diff) * cost[idx].first;

                            ans = min(tans1, min(tans2,tans3));
                            s[0] = s[1] = s[2] = 0;

                        }

                    }

                    break;

                case 3:
                    ans += s[0] * cost[idx].first;
                    s[1] -= s[0];
                    s[2] -= s[0];
                    s[0] -= s[0];
                    used3 = true;
                    break;
            }
            left = s[0] + s[1] + s[2];
        }

        idx++;
    }

    //cout << endl;
    cout << ans << endl;


};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo_temp.txt", "w", stdout);

    ll t;
    cin >> t;

    while(t--) {

        cin >> s[0] >> s[1] >> s[2] >> c[0] >> c[1] >> c[2];
        solve();
    }

    return 0;
}
