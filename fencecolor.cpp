#include <bits/stdc++.h>

using namespace std;

int n;
int digit[10];
int dn = 0;
int mxd = 1;
vector <int> outp;

int main()
{
    cin >> n;
    for(int i = 1; i < 10; i++)
    {
        cin >> digit[i];
    }

    for(int i = 1; i <= 9; i++)
    {
        if(digit[mxd] >= digit[i]) mxd = i;
    }
    dn = n/digit[mxd];
    n -= dn * digit[mxd];

    int s = 9;
    while(s > mxd)
    {
        if(digit[s]-digit[mxd] <= n)
        {
            outp.push_back(s);
            n -= digit[s] - digit[mxd];
            dn--;
        }
        else
        {
            s--;
        }
    }

    if(dn == 0 && outp.empty())
    {
        cout << -1 << endl;
        return 0;
    }
    for(auto e: outp) cout << e;
    for(int i = 0; i < dn; i++) cout << mxd;
    cout << endl;
}