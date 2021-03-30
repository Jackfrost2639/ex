#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;


int n, m, k;
int arr[100001];
int ocnt[100001];
int l[100001];
int r[100001];
ll s[100001];
ll e[100001];
int op[100001];
int qs[100001];
int qe[100001];

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> op[i];
    }
    for(int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        qs[a]++;
        qe[b]++;
    }

    int t = 0;
    for(int i = 1; i <= m; i++)
    {
        t += qs[i];
        ocnt[i] = t;
        t -= qe[i];
    }
    
    for(int i = 1; i <= m; i++)
    {
        s[l[i]] += (ll)op[i] * ocnt[i];
        e[r[i]] += (ll)op[i] * ocnt[i];
    }

    ll add = 0;
    for(int i = 1; i <= n; i++)
    {
        add += s[i];
        cout << arr[i] + add << ' ';
        add -= e[i];
    }

    cout << endl;
    return 0;
}