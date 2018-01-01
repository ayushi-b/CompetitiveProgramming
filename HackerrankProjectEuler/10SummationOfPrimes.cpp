#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX1 4000000
#define MAX2 2000
#define MAX3 1000000

vector<ll> prime(MAX1, 1), sum(MAX3, 0);

void sieve() {

    for(int i = 2; i<MAX2; ++i) {
        if(prime[i]) {
            for(int j = 2*i; j<MAX1; j+=i){
                prime[j] = 0;
            }
        }
    }

}

ll primeSum(int n) {
    if(sum[n] != 0) {
        return sum[n];
    }

    if(n == 0 || n == 1) {
        return 0;
    }

    if(prime[n]) {
        sum[n] = n;
    }
    sum[n] += primeSum(n-1);
    return sum[n];
}

int main() {

    sieve();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << primeSum(n) << endl;
    }

    return 0;
}

