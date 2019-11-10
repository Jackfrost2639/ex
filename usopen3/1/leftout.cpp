#include <bits/stdc++.h>

using namespace std;

bool dir[1000][1000];
int n;

bool check()
{//true : [0] change
        vector<int> diff;
        bool flag = false;
        for(int index = 0; index< n; index++)
        {
            if(!dir[0][index] == dir[2][index])
            {
                diff.push_back(index);
            }
            if(diff.size() >= 1)
            {
                flag = true;
            }
        }

        if(flag)
        {
            diff.clear();
            for(int index =0; index <n; index++)
            {
                if(dir[0][index] == dir[2][index])
                {
                    diff.push_back(index);
                }
                if(diff.size() >= 1)
                {
                    return true;
                }
            }
        }
        return false;

}

int main()
{
    ifstream in("leftout.in");
    ofstream out("leftout.out");

    in >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char temp;
            in >> temp;
            dir[i][j] = (temp == 'R') ? true : false;
        }
    }
    if( n == 2)
    {
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                dir[i][j] = !dir[i][j];
                
                if(( dir[0][0] == dir[1][0] && dir[0][1] == dir[1][1]) || ( dir[0][0] != dir[1][0] && dir[0][1] != dir[1][1]))
                {
                     out << i+1 << ' ' << j+1;
                        return 0;
                }   
                dir[i][j] = !dir[i][j];                
            }
        }
    }

// now : dir[0];
    int ansx = -1, ansy;
            vector<int> diff;
    for(int i = 1; i < n; i++)
    {
        diff.clear();
        bool flag = false;
        for(int index = 0; index< n; index++)
        {
            if(dir[i][index] != dir[0][index])
            {
                diff.push_back(index);
            }
            if(diff.size() >= 2)
            {
                flag = true;
                break;
            }
        }

        if(flag)
        {
            diff.clear();
            for(int index =0; index <n; index++)
            {
                if(dir[i][index] == dir[0][index])
                {
                    diff.push_back(index);
                }
                if(diff.size() >= 2)
                {


                    out << -1;
                    return 0;
                }
            }
        }

        if(i == 1 && diff.size() == 1) 
        {

            if( n>2 && check())
            {// check : first line is wrong
                ansx = 0; ansy = diff[0];
                dir[0][ansy] = ! dir[0][ansy];
            }

            else if(n>2 && !check())
            {
                ansx = 1; ansy = diff[0];
            }

            else{
                ansx = 0; ansy = diff[0];
                dir[0][ansy] = ! dir[0][ansy];   
            }

        }

        if(i >= 2 && diff.size() == 1)
        {
            if(ansx != -1)
            {
                out << -1;
                return 0;
            }
            else
            {
                ansx = i; ansy = diff[0];
 //               dir[0][ansy] = !  dir[0][ansy];
            }
            
        }
    }

    out << ansx+1 << ' ' << ansy + 1;
}