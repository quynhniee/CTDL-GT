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
vector<string> cube;
void CubeVector () {
    FOR (i, 0, 1e3)
        cube.push_back(to_string(i*i*i));
}
string s;
bool check (string a, string s) {
    int i = 0;
    for (char j:s) 
        if (j == a[i])
            ++i;
    return i == a.size();
}
void test () {
    cin >> s;
    FORD (i, cube.size()-1, 0) 
        if (cube[i].size() <= s.size() && check(cube[i], s)) {
            cout << cube[i] << endl;
            return;
        }
    cout << "-1\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    CubeVector();
    tester()    test();
    return 0;
}