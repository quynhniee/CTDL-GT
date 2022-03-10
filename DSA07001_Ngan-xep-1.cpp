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
vector<int> a;
string s;
int n;
void output () {
    for (auto i:a)  cout << i << " ";
    cout << endl;
}
void input (string s) {
    if (s == "push") {
        cin >> n;
        a.push_back(n);
    }
    else if (s == "pop") a.pop_back();
    else {
        if (a.empty())  cout << "empty\n";
        else  output();
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> s) 
        input(s);
    return 0;
}