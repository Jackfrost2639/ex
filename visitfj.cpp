#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pa;

int n, t;
int field[100][100];
int answer[100][100];
int xdir[16] = {0, 1, 0, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1};
int ydir[16] = {1, 0, -1, 0, 3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2};

int main()
{
    ifstream in("visitfj.in");
    ofstream out("visitfj.out");
    
    in >> n >> t;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            in >> field[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            answer[i][j] = 0x7fffffff;
        }
    }

    priority_queue<pa, vector<pa>, greater<pa>> b;
    answer[0][0] = 0;
    b.push(pa(0, 0));

    int cnt = 0;
    int mn = 0x7fffffff;

    while(!b.empty())
    {
        pa temp = b.top();
        int ans = temp.first;
        int r = temp.second/n;
        int c = temp.second%n;
        b.pop();

        if(ans != answer[r][c])
        {
            continue;
        }

        if((n-r-1)+(n-c-1) < 3)
        {
            cnt++;
            mn = min(mn, ans + t*((n-r-1)+(n-c-1)));
            if(cnt == 6)
            {
                break;
            }
        }

        for(int i = 0; i < 16; i++)
        {
            int nr = r + xdir[i];
            int nc = c + ydir[i];

            if(nr >= n || nr < 0 || nc >= n || nc < 0)
            {
                continue;
            }

            if(ans + field[nr][nc] + 3*t < answer[nr][nc])
            {
                answer[nr][nc] = ans + field[nr][nc] + 3*t;
                b.push(pa(answer[nr][nc], nr*n+nc));
            }
        }
    }

    out << mn << endl;
}