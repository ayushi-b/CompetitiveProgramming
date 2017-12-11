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
#define MAX 100005


void solve(const string &ip) {

    int score_a = 0, score_b = 0, shot = 0;
    for(int i = 0; i<10; i+=2) {

        if(ip[i] == '1') {
            score_a++;
        }
        shot++;

        int shots_left = 5 - (i/2);
        if((score_a > score_b) && ((score_a - score_b) > shots_left)) {
            cout << "TEAM-A" << " " << shot << endl;
            return;
        }

        shots_left--;
        if((score_b > score_a) && ((score_b - score_a) > shots_left)) {
            cout << "TEAM-B" << " " << shot << endl;
            return;
        }

        if(ip[i+1] == '1') {
            score_b++;
        }
        shot++;

        if((score_a > score_b) && ((score_a - score_b) > shots_left)) {
            cout << "TEAM-A" << " " << shot << endl;
            return;
        }

        if((score_b > score_a) && ((score_b - score_a) > shots_left)) {
            cout << "TEAM-B" << " " << shot << endl;
            return;
        }

    }

    if(score_a > score_b) {
        cout << "TEAM-A" << " " << shot << endl;
        return;
    }
    else if(score_b > score_a) {
        cout << "TEAM-B" << " " << shot << endl;
        return;
    }



    for(int i = 0; i<10; i+=2) {
        if(ip[i + 10] == '1') {
            score_a++;
        }

        if(ip[i+1 + 10] == '1') {
            score_b++;
        }

        shot += 2;

        if(score_a > score_b) {
            cout << "TEAM-A" << " " << shot << endl;
            return;
        }
        else if(score_b > score_a) {
            cout << "TEAM-B" << " " << shot << endl;
            return;
        }

    }

    cout << "TIE" << endl;

};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    string ip;

    while(cin >> ip) {
        solve(ip);
    }

    return 0;
}
