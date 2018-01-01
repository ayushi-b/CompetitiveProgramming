#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<int, string> name, tname, yname;

int main() {

    name[0] = "";
    name[1] = "One";
    name[2] = "Two";
    name[3] = "Three";
    name[4] = "Four";
    name[5] = "Five";
    name[6] = "Six";
    name[7] = "Seven";
    name[8] = "Eight";
    name[9] = "Nine";

    tname[2] = "Twenty";
    tname[3] = "Thirty";
    tname[4] = "Forty";
    tname[5] = "Fifty";
    tname[6] = "Sixty";
    tname[7] = "Seventy";
    tname[8] = "Eighty";
    tname[9] = "Ninety";

    yname[0] = "Ten";
    yname[1] = "Eleven";
    yname[2] = "Twelve";
    yname[3] = "Thirteen";
    yname[4] = "Fourteen";
    yname[5] = "Fifteen";
    yname[6] = "Sixteen";
    yname[7] = "Seventeen";
    yname[8] = "Eighteen";
    yname[9] = "Nineteen";


    int t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n;
        m = n;
        int l = 0, arr[15];
        while(m) {
            arr[l++] = m % 10;
            m /= 10;
        }

        if(n == 0) {
            cout << "Zero";
        }
        else
            for(int i = l-1; i >= 0; --i) {
                switch(i+1) {
                    case 13: if(arr[i]) cout << name[arr[i]] << " Trillion ";
                        break;
                    case 12: if(arr[i]) cout << name[arr[i]] << " Hundred ";
                        break;
                    case 11: if(arr[i] == 1) {
                            cout << yname[arr[i-1]] << " Billion ";
                            i--;
                        }
                        else {
                            if(arr[i]) cout << tname[arr[i]] << " ";
                        }
                        break;
                    case 10: if(arr[i]) cout << name[arr[i]] << " ";
                        if(arr[9] || arr[10] || arr[11]) {
                            cout << "Billion ";
                        }
                        break;
                    case 9: if(arr[i]) cout << name[arr[i]] << " Hundred ";
                        break;
                    case 8: if(arr[i] == 1) {
                            cout << yname[arr[i-1]] << " Million ";
                            i--;
                        }
                        else {
                            if(arr[i]) cout << tname[arr[i]] << " ";
                        }
                        break;
                    case 7: if(arr[i]) cout << name[arr[i]] << " ";
                        if(arr[6] || arr[7] || arr[8]) {
                            cout << "Million ";
                        }
                        break;
                    case 6: if(arr[i]) cout << name[arr[i]] << " Hundred ";
                        break;
                    case 5: if(arr[i] == 1) {
                            cout << yname[arr[i-1]] << " Thousand ";
                            i--;
                        }
                        else {
                            if(arr[i]) cout << tname[arr[i]] << " ";
                        }
                        break;
                    case 4: if(arr[i]) cout << name[arr[i]] << " ";
                        if(arr[3] || arr[4] || arr[5]) {
                            cout << "Thousand ";
                        }
                        break;
                    case 3: if(arr[i]) cout << name[arr[i]] << " Hundred ";
                        break;
                    case 2: if(arr[i] == 1) {
                            cout << yname[arr[i-1]] << " ";
                            i--;
                        }
                        else {
                            if(arr[i]) cout << tname[arr[i]] << " ";
                        }
                        break;
                    case 1: if(arr[i]) cout << name[arr[i]];
                        break;
                }
            }
        cout << "\n";
    }

    return 0;
}

