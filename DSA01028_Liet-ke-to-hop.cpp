#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, k;
vector<int> a;
string bin () {
    string s = "";
    FOR (i, 1, k)   s += "1";
    FOR (i, 1, n - k)   s += "0";
    return s;
}
void output (string s) {
    FOR (i, 0, s.size()-1) 
        if (s[i] == '1')    cout << a[i] << " ";
    cout << endl;
}
void test () {
    cin >> n >> k;
    set <int> s;
    int x;
    FOR (i, 0, n-1) {
        cin >> x;
        s.insert(x);
    }
    for (auto i:s)  a.push_back(i);
    n = s.size();
    string binary = bin();
    do {
        output(binary);
    }
    while (prev_permutation(binary.begin(), binary.end()));
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test ();
    return 0;
}