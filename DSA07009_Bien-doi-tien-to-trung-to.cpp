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
string s;
void test () {
    cin >> s;
    stack<string> st;
    FORD (i, s.size()-1, 0) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '%') {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string temp = "(" + fi + s[i] + se + ")";
            st.push(temp);
        }
        else   st.push(string(1, s[i]));
    }
    cout << st.top() << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}