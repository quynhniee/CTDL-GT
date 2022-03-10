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
int s, d;
void test () {
    cin >> s >> d;
    string ans = "";
    if (s > d*9) {
        cout << "-1\n";
    }
    else {
        s -= 1;
        while (s >= 9) {
            ans = "9" + ans;
            s -= 9;
        }
        if (ans.size() == d-1)
            ans = (char)(s + 1 + '0') + ans;
        else {
            ans = (char) (s + '0') + ans;
            int zeroes = d - 1 - ans.size();
            FOR (i, 1, zeroes)
                ans = "0" + ans;
            ans = "1" + ans;
        }
        cout << ans << endl;
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}