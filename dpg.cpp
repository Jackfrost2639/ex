#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, m;
vector <int> graph[100001];
int degree[100001];
int dep[100001];
vector <int> emp;

void dfs(int a)
{   
    for(int t : graph[a]) {
        degree[t]--;
        dep[t] = max(dep[t], dep[a]+1);
    
        if(degree[t] == 0)
        {
            dfs(t);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[y].push_back(x);
        degree[x]++;  
    }
    for(int i = 1; i <= n; i++)
    {
        if(degree[i] == 0)
        {
            emp.push_back(i);
        }
    }

    for(int e : emp)
    {
        dfs(e);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dep[i]);
    }

    cout << ans << endl;
    return 0;
}