#include <bits/stdc++.h>

using namespace std;

char x[101];
char y[101];

int main()
{
    cin >> x >> y;
    for(int i = 0; i < strlen(x); i++)
    {
        if(x[i] == y[i]) cout << 0;
        else cout << 1;
    }
}