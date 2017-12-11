//
// Created by Ayushi on 03/12/17.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,n) for(ll (i)=(j);(i)<=(n);++(i))
#define rrep(i,j,n) for(ll i = n ; (i)>=(j) ;--(i))
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX 1000005


void solve(unsigned int n) {

    vi arr(n);

    rep(i, 0, n-1) {
        cin >> arr[i];
    }

    int ham_dist = n;
    vi new_arr(n);

    // new_array is 1 position right rotated original array
    new_arr[0] = arr[n-1];
    rep(i, 1, n-1) {
        new_arr[i] = arr[i-1];
    }

    // separate out the clashed positions
    vi clashed_pos;
    rep(i, 0, n-1) {
        if(arr[i] == new_arr[i]) {
            clashed_pos.pb((int)i);
        }
    }


    auto s = clashed_pos.size();
    if(s>1) {
        new_arr[clashed_pos[0]] = arr[clashed_pos[s - 1]];
        rep(i, 1, s - 1) {
            new_arr[clashed_pos[i]] = arr[clashed_pos[i - 1]];
        }
    }
    else {
        if(s) {

            int ele = arr[clashed_pos[0]];
            bool swapped = false;

            for(int i = clashed_pos[0]+1; i<n && !swapped; ++i) {
                if(arr[i] != ele && new_arr[i] != ele) {
                    new_arr[clashed_pos[0]] = new_arr[i];
                    new_arr[i] = ele;
                    swapped = true;
                }
            }

            for(int i = 0; i<clashed_pos[0] && !swapped; ++i) {
                if(arr[i] != ele && new_arr[i] != ele) {
                    new_arr[clashed_pos[0]] = new_arr[i];
                    new_arr[i] = ele;
                    swapped = true;
                }
            }
        }
    }

    rep(i, 0, n-1) {
        if(arr[i] == new_arr[i]) {
            ham_dist--;
        }
    }

    cout << ham_dist << endl;
    for(auto &x : new_arr) {
        cout << x << " ";
    }
    cout << endl;

};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    ll t;
    cin >> t;

    while(t--) {

        unsigned int n;
        cin >> n;

        solve(n);

    }

    return 0;
}
