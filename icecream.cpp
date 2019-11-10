#include <bits/stdc++.h>

using namespace std;

bool blob[1002][1002];
bool visited[1002][1002];
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
int n;

typedef pair<int, int> pa;

pa dfs(int x, int y)
{
    if(!blob[x][y] || visited[x][y])
    {
        return pa(0, 0);
    }

    visited[x][y] = true;
    int a = 1;
    int p = 4;

    for(int i = 0; i < 4; i++)
    {
        if(blob[x+xdir[i]][y+ydir[i]])
        {
            p--;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if(!visited[x+xdir[i]][y+ydir[i]])
        {
            pa t = dfs(x+xdir[i], y+ydir[i]);
            a += t.first;
            p += t.second;
        }
    }

    return pa(a, p);
}


int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char temp;
            cin >> temp;
            if(temp == '.')
            {
                continue;
            }
            blob[i][j] = true;
        }
    }

    int mxa = 0;
    int mnp = 999999;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(visited[i][j])
            {
                continue;
            }
            pa temp = dfs(i, j);

            if(mxa == temp.first)
            {
                mnp = min(mnp, temp.second);
            }
            else if(temp.first > mxa)
            {
                mxa = temp.first;
                mnp = temp.second;
            }
            
        }
    }

    cout << mxa << ' ' << mnp << endl;
}