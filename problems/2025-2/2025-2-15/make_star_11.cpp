// 2448 별 찍기 - 11
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 재귀, 분할정복
// n = 3, 6, 12, 24, 48
// k = 0, 1,  2 , 3 ,  4
// c - 5, 2*5 + 1, 4 * 5 + 3, 8 * 5 + 7

void make_star(vector<vector<bool>>& star, int depth, pair<int, int> start)
{

    if(depth == 0)
    {
        int y = start.first;
        int x = start.second;

        for(int i = 1; i <= 3; i++)
        {
            if(i == 1)
            {
                star[y][x + 2] = true;
            }
            else if(i == 2)
            {
                star[y + 1][x + 1] = true;
                star[y + 1][x + 3] = true;
            }
            else if(i == 3)
            {
                star[y + 2][x] = true;
                star[y + 2][x + 1] = true;
                star[y + 2][x + 2] = true;
                star[y + 2][x + 3] = true;
                star[y + 2][x + 4] = true;
            } 
        }

        return;
    }

    int base = pow(2, depth);
    int column = base * 5 + base - 1;
    int low = 3 * base;

    int y = start.first;
    int x = start.second;

    make_star(star, depth - 1, {y + low / 2, x});
    make_star(star, depth - 1, {y, x + column / 4 + 1});
    make_star(star, depth - 1, {y + low / 2, x + column / 2 + 1});
}

int main(void) 
{

    int n;
    cin >> n;

    int num = n / 3;
    int k = -1;
    int z = num;
    while(z > 0)
    {
        z = z / 2;
        k++;
    }

    int c = 5 * num + num - 1;

    vector<vector<bool>> star(n+1, vector<bool>(c+1, false));
    make_star(star, k, {1,1});

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout << (star[i][j] ? "*" : " ");
        }
        cout << "\n";
    }

    return 0;
}