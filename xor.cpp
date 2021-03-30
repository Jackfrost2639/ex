#include <bits/stdc++.h>

using namespace std;

long long l, r;

int main()
{   
    cin >> l >> r;
    int cnt = 0;
    for(int i = 62; i >= 0; i--)
    {
        long long lt = l >> i;
        long long rt = r >> i;

        if(lt != rt) break;
        
        cnt++;
    }

    long long ans = (1LL << 63-cnt) - 1;
    cout << ans << endl;
}