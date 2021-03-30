#include <bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;
bool board[100][100];
bool row[100];
bool dia[100];
bool diag[100];

void rec(int ind)
{
    if(ind == n)
    {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!row[i] && !dia[ind-i + n-1] && !diag[ind+i])
        {
            board[ind][i] = true;
            row[i] = true;
            dia[ind-i + n-1] = true;
            diag[ind+i] = true;
            rec(ind + 1);
            board[ind][i] = false;
            row[i] = false;
            dia[ind-i + n-1] = false;
            diag[ind+i] = false;
        }
    }
    //rec(ind + 1);
}

int main()
{
    cin >> n;
    rec(0);
    cout << cnt << endl;
}