#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int max_val = 0;
    cin >> n;



    for(int i = 0; i < n; i++)
    {
        int val = 0;
        int dup = 0;
        int dup_num;
        int dice[3];

        for(int j = 0; j < 3; j++)
        {
            cin >> dice[j];
        }
        
        for(int j = 0; j < 3; j++)
        {
            int temp = 0;
            for(int h = 0; h < 3; h++)
            {
                if(dice[j] == dice[h])
                {
                    temp++;
                }
            }

            if(dup < temp)
            {
                dup = temp;
                dup_num = dice[j];
            }
        }

        if(dup == 3)
        {
            val = 10000 + (1000*dup_num);
        }
        else if(dup == 2)
        {
            val = 1000 + (100*dup_num);
        }
        else
        {
            int mx = 0;
            for(int j = 0; j <3; j++)
            {
                mx = max(mx, dice[j]);
            }
            val = 100 *mx;
        }

        max_val = max(max_val, val);
    }

    cout << max_val << endl;
}