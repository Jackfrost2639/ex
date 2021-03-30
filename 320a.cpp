#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

string a;

int main() {
    cin >> a;
    for(int i = 0; i < a.length(); i++)
    {
        int cnt = 0;
        if(a[i] == '1')
        {
            while(a[i+1] == '4')
            {
                cnt++;
                i++;
            }

            if(cnt > 2)
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                cnt = 0;
            }
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}