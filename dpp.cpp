#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pa;

const ll MAX = 1e9 + 7;
int n;
bool visited[100001];
vector <int> tree[100001];

pa dpfs(int d)
{
    visited[d] = true;

    ll wsum = 1;
    ll bsum = 1;
    for(auto e: tree[d])
    {
        if(!visited[e])
        {
            pa t = dpfs(e);
            ll w = t.first;
            ll b = t.second;

            wsum *= w + b;
            wsum %= MAX;
            bsum *= w;
            bsum %= MAX;
        }
    }

    return pa(wsum, bsum);
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    pa ans = dpfs(1);

    cout << (ans.first + ans.second)%MAX << endl;
    return 0;
}