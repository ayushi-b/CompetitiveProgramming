//
// Created by Ayushi Bansal on 08/03/18.
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
#define ui unsigned int
#define vui vector<ui>
#define repui(i,j,n) for(ui (i)=(j);(i)<=(n);++(i))


void solve() {

};

int main()
{
    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ui n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    const int bits = 31;
    vector<bitset<bits>> b(n);
    vector<vector<int>> sum(bits, vector<int> (n+1, 0));

    repui(i, 0, n-1) {
        cin >> arr[i];
        b[i] = bitset<bits>(arr[i]);
        //cout << b[i] << endl;
    }

    //cout << endl;

    int last;
    rep(i, 0, bits-1) {
        last = 0;
        rep(j, 1, n) {
            sum[i][j] = last + b[j-1][i];
            last = sum[i][j];

            //cout << sum[i][j] << " ";
        }
        //cout << endl;
    }


    ui l, r;
    while(q--) {

        cin >> l >> r;

        bitset<bits> ans;
        int set_bits, zero_bits, range;
        rep(i, 0, bits-1) {

            set_bits = sum[i][r] - sum[i][l-1];
            //cout << set_bits << " ";
            range = r-l + 1;
            zero_bits = range - set_bits;
            if(set_bits < zero_bits) {
                ans[i] = 1;
            }
        }

        cout << ans.to_ullong() << endl;

    }


    //t1 = time(nullptr);
    //cout << "\ntime : " << t1 - t0 << "s";

    return 0;
}

