#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<ll> luckyNum;
void LNVector () {
    queue<string> st;
    st.push("4"), st.push("7");
    luckyNum.push_back(4), luckyNum.push_back(7);
    string s = st.front();
    ll num = stoll(s);
    while (s.size() <= 9) {
        luckyNum.push_back(num * 10 + 4), luckyNum.push_back(num * 10 + 7);
        st.push(s + "4"), st.push(s + "7");
        st.pop();
        s = st.front();
        num = stoll(s);
    }
}
void solution () {
    ll a, b, k = 0, res = 0;
    cin >> a >> b;
    FOR (i, a, b) {
        while (i > luckyNum[k])   ++k;
        if (i <= luckyNum[k])
            res += luckyNum[k];
    }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    LNVector();
    solution();
    return 0;
}