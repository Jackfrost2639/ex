#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int t;
int n;
int arr[5001];
int app[5001];
int main() {
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[j];
            app[j] = -1;
        }

        for(int j = 1; j <= n; j++)
        {
            if(app[arr[j]] == -1)
            {
                app[arr[j]] = j;
            }
            else
            {
                if(j - app[arr[j]] > 1)
                {
                    cout << "YES" << endl;
                    break;
                }    
            }
            if(j == n) cout << "NO" << endl;
        }
    }
    return 0;
}