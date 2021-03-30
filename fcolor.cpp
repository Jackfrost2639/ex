#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> cow[200001];
int ans[200001];

int dfs()
{

}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cow[b].push_back(a);
    }


}