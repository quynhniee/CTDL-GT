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
vector<ll> a;
ll cou;
void input () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    cou = 0;
}
void merge (int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    vector<ll> a1(n1), a2(n2);
    FOR (i, 0, n1-1)
        a1[i] = a[l+i];
    FOR (i, 0, n2-1)
        a2[i] = a[m+i+1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) {
            a[k++] = a1[i++];
        }
        else {
            a[k++] = a2[j++];
            cou += n1 - i;
        }
    }
    while (i < n1)
        a[k++] = a1[i++];
    while (j < n2)
        a[k++] = a2[j++];
}
void mergeSort (int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}
void output () {
    for (auto i:a)  cout << i << " ";
    cout << endl;
}
void test () {
    input();
    mergeSort(0, n-1);
    cout << cou << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}