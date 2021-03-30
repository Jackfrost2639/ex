#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

typedef pair<int, int> pa;

int n;
pa drift[101];
int g[101];

int find(int a)
{
    if(g[a] != a)
    {
        g[a] = find(g[a]);
    }
    return g[a];
}

int uni(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a > b) swap(a, b);
    if (a == b) return 0;
    g[b] = a;
    return 1;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        drift[i] = pa(x, y);
        g[i] = i;
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(drift[i].first == drift[j].first || drift[i].second == drift[j].second){
                cnt += uni(i, j);
            }
        }
    }

    cout << n-cnt-1 << endl;
    return 0;
}