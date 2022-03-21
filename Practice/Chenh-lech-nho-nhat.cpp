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
int n, k;
vector<int> p;
vector<string> num;
void init () {
    cin >> n >> k;
    p.assign(k, 0);
    num.assign(n, "");
    FOR (i, 0, n-1) cin >> num[i];
    FOR (i, 0, k-1) p[i] = i;
}

// tính các số tương ứng với hoán vị p
ll calculate (string s) {
    ll temp = 0;
    FOR (i, 0, k-1)
        temp = temp *10 + (s[p[i]] - '0');
    return temp;
}

// tìm hiệu giữa số lớn nhất & nhỏ nhất tạo được ứng với mỗi hoán vị p
ll sub () {
    ll Max = 0, Min = 1e9;
    FOR (i, 0, n-1) {
        ll temp = calculate(num[i]);
        Min = min (Min, temp);
        Max = max (Max, temp);
    } 
    return Max - Min;
}
void test () {
    ll res = 1e9;
    init();
    do {
        res = min(res, sub());
    }
    while (next_permutation(p.begin(), p.end()));
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}