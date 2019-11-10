#include <bits/stdc++.h>

using namespace std;

bool field[101][101];
bool road[101][101][4];
bool visited[101][101];

int n;
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};

int dfs(int x, int y)
{
    if(x>n || y>n || x<=0 || y<=0)
    {
        return 0;
    }

    visited[x][y] = true;

    int cnt = 0;
    if(field[x][y])
    {
        cnt++;
    }

    for(int i = 0; i < 4; i++)
    {
        if(!road[x][y][i] && !visited[x+xdir[i]][y+ydir[i]])
        {
            cnt += dfs(x+xdir[i], y+ydir[i]);
        }
    }

    return cnt;
}

int main()
{
    int k, r;
    cin >> n >> k >> r;

    for(int i = 0; i < r; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a<c)
        {
            road[a][b][0] = true;
            road[c][d][2] = true;
        }
        if(a>c)
        {
            road[a][b][2] = true;
            road[c][d][0] = true;
        }
        if(b<d)
        {
            road[a][b][1] = true;
            road[c][d][3] = true;
        }
        if(b>d)
        {
            road[a][b][3] = true;
            road[c][d][1] = true;
        }
    }

    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        field[a][b] = true;
    }

    vector<int> group;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                int temp = dfs(i, j);
                if(temp != 0)
                {
                    group.push_back(temp);
                }
            }
        }
    }

    int cnt = 0;
    int len = group.size();

    for(int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            cnt += group[i] * group[j];
        }
    }

    cout << cnt << endl;
}