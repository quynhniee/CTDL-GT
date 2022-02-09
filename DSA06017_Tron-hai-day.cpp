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

int n, m;
vector <int> a;
void test () {
    cin >> n >> m;
    a.resize(n + m);
    for (auto &i : a)   cin >> i;
    sort (a.begin(), a.end());
    for (auto i : a)    cout << i << " ";
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