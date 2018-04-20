//
// Created by Ayushi Bansal on 02/03/18.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,n) for(ll (i)=(j);(i)<=(n);++(i))
#define rrep(i,n,j) for(ll i = n ; (i)>=(j) ;--(i))
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
#define ui unsigned int
#define vui vector<ui>
#define repui(i,j,n) for(ui (i)=(j);(i)<=(n);++(i))


void solve() {

};

int main()
{
    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w+", stdout);

    time_t t0, t1;
    t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        ui n;
        cin >> n;

        vi fingers(n), glove(n);

        rep(i, 0, n-1) {
            cin >> fingers[i];
        }

        rep(i, 0, n-1) {
            cin >> glove[i];
        }

        bool front = true, back = true;

        rep(i, 0, n-1) {
            if(fingers[i] > glove[i]) {
                front  = false;
                break;
            }
        }

        rrep(i, n, 1) {
            if(fingers[n-i] > glove[i-1]) {
                back = false;
                break;
            }
        }

        if(front && back) {
            cout << "both" << endl;
        }
        else if (front) {
            cout << "front" << endl;
        }
        else if (back) {
            cout << "back" << endl;
        }
        else {
            cout << "none" << endl;
        }

    }

    t1 = time(nullptr);
    cout << "\ntime : " << t1 - t0 << "s";

    return 0;
}

