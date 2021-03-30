#include <bits/stdc++.h>

using namespace std;

int n, k;
int str[500001];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        char t;
        cin >> t;
        str[i] = t - 'A';
    }

    if(k == 2)
    {
        int acnt = 0;
        int bcnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(i%2 == 0)
            {
                if(str[i] == 0) bcnt++;
                if(str[i] == 1) acnt++;
            }
            if(i%2 == 1)
            {
                if(str[i] == 0) acnt++;
                if(str[i] == 1) bcnt++;
            }
        }
        if(acnt <= bcnt)
        {
            cout << acnt << endl;
            for(int i = 0; i < n; i++)
            {
                if(i%2 == 0) cout << 'A';
                else cout << 'B';
            }
        }
        else
        {
            cout << bcnt << endl;
            for(int i = 0; i < n; i++)
            {
                if(i%2 == 0) cout << 'B';
                else cout << 'A';
            }
        }
        
        return 0;
    }

    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(str[i] == str[i-1])
        {
            cnt++;
            for(int j = 0; j < 26; j++)
            {
                if(str[i] != j && str[i-1] != j && str[i+1] != j)
                {
                    str[i] = j;
                    break;
                }
            }
        }
    }

    cout << cnt << endl;
    for(int i = 0; i < n; i++)
    {
        cout << (char) ('A' + str[i]);
    }
    cout << endl;
}