#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int t;
char path[200001];
int main() {
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> (path+1);
        path[0] = 'R';
        int len = strlen(path);
        int temp = 0;
        int mx = 0;
        for(int j = 1; j < len; j++)
        {
            if(path[j] == 'R')
            {
                mx = max(mx, j - temp);
                temp = j;
            }

            if(j == len-1)
            {
                mx = max(mx, len - temp);
            }
        }
        cout << mx << endl;
    }
    return 0;
}