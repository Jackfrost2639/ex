#include <bits/stdc++.h>

using namespace std;

string s, t;
int dp[3001][3001];
int his[3001][3001];
int xdir[4] = {0, -1, -1, 0};
int ydir[4] = {0, 0, -1, -1};
vector <char> ans;

int main()
{
    cin >> s >> t;

    int slen = s.length(), tlen = t.length();
    for(int i = 1; i <= slen; i++)
    {
        for(int j = 1; j <= tlen; j++)
        {
            if(s.at(i-1) == t.at(j-1))
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                his[i][j] = 2;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                his[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                his[i][j] = 3;
            }
        }
    }

    int xind = slen, yind = tlen, aind = 0;
    while(xind >= 1 && yind >= 1)
    {
        if(his[xind][yind] == 2)
        {
            ans.push_back(s.at(xind-1));
            xind--;
            yind--;
        }
        else if(his[xind][yind] == 1) xind--;
        else yind--;
    }

    for(int i = ans.size()-1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;

    for(int i = 0; i < slen; i++)
    {
        for(int j = 0; j < tlen; j++)
        {
            //cout << his[i][j] << ' ';
        }
        //cout << endl;
    }
}