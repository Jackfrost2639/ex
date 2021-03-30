#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
char str[100][100];
int ord[26];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    for(int i = 0; i < 26; i++)
    {
        ord[i] = i;
    }

    
    return 0;
}