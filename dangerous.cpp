#include <bits/stdc++.h>

using namespace std;

char seq[200];

int main()
{
    cin >> seq;

    if(strlen(seq) < 7)
    {
        cout << "NO" << endl;
        return 0;
    }
    
    for(int i = 0; i < strlen(seq) - 6; i++)
    {
        int t = seq[i];
        if(t == seq[i+1] && t == seq[i+2] && t == seq[i+3] && t == seq[i+4] && t == seq[i+5] && t == seq[i+6])
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}