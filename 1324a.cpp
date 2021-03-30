#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int t, n;
int field[101];
bool flag = false;

int main() {
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 0; j < n; j++) cin >> field[j];

        sort(field, field+n);
        int mn = field[0];
        for(int j = 0; j < n; j++)
        {
            if((field[j]-mn)%2 != 0)
            {
                cout << "NO" << endl;
                break;
            }
            if(j == n-1) cout << ' ' << "YES" << endl;
        }
    }
    return 0;
}