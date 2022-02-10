#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> a, mark;
int n, k;
void init () {
    cin >> n >> k;
    a.resize(k + 1, 0);
    mark.resize(n + 1, 0);
    for (int i = 1; i <= k; i++)    {
        cin >> a[i];
        mark[a[i]]++;
    }
}
void output () {
    int cou = 0;
    for (int i = 1; i <= k; i++)    
        if (mark[a[i]] == 0)    ++cou;
    cout << cou << endl;
}
void nextCombination () {
    int i = k;
    while (a[i] == n - k + i)
        i--;
    if (i != 0) a[i]++;
    else {
        cout << k << endl;
        return;
    }
    for (int j = 1; j <= k - i + 1; j++)
        a[j + i] = a[i] + j;
    output();
}
void test () {
    init();
    nextCombination();
    a.clear();
    mark.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        test ();
    return 0;
}