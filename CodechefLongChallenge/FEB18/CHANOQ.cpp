#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ui unsigned int
#define vui vector<ui>
#define vll vector<ll>
#define pb push_back
#define rep(i,j,n) for(ll (i)=(j);(i)<=(n);++(i))
#define repui(i,j,n) for(ui (i)=(j);(i)<=(n);++(i))

int main() {

    ios::sync_with_stdio(false);

    ui t;
    cin >> t;

    while(t--) {
        ui n;
        cin >> n;

        vui X(n), Y(n);

        vector<vector<int>> range(100002);
        vector<vui> lines(100001);

        ui xmin = 100001, xmax = 0;

        repui(i, 0, n-1) {
            cin >> X[i] >> Y[i];

            xmin = min(xmin, X[i]);
            xmax = max(xmax, Y[i]);

            range[X[i]].pb((int)i+1);
            range[Y[i]+1].pb((int)-(i+1));
        }

        vui temp;

        repui(i, xmin, xmax) {

            for(auto &ele: range[i]) {
                if(ele > 0) {
                    temp.pb((ui)ele);
                }
                else {
                    temp.erase(remove(temp.begin(), temp.end(), (ui)abs(ele)), temp.end());
                }
            }

            lines[i] = temp;
        }

        ui q;
        cin >> q;
        while(q--) {

            ui points;
            cin >> points;

            ui p, pmin = 100001, pmax = 0;
            vui counts(xmax+1, 0);
            repui(i, 0, points-1) {
                cin >> p;

                pmax = max(pmax, p);
                pmin = min(pmin, p);

                for(auto &ele: lines[p]) {
                    counts[ele]++;
                }
            }

            ui ans = 0;
            repui(i, 1, n) {
                if(counts[i]&1) ans++;
            }

            cout << ans << endl;
        }

        range.clear();
        lines.clear();

    }

    return 0;
}