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
int n;
string s;
vector<vector<int> > adjacency;

void pushElements (int row) {
    scanf ("\n");
    getline(cin , s);
    stringstream ss(s);
    string token;
    while (ss >> token) {
        int x = stoi(token);
        adjacency[row][x] = adjacency[x][row] = 1;
    }
}
void input () {
    cin >> n;
    adjacency.assign(n+1, vector<int> (n+1, 0));
    FOR (i, 1, n) 
        pushElements(i);
}
void output () {
    FOR (i, 1, n) {
        FOR (j, 1, n)  cout << adjacency[i][j] << " ";
        cout << endl;
    }
}
void test () {
    input();
    output();
}
int main () {
    test();
    return 0;
}