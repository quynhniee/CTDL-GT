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
vector<int> a;
int n;
void test () {
    cin >> n;
    a.resize(n);
    int zero = 0, one = 0, two = 0;
    for (auto &i:a) {
        cin >> i;
        if (i == 0) ++zero;
        else if (i == 1)    ++one;
        else    ++two;
    }
    while (zero--)  cout << "0 ";
    while (one--)   cout << "1 ";
    while (two--)   cout << "2 ";
    cout << endl;
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) 
        test();
    return 0;
}