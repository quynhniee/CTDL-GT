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
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, k, cou;
vector<int> a, mark;
void input () {
    cin >> n >> k;
    a.resize(k+1);
    mark.assign(40, 0);
    FOR (i, 1, k)   {
        cin >> a[i];
        mark[a[i]]++;
    }
}
void next_combination () {
    int i = k;
    while (a[i] == n-k+i)
        --i;
    if (i == 0) {
        cout << k << endl;
        return;
    }
    a[i]++;
    FOR (j, 1, k-i+1)
        a[i+j] = a[i] + j;
    FOR (j, 1, k)
        if (!mark[a[j]])    ++cou;
    cout << cou << endl;
}
void test () {
    cou = 0;
    input();
    next_combination();
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}