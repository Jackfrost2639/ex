#include <bits/stdc++.h>

using namespace std;

int n, q;
int enj[100000];
vector <int> path[100000];
int anc[100000][20];
int XOR[100000][20];
int depth[100000];
bool visited[100000];

void dfs(int cur, int dpth)
{
    visited[cur] = true;
    depth[cur] = dpth;

    for(int i = 0; i < path[cur].size(); i++)
    {
        if(!visited[path[cur][i]])
        {
            anc[path[cur][i]][0] = cur;

            XOR[path[cur][i]][0] = enj[path[cur][i]]; 
            dfs(path[cur][i], dpth+1);
        }
    }
}

void fanc()
{
    for(int j = 1; j < 21; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

void calc()
{
    for(int j = 1; j < 21; j++)
    {
        for(int i = 1; i <=n; i++)
        {
            XOR[i][j] = XOR[i][j-1] ^ XOR[anc[i][j-1]][j-1];
        }
    }

    for(int i=0; i<1; i++)
    {
        for(int j=1;j<=n; j++) printf("%d %d %d\n", j, i, XOR[j][i]);
    }
}

int lca(int a, int b)
{
    if(depth[a] > depth[b]) swap(a, b);

    for(int i = 20; i >= 0; i--)
    {
        if(depth[b] - depth[a] >= (1 << i))
        {
            //printf("**%d %d\n", i, b);
            b = anc[b][i];
        }
    }
    
    if(a == b) return a;
    for(int i = 20; i >= 0; i--)
    {
        if(anc[a][i] != anc[b][i])
        {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
}

int cxor(int a, int b)
{
    int leastca = lca(a, b);
    //cout << 'c' <<leastca << endl;
    int axor = 0, bxor = 0;

    for(int i = 20; i >= 0; i--)
    {
        if(depth[a] - depth[leastca] >= (1 << i))
        {
            //printf("*%d %d\n", i, a);
            axor ^= XOR[a][i];
            a = anc[a][i];
        }
    }
    for(int i = 20; i >= 0; i--)
    {
        if(depth[b] - depth[leastca] >= (1 << i))
        {
            printf("***%d %d %d\n", i, b, XOR[b][i]);
            bxor ^= XOR[b][i];
            b = anc[b][i];
        }
    }

    cout << axor << ' '<<bxor<<endl;
    return axor^bxor^enj[leastca];
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> enj[i];
    }
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    
    dfs(1, 0);
    fanc();
    calc();

    for(int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1)
        {
            enj[b] = c;
            calc();
        }
        else
        {
            cout << cxor(b, c) << endl;
        }
    }
}