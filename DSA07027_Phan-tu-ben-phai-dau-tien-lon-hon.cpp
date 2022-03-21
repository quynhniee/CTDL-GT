#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector<ll> a;

void test () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    if (n <= 1) {
        cout << "-1\n";
        return;
    }
    stack<ll> st;
    vector<ll> res = {-1};
    st.push(a[n-1]);
    FORD (i, n-2, 0) {
        while (!st.empty() && a[i] >= st.top()) {
            st.pop();
        }
        st.empty() ? res.push_back(-1) : res.push_back(st.top());
        st.push(a[i]);
    }
    FORD (i, res.size()-1, 0)   cout << res[i] << " ";
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}
/*
5 
5 3 1 5 7
7 5 5 7 -1
*/