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
int n, x;
vector<vector<int> > list;
void input () {
    cin >> n;
    list.resize(n+1);
    FOR (i, 1, n)
        FOR (j, 1, n) {
            cin >> x;
            if (x) 
                list[i].push_back(j);
        }
}
void output () {
    FOR (i, 1, n) {
        for (auto j:list[i])    
            cout << j << " ";
        cout << endl;
    }
}
void test () {
    input();
    output();
    list.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}