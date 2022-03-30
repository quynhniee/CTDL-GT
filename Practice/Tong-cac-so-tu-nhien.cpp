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
int n;
vector<vector<int> > res;
vector<int> temp;
void backtracking (int i) {
    FORD (j, i, 1) {
        temp.push_back(j);
        n -= j;
        if (n == 0)
            res.push_back(temp);
        else if (n > 0)    backtracking(j);
        temp.pop_back();
        n += j;
    }
}
void output () {
    cout << res.size() << endl;
    for (auto i:res) {
        cout << "(";
        if (i.size() > 1)
            FOR (j, 0, i.size()-2)  cout << i[j] << " ";
        cout << i.back() << ")";
    }
    cout << endl;
}
void test () {
    cin >> n;
    res.clear(); temp.clear();
    backtracking(n);
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}