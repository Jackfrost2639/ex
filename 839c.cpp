#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n;
vector <int> graph[100001];
bool visited[100001];
double ans = 0;

void dfs(int a, int b, double p)
{
    visited[a] = true;
    int cnt = 0;
    for(auto e: graph[a])
    {
        if(visited[e]) cnt++;
    }
    for(auto e: graph[a])
    {
        if(!visited[e])
        {
            //cout << "dfs " << e << ' ' << b+1 << ' ' << p/graph[a].size() << endl;
            dfs(e, b+1, (double)p/(graph[a].size()-cnt));
        }
    }

    if(cnt == graph[a].size())
    {
        //cout << "add " << b*p << endl;
        ans += b*p;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, 1);

    cout << setprecision(9);
    cout << ans << endl;
    return 0;
}