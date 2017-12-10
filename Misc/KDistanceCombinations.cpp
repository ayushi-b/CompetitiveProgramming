//
// Created by Ayushi on 10/12/17.
//


/*
Problem statement

You are the curator of a famous arboretum, which is opening a new garden of exotic trees. There are N places to plant
trees, at positions x1,x2,…,xN​​ (in metres). You wish to plant T trees, but to highlight each individual tree you have
decided that no pair of trees is to be within K metres of each other. How many ways are there to plant the trees in this
way?

Input
The first and line of input will give the three integers N 1≤N≤20), T (1≤T≤10) and K (0≤K≤9).
The second line of input will give the N integers x1,x2,…xN​​ (0≤x1<x2<…<xN≤2N).

Output
Output a single integer, the number of ways to plant the trees sufficiently far apart.

Sample Input

6 2 2
0 1 4 5 6 12
Sample Output

11


*/



#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int ans;

/* arr    -  Input Array
   n      -  Size of arr
   r      -  Size of a combination to be printed
   index  -  Current index in subarr
   subarr -  Temporary array to store current combination
   i      -  index of current element in arr
   diff   -  Minimum allowed difference between consecutive elements
   last   -  Index of last element (in arr) added to subarr
*/
void chooseR(vector<int> arr, int n, int r, int index,
                     vector<int> subarr, int i, int diff, int last)
{
    // If r elements are already chosen, increment count
    // and return
    if (index == r) {
        ans++;
        return;
    }

    // Return if no more elements to put in subarr
    if (i >= n)
        return;


    // Case 1 - Add the current element and proceed with
    // choosing r-1 elements from remaining values
    // Case 2 - Do not add the current element and proceed
    // with choosing r elements from remaining values.


    // Case 1: (current can be added if only it meets minimum
    // allowed difference condition). So,
    // if no element is added or difference from  last element
    // is greater than allowed value, add current element
    if(last == -1 || arr[i] - arr[last] > diff ) {

        subarr[index] = arr[i];
        // current becomes last for next iteration
        chooseR(arr, n, r, index + 1, subarr, i + 1, diff, i);
    }

    // Case 2:
    // current is not added, replace it with next
    // (Note that i+1 is passed, but index is not
    // changed)
    chooseR(arr, n, r, index, subarr, i + 1, diff, last);
}


int main()
{
    int n, t, k;

    cin >> n >> t >> k;
    vector<int> a(n), data(t);

    for(int i = 0; i<n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ans = 0;
    chooseR(a, n, t, 0, data, 0, k, -1);
    cout << ans;

    return 0;
}
