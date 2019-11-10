#include <bits/stdc++.h>

using namespace std;

int n;
long long coord[100000][4];


int main()
{
    ifstream in("cowjump.in");
    ofstream out("cowjump.out");

    in >> n;

    for(int i = 0; i < n; i++)
    {
        in >> coord[i][0] >> coord[i][1] >> coord[i][2] >> coord[i][3]; 
    }

    int i;
    int j;

    bool flag = false;
    long long result1;
    long long result2;
    long long X1, Y1;
    long long result3;
    long long result4;
    for(i = 0; i < n; i++)
    {
        long long t1 = min(coord[i][0], coord[i][2]);
        long long t2 = max(coord[i][0], coord[i][2]);
        long long t3 = min(coord[i][1], coord[i][3]);
        long long t4 = max(coord[i][1], coord[i][3]);
                    long long X = coord[i][2] - coord[i][0];
            long long Y = coord[i][3] - coord[i][1];
            

        for(j = i+1; j < n; j++)
        {
            if(t1 > max(coord[j][0], coord[j][2]) || t2 < min(coord[j][0], coord[j][2]) 
            || t3 > max(coord[j][1], coord[j][3]) || t4 < min(coord[j][1], coord[j][3]))
            {
                continue;
            }

            int r1 = 1, r2 = 1, r3 = 1, r4 = 1;

            result1 = X * (coord[j][1] - coord[i][1]) - Y * (coord[j][0] - coord[i][0]);
            result2 = X * (coord[j][3] - coord[i][1]) - Y * (coord[j][2] - coord[i][0]);

            if(result1 < 0)
            {
                r1 = -1;
            }
            if(result2 < 0)
            {
                r2 = -1;
            }

             X1 = coord[j][2] - coord[j][0];
             Y1 = coord[j][3] - coord[j][1];

            result3 = X1 * (coord[i][3] - coord[j][1]) - Y1 * (coord[i][2] - coord[j][0]);
            result4 = X1 * (coord[i][1] - coord[j][1]) - Y1 * (coord[i][0] - coord[j][0]);

            if(result3 < 0)
            {
                r3 = -1;
            }
            if(result4 < 0)
            {
                r4 = -1;
            }

            if((result1 == 0 || result2 == 0 ||  result3 == 0 || result4 == 0) ||  ( (r1 * r2 < 0) && (r3 * r4 < 0) ) )
            {
                flag = true;
                break;   
            }
        }
        if(flag){
            break;
        }
    }

    int tempi = i;
    i = j;

    long long t1 = min(coord[i][0], coord[i][2]);
    long long t2 = max(coord[i][0], coord[i][2]); 
    long long t3 = min(coord[i][1], coord[i][3]);
    long long t4 = max(coord[i][1], coord[i][3]);
    for(int k = tempi +1 ; k<n; k++)
    {   
            if(t1 > max(coord[k][0], coord[k][2]) || t2 < min(coord[k][0], coord[k][2]) 
            || t3 > max(coord[k][1], coord[k][3]) || t4 < min(coord[k][1], coord[k][3])||k == i)
            {
                continue;
            }
            
                        int r1 = 1, r2 = 1, r3 = 1, r4 = 1;

            long long X = coord[i][2] - coord[i][0];
            long long Y = coord[i][3] - coord[i][1];

            long long result1 = X * (coord[k][1] - coord[i][1]) - Y * (coord[k][0] - coord[i][0]);
            long long result2 = X * (coord[k][3] - coord[i][1]) - Y * (coord[k][2] - coord[i][0]);

            if(result1 < 0)
            {
                r1 = -1;
            }
            if(result2 < 0)
            {
                r2 = -1;
            }

            X = coord[k][2] - coord[k][0];
            Y = coord[k][3] - coord[k][1];

            long long result3 = X * (coord[i][3] - coord[k][1]) - Y * (coord[i][2] - coord[k][0]);
            long long result4 = X * (coord[i][1] - coord[k][1]) - Y * (coord[i][0] - coord[k][0]);

            if(result3 < 0)
            {
                r3 = -1;
            }
            if(result4 < 0)
            {
                r4 = -1;
            }

            if(((result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0)) ||  ( (r1 * r2 < 0) && (r3 * r4 < 0) ) )
            {   
                out << i+1;
                return 0;
            }
    }
    
    out << tempi+1;
}