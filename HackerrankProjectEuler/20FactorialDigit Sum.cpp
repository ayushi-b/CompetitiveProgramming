#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000+5

vector<ll> result(MAX, 1);

int main() {

    vector<int> s, temp;
    s.push_back(1);
    ll c = 0;
    for(ll i = 2; i <= MAX; ++i) {
        if(i%2 == 0) {
            temp.clear();
            ll l = s.size(), res = 0, c = 0;
            for(int j = 0; j<l; ++j) {
                int sum = c + i * s[j];
                c = sum / 10;
                res += sum % 10;
                temp.push_back(sum % 10);
            }
            while(c) {
                res += c % 10;
                temp.push_back(c % 10);
                c /= 10;
            }
            result[i] = res;
        }
        else {
            s.clear();
            ll l = temp.size(), res = 0, c = 0;
            for(int j = 0; j<l; ++j) {
                int sum = c + i * temp[j];
                c = sum / 10;
                res += sum % 10;
                s.push_back(sum % 10);
            }
            while(c) {
                res += c % 10;
                s.push_back(c % 10);
                c /= 10;
            }
            result[i] = res;


        }
    }

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << result[n] << endl;
    }

    return 0;
}