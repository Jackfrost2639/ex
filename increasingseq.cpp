#include <bits/stdc++.h>

using namespace std;

int n;
int seq[1000];

int solve(int mx, int ind)
{
    int cnt = 0;
    int m = mx;
    if(seq[ind] >= mx)
    {
        cnt++;
        m = seq[ind];
    }
    else
    {
        return 0;
    }
    
    cnt += solve(m, ind++);
    return cnt;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }

    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        mx = max(mx, solve(seq[i], i));
    }

    cout << mx+1 << endl;
}