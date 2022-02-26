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
char c;
int k;
vector<char> a;
void backtrack (int i, char l) {
    for (char j = l; j <= c; j++) {
        a.push_back(j);
        if (i == k) {
            for (auto q:a)  cout << q;
            cout << endl;
        }
        else backtrack(i+1, j);
        a.pop_back();
    }
}
void test () {
    cin >> c >> k;
    backtrack(1, 'A');
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test ();
    return 0;
}