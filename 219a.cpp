#include <bits/stdc++.h>

using namespace std;

int n;
char str[1001];
int let[26];
vector <char> outp;

int main()
{
    cin >> n;
    cin >> str;
    int len = strlen(str);
    
    for(int i = 0; i < len; i++)
    {
        let[str[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(let[i]%n != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        char temp = 'a' + i;
        if(let[i] != 0)
        {
            for(int j = 0; j < let[i]/n; j++)
            {
                outp.push_back(temp);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < outp.size(); j++)
        {
            cout << outp[j];
        }
    }
    cout << endl;
}