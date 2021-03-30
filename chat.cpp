#include <bits/stdc++.h>

using namespace std;

string word;
char hel[5] = {'h','e','l','l','o'};

int main()
{
    cin >> word;
    int ind = 0;

    for(int i = 0; i < word.length(); i++)
    {
        if(word[i] == hel[ind]) ind++;

        if(ind == 5)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}