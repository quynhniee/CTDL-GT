#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
deque<int> a;
string s;
int n;
void request () {
    cin >> s;
    if (s == "PUSHFRONT") {
        cin >> n;
        a.push_front(n);
    }
    else if (s == "PRINTFRONT")
        !a.empty() ? cout << a.front() << endl : cout << "NONE\n";
    else if (s == "POPFRONT" && !a.empty())
        a.pop_front();
    else if (s == "PUSHBACK") {
        cin >> n;
        a.push_back(n);
    }
    else if (s == "PRINTBACK") 
        !a.empty() ? cout << a.back() << endl : cout << "NONE\n";
    else if (s == "POPBACK" && !a.empty())
        a.pop_back();

}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    request();
    return 0;
}