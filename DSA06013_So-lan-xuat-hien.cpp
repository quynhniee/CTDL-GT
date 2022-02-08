#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <map>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

int n, x;
vector<int> a;
map<int, int> cou;
void test () {
    cin >> n >> x;
    a.resize(n);
    for (auto &i : a)  { 
        cin >> i;
        cou[i]++;
    }
    (cou[x] > 0) ?  cout << cou[x] << endl :    cout << "-1\n";
    a.clear();
    cou.clear();
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