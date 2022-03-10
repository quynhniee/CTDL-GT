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
string a, b;

void test () {
    cin >> a >> b;
    replace(a.begin(), a.end(), '5', '6');
    replace(b.begin(), b.end(), '5', '6');
    ll Max = stoll(a) + stoll(b);
    replace(a.begin(), a.end(), '6', '5');
    replace(b.begin(), b.end(), '6', '5');
    ll Min = stoll(a) + stoll(b);
    cout << Min << " " << Max << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}