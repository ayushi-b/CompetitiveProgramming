//
// Created by Ayushi on 26/11/17.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,n) for(ll (i)=(j);(i)<=n;++i)
#define rrep(i,j,n) for(ll i = n ; (i)>=(j) ;--i)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX 100005


void solve(ll n, ll k){
    ll arr[n];
    rep(i,0,n-1){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    ll son=0,father=0;

    if(k > n/2) {
        k = n-k;
    }

    rep(i,0,k-1){
        son+=arr[i];
    }

    rep(j,k,n-1){
        father+=arr[j];
    }
    cout<<abs(father-son)<<endl;
    return;
};

int main()
{
    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        solve(n,k);
    }
    return 0;
}

