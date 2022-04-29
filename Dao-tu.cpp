#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <sstream>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
void solution () {
    scanf ("\n");
    string s, token;
    getline (cin, s);
    vector<string> a;
    stringstream ss(s);
    while (ss >> token) {
        reverse(token.begin(), token.end());
        a.push_back(token);
    }
    for (auto i:a)
        cout << i << " ";
    cout << endl;
}
int main () {
    
    tester()    solution();
    return 0;
}