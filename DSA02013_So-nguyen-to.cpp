#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> prime, res;
vector<vector<int> > answer;
int n, p, s, sum;
bool check (int x) {
    if (x == 2) return true;
    else if (x % 2 == 0)    return false;
    for (int i = 3; i <= sqrt(x); i += 2)
        if (x % i == 0)  return false;
    return true;
}
void PrimeArray () {
    FOR (i, 2, 200) 
        if (check(i))   prime.push_back(i);
}
void output () {
    for (auto i:answer) {
        for (auto j:i)  cout << j << " ";
        cout << endl;
    }
    answer.clear();
}
void backtracking (int l, int r) {
    if (l <= r)
    FOR (j, l+1, r) {
        sum += prime[j];
        res.push_back(prime[j]);
        if (res.size() == n && sum == s)  
            answer.push_back(res);
        else if (res.size() < n && sum < s)
            backtracking(j, r);
        sum -= prime[j];
        res.pop_back();
    }
}
void test () {
    cin >> n >> p >> s;
    sum = 0;
    int l = 0;
    while (prime[l] < p)  
        ++l;
    int r = l+1;
    while (prime[r] < s && r < prime.size() - 1)
        ++r;
    backtracking(l, r);
    cout << answer.size() << endl;
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    PrimeArray();
    tester() 
        test();
    return 0;
}