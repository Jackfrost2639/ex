#include <bits/stdc++.h>

using namespace std;

int n, k;
int pic[10][100];
bool visited[10][100];

int dfs(int x, int y)
{
    if(visited[x][y])
    {
        return 0;
    }
}


int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> pic[i][j];
        }
    }


}