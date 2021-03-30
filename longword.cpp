#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    string temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        int len = temp.length();
        if(len <= 10)
        {
            cout << temp << endl;
        }
        else
        {
            cout << temp[0] << len - 2 << temp[len-1] << endl;
        }
    }
}