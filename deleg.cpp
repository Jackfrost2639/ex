#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> tree[100001];
int branch[100001];
bool ans[100001] = {true,};

int dfs(int ind, int par)
{

    int cnt = 1;
    for(auto e: tree[ind])
    {
        if(e != par)
        {
            cnt += dfs(e, ind);
        }
    }

    if(par == 1)
    {
        branch[cnt]++;
        return 0;
    }
    else return cnt;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 1);

    for(int i = 1; i <= n; i++)
    {
        if((n-1)%i != 0)
        {
            ans[i] = false;
            continue;
        }

        for(int j = 1; j <= n/2; j++)
        {
            if(i-j >= 0 && j != i-j && branch[j] != branch[i-j])
            {
                ans[i] = false;
                break;
            }
            else if(i-j >= 0 && j == i-j && branch[j]%2 == 0)
            {
                ans[i] = true;
                break;
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        cout << branch[i] << ' ';
    }

    cout << endl;
    // for(int i = 1; i <= n-1; i++)
    // {
    //     cout << ans[i];
    // }
    // cout << endl;
}