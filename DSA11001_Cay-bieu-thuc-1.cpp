#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;
typedef double db;
void solution () {
    string s;
    cin >> s;
    stack<string> st;
    for (auto i:s) {
        if (i == '+' or i == '-' or i == '*' or i == '/') {
            string r = st.top(); st.pop();
            string l = st.top(); st.pop();
            st.push(l + i + r);
        }
        else    st.push(string(1, i));
    }
    cout << st.top() << endl;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}