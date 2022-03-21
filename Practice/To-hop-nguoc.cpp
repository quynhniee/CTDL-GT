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
vector<int> a;
vector<vector<int> > C; 
void output () {
    FORD (i, C.size()-1, 0) {
        FOR (j, 1, C[i].size()-1)   cout << C[i][j] << " ";
        cout << endl;
    }
}
void combination (int i) {
    FOR (j, a[i-1]+1, n-k+i) {
        a[i] = j;
        if (i == k) 
            C.push_back(a);
        else    combination(i+1);
    }
}
void test () {
    cin >> n >> k;
    a.assign(k+1, 0);
    FOR (i, 1, k)   a[i] = i;
    combination(1);
    output();
    C.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}