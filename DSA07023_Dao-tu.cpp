#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#include <sstream>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
stack<string> a;
void word_separation () {
    scanf("\n");
    getline(cin, s);
    string temp;
    stringstream ss(s);
    while (ss >> temp) 
        a.push(temp);
    while (!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
}
int main () {
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    // cout.tie(NULL);
    tester()    word_separation();
    return 0;
}