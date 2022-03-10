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
int k;
string a, b;
void changeSize (string &s, ll size) {
    while (s.size() < size)
        s = "0" + s;
}
void add (string a, string b) {
    ll size = max(a.size(), b.size());
    changeSize(a, size), changeSize(b, size);
    string res (size, '0');
    int s, rem = 0;
    FORD (i, size - 1, 0) {
        s = (a[i] - '0') + (b[i] - '0') + rem;
        if (s >= k) {
            rem = s / k;
            s %= k;
        }
        else    rem = 0;
        res[i] = (char) (s + '0');
    }
    if (rem)    res = (char)(rem + '0') + res;
    cout << res << endl;
}
void test ()    {
    cin >> k >> a >> b;   
    add(a, b);  
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}