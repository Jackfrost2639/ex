#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
char word[50];

int main() {
    cin >> n;
    cin >> word;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(word[i] == word[i+1])
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}