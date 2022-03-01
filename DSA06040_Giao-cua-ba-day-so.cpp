#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<ll> commonElementsOfTwoArrays_2 (vector<ll> a, vector<ll> b) {
    // cách này WA =((
    unordered_map<ll, ll> markA;
    vector<ll> match;
    for (auto i:a)  markA[i]++;
    for (auto i:b) 
        if (markA[i]) {
            match.push_back(i);
            --markA[i];
        }
    return match;
}
vector<ll> commonElementsOfTwoArrays (vector<ll> a, vector<ll> b) {
    vector<ll> match;
    int ia = 0, ib = 0;
    while (ia < a.size() && ib < b.size()) {
        if (a[ia] == b[ib]) {
            match.push_back(a[ia]);
            ++ia, ++ib;
        }
        else if (a[ia] < b[ib])
            ++ia;
        else    ++ib;
    }
    return match;
}
void test () {
    vector<ll> a, b, c;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    a.assign(n1, 0), b.assign(n2, 0), c.assign(n3, 0);
    for (auto &i:a) cin >> i;
    for (auto &i:b) cin >> i;
    for (auto &i:c) cin >> i;
    vector<ll> ans = commonElementsOfTwoArrays(commonElementsOfTwoArrays(a, b), commonElementsOfTwoArrays(b, c));
    if (ans.empty()) {
        cout << "-1\n";
        return;
    }
    for (auto i:ans)    cout << i << " ";
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
    test();
    return 0;
}