#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n, m;
ll stair[100001];
ll ans[100001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> stair[i];
    
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int w, h;
        cin >> w >> h;

        if(stair[1] >= stair[w])
        {
            ans[i] = stair[1];
            stair[1] += h;
        }
        if(stair[w] > stair[1])
        {
            ans[i] = stair[w];
            stair[w] += h;
            stair[1] = stair[w];
        }
    }

    for(int i = 0; i < m; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}