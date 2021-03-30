#include <bits/stdc++.h>

using namespace std;

int rep, h, v, c;
int f[50][50];
int visited[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool dfs(int cx,int cy)
{
    if(visited[cx][cy] == 1 || f[cx][cy] == 0)
    {
        return false;
    }

    visited[cx][cy] = 1;

    for(int i = 0; i < 4; i++)
    {
        if(visited[cx+dx[i]][cy+dy[i]] == 0 && f[cx+dx[i]][cy+dy[i]] == 1)
        {
            dfs(cx+dx[i], cy+dy[i]);
        }
    }
    return true;
}

int main()
{
    cin >> rep;
    for(int i = 0; i < rep; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            for(int k = 0; k < 50; k++)
            {
                visited[j][k] = 0;
                f[j][k] = 0;
            }
        }
        int cnt = 0;
        cin >> h >> v >> c;
        for(int j = 0; j < c; j++)
        {
            int x, y;
            cin >> x >> y;
            f[x][y] = 1;
        }

        for(int j = 0; j < h; j++)
        {
            for(int k = 0; k < v; k++)
            {
                if(dfs(j, k))
                {
                    cnt++;

                }
            }
        }
        cout << cnt << endl;
    }
}