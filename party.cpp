#include <bits/stdc++.h>

using namespace std;

int n;
int depth;
vector <int> tree[2001];
vector <int> emp;
bool visited[2001];

int bfs(int a)
{
    int depth = 0;
    for(auto e : tree[a]) {
        depth = max(depth, bfs(e));
    }
    return depth + 1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;

        if(t > 0) tree[t].push_back(i);
        else emp.push_back(i);
    }

    int mx = -1;
    for(auto e : emp)
    {
        mx = max(mx, bfs(e));
    }

    cout << mx << endl;
}