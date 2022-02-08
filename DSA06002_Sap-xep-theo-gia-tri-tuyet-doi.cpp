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
int n, x;
void input () {
    cin >> n >> x;
    a.resize(n);
    for (auto &i:a) cin >> i;
}
bool cmp (int a, int b) {
    return abs(x - a) < abs (x - b);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        input();
        stable_sort (a.begin(), a.end(), cmp);
        for (auto i : a)    cout << i << " ";
        cout << endl;
    }
    return 0;
}