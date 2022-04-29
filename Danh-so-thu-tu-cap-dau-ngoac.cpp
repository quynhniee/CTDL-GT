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
void solution () {
    scanf("\n");
    string s;
    getline(cin, s);
    int k = 1;
    stack<int> st;
    vector<int> res;
    for (char i:s) {
        if (i == '(') {
            res.push_back(k);
            st.push(k++);
        }
        else if (i == ')') {
            res.push_back(st.top());
            st.pop();
        }
    }
    for (auto i:res)    cout << i << " ";
    cout << endl;
}
int main () {
    tester()    solution();
    return 0;
}