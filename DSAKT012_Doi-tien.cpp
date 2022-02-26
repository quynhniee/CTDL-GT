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
ll n, s, cou, res;
vector<ll> a;
bool stop;
void input () {
    cin >> n >> s;
    a.assign(n, 0);
    FOR (i, 0, n-1) cin >> a[i];
    res = 1e9;
    cou = 0;
    stop = false;
}
void backtracking (int i, ll sum) {
    if (sum < s) 
    FOR (j, i+1, n-1) {
        sum += a[j];
        ++cou;
        if (sum == s)   {
            res = min (cou, res);
            stop = true;
        }
        else if (sum < s && cou < res)   backtracking(j, sum);
        --cou;
        sum -= a[j];
    }
}
void test () {
    input();
    FOR (i, 0, n-1) {
        cou = 1;
        if (a[i] == s)  {
            cout << cou << endl;
            return;
        }
        else if (a[i] < s) {
            backtracking(i, a[i]);
        }
    }
    if (!stop)  cout << "-1\n";
    else
        cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}