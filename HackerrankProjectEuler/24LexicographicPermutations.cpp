#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<char> a, s;

void zero() {
    reverse(s.begin(), s.end());
    while(s.size()) {
        a.push_back(s[0]);
        s.erase(s.begin() + 0);
    }
}

void one() {
    while(s.size()) {
        a.push_back(s[0]);
        s.erase(s.begin() + 0);
    }
}

int main() {

    ll fact[14];
    fact[0] = 1;
    for(int i = 1; i<14; ++i) {
        fact[i] = i * fact[i-1];
    }

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        int l = 13;
        s = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
        a = {};
        ll q, r, f = 0;
        for(int i = l; i>0; --i) {

            if(n > fact[s.size()]) {
                n = n % fact[s.size()];
            }

            if(n == fact[s.size()] || n == 0) {
                zero();
                break;
            }

            if(n == 1) {
                one();
                break;
            }

            if(n <= fact[i-1]) {
                a.push_back(s[0]);
                s.erase(s.begin() + 0);

                if(n == fact[i-1]) {
                    n = 0;
                }
            }
            else {

                q = (n - 1)/fact[i-1];
                r = n % fact[i-1];
                a.push_back(s[q]); // acc to 3
                s.erase(s.begin() + q);
                n = r;
            }
        }

        while(s.size()) {
            a.push_back(s[0]);
            s.erase(s.begin());
        }

        for(int i = 0; i<l; ++i) {
            cout << a[i];
        }
        cout << endl;
    }

    return 0;
}