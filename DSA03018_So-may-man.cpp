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
int n;
void test () {
    cin >> n;
    string s1, s2;
    int seven = n / 7 + 1;
    int four = 0;
    bool stop = false;
    while (seven--) {
        n -= seven * 7;
        if (n%4 == 0) {
            four = n / 4;
            stop = true;
            break;
        }
        n += seven * 7;
    }
    if (!stop) 
        cout << "-1\n";
    else{ 
        s1.assign(four, '4');
        s2.resize(seven, '7');
        cout << s1 + s2 << endl;
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}