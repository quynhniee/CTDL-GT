#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector<int> a;
void solution () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    stack<int> st;
    vector<int> res(n, 1);
    st.push(0);
    FOR (i, 1, n-1) {
        while (!st.empty() && a[i] >= a[st.top()]) {
            res[i] += res[st.top()];
            st.pop();
        }
        st.push(i);
    }
    for (auto i:res)    cout << i << " ";
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}