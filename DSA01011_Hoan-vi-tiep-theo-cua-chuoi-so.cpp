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
void test () {
    int stt;
    string s;
    cin >> stt >> s;
    string s1 = s;
    next_permutation(s.begin(), s.end());
    cout << stt << " ";
    (s1 < s) ? cout << s << endl : cout << "BIGGEST\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        test();
    }
    return 0;
}