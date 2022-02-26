#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <set>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<string> day = {"02", "20", "22"}, year;
set<string> ans;
vector<string> Sday;
void yearGenerate (int i, string s) {
    if (i == 3) year.push_back(s);
    else {
        yearGenerate(i+1, s + "0");
        yearGenerate(i+1, s + "2");
    }
}
void output () {
    for (auto i:ans)    cout << i << endl;
}
void specialDay () {
    for (auto d:day) {
        Sday.push_back(d);
        Sday.push_back("02");
        for (auto y:year) {
            Sday.push_back(y);
            ans.insert(Sday[0] + "/" + Sday[1] + "/" + Sday[2]);
            Sday.pop_back();
        }
        Sday.pop_back();
        Sday.pop_back();
    }
}
void test () {
    yearGenerate(0, "2");
    specialDay();
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}