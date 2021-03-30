#include <bits/stdc++.h>

using namespace std;

int n;
int cmax = 0;
vector <int> stk[100000];

int main()
{
    cin >> n;
    int ans = n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if(cmax > temp)
        {
            ans = i;
            break;
        }

        int j;
        for(j = 0; j < n; j++)
        {
            if(stk[j].empty() || stk[j][0] > temp) break;
        }

        while(!stk[j].empty() && stk[j].back() < temp)
        {
            cmax = stk[j].back();
            stk[j].pop_back();
        }

        stk[j].push_back(temp);
    }

    cout << ans << endl;
}