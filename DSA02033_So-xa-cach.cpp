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
vector<int> a;
int n;
bool check () {
    FOR (i, 2, n) 
        if (abs(a[i] - a[i-1]) == 1)
            return false;
    return true;
}
void output () {
    FOR (i, 1, n)   cout << a[i];
    cout << endl;
}
void test () {
    cin >> n;
    a.assign(n+1, 0);
    FOR (i, 1, n)   a[i] = i;
    do 
        if (check())    output();
    while (next_permutation(a.begin()+1, a.end()));
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