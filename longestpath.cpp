#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> tree[100001];
vector <int> emp[100001];
int dp[100001];
int gmx = 0;

int dfs(int ind)
{
    int mx = 0;
    if(dp[ind] != 0) return dp[ind];
    
    for(auto e : tree[ind])
    {
        mx = max(mx, dfs(e));
    }
    dp[ind] = mx+1;
    return mx + 1;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        emp[b].push_back(a);
    }

    queue <int> q;
    for(int i = 1; i <= n; i++)
    {
        if(emp[i].empty()) q.push(i);
    }

    while(!q.empty())
    {
        gmx = max(gmx, dfs(q.front()));
        q.pop();
    }

    cout << gmx - 1 << endl;
}