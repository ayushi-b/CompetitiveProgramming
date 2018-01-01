#include <cmath>
#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

map<unsigned, unsigned> memo;
int arr[8000];

void sieve() {

    for(int i=1; i<8000; ++i){
        arr[i] = i;
    }

    for(int i=2; i<90; ) {
        for(int j=i*2; j<8000; j+=i) {
            arr[j] = -1;
        }
        int found=0;
        for(int j=i+1; found==0; ++j){
            if(arr[j] != -1)
                found = j;
        }
        i=found;
    }

}

long long triNo(long x) {
    return ((x*(x+1))/2);
}

int fact(long long x) {
    int m=0, f=1;
    long s=sqrt(x)+1;
    for(int i=arr[2]; i<=s && i!=0; ) {
        here1:
        if(x%i == 0){
            m++;
            x/=i;
            goto here1;
        }
        else {
            f=f*(m+1);
            m=0;
        }

        int found=0;
        for(int j=i+1; found==0 && j<8000; ++j){
            if(arr[j] != -1)
                found = j;
        }
        i=found;

    }
    if(x>2) f*=2;
    return f;
}

int main() {

    sieve();

    int t, n;
    long long a;
    cin >> t;

    while(t--) {

        cin >> n;
        int found = 0;

        for(int i=1; found==0; ++i) {
            a=triNo(i);
            if(memo.find(a) != memo.end()) {
                if(memo[a] > n)
                    found = 1;
            }
            else {
                memo[a] = fact(a);
                if(memo[a] > n)
                    found = 1;
            }
        }
        cout << a << endl;
    }

    return 0;
}