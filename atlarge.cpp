#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <int> tree[100001];
int depth[100001];
int ldis[100001];
int cnt = 0;

int dfs(int ind, int par)
{
    if(ind != k) depth[ind] = depth[par] + 1;
    int mn = 1000000;
    if(tree[ind].size() == 1){
        ldis[ind] = 0;
        return 0;
    }
    for(int i = 0; i < tree[ind].size(); i++)
    {
        if(tree[ind][i] != par)
        {
            mn = min(mn, dfs(tree[ind][i], ind) + 1);
        }
    }

    ldis[ind] = mn;
    return mn;
}

void dfs2(int ind, int par)
{
    if(par != k)
    {
        ldis[ind] = min(ldis[ind], ldis[par] + 1);
    }

    printf("%d %d %d\n", ind, depth[ind], ldis[ind]);
    
    for(int i = 0; i < tree[ind].size(); i++)
    {
        if(tree[ind][i] != par)
        {
            dfs2(tree[ind][i], ind);
        }
    }
}

void fdfs(int ind, int par)
{
    if(ind != k && depth[par] < ldis[par] && depth[ind] >= ldis[ind])
    {
        cnt++;
    }
    for(int i = 0; i < tree[ind].size(); i++)
    {
        int des = tree[ind][i];

        //printf("%d %d %d %d\n", ind, depth[ind], ldis[ind], par);

        if(des != par)
        {
            fdfs(des, ind);
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(k, k);
    dfs2(k, k);
    fdfs(k, k);

    cout << cnt << endl;
}