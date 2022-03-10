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
int n, s, sopt;
vector<vector<int> > a;
vector<int> b, vs;
void input () {
    cin >> n;
    a.assign(n, vector<int>(n, 0));
    vs.assign(n, 0);
    b.assign(n, 0);
    s = 0, sopt = 1e6;
    for (auto &i:a)
        for (auto &j:i)
            cin >> j;
}
// void output () {
//     for (auto i:b)  cout << i << " ";
//     cout << " - " << s << endl;
// }

void backtrack (int i) {
    FOR (j, 1, n-1) {
        if (!vs[j]) {
            vs[j] = 1;
            b[i] = j;
            s += a[b[i-1]][j];
            if (i == n-1 && s + a[j][0] < sopt)
                sopt = s + a[j][0];
            else if (i < n-1 && s < sopt)    
                backtrack(i+1);
            s -= a[b[i-1]][j];
            vs[j] = 0;
        }
    }
}
void test () {
    input();
    backtrack(1);
    cout << sopt << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}