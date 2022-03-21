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
string s;
int priority (char x) {
    if (x == '(')   return 0;
    else if (x == '-' || x == '+')  return 1;
    else if (x == '*' || x == '/' || x == '%')  return 2;
    else if (x == '^')  return 3;
}
void test () {
    cin >> s;
    stack<char> st;
    for (auto i:s) {
        if (i == '(')  st.push(i);
        else if (i == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^' || i == '%') {
            while (!st.empty() && priority(i) <= priority(st.top())) {
                cout << st.top();
                st.pop();
            }
            st.push(i);
        }
        else    cout << i;
    }
    while (!st.empty()) {
        if (st.top() != '(')
            cout << st.top();
        st.pop();
    }
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}