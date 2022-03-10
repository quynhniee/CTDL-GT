#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
int k;
void test () {
    unordered_map<char, int> mark;
    cin >> k >> s;
    for (auto i:s)  mark[i]++;
    priority_queue<int> q;
    for (auto i:mark) {
        q.push(i.second);
    }
    int temp;
    while (k--) {
        temp = q.top() - 1;
        q.pop();
        q.push(temp);
    }
    temp = 0;
    while (!q.empty()) {
        temp += q.top() * q.top();
        q.pop();
    }
    cout << temp << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}