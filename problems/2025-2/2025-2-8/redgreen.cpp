#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 색약 or 일반인 구분

char normal[101][101];
char blindness[101][101];
int normal_gruop[101][101] = {0,};
int normal_id = 0;
int blindness_gruop[101][101] = {0,};
int blindness_id = 0;

int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

void normal_dfs(int N, int x, int y, char color, int group_id)
{
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_y < 0 || new_x > N || new_y > N)
            continue;
        if(normal_gruop[new_x][new_y] == 0)
        {
            if(normal[new_x][new_y] == color)
            {
                normal_gruop[new_x][new_y] = group_id;
                normal_dfs(N, new_x, new_y, color, group_id);
            }
        }
    }
}

void blindness_dfs(int N, int x, int y, char color, int group_id)
{
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_y < 0 || new_x > N || new_y > N)
            continue;
        if(blindness_gruop[new_x][new_y] == 0)
        {
            if(blindness[new_x][new_y] == color)
            {
                blindness_gruop[new_x][new_y] = group_id;
                blindness_dfs(N, new_x, new_y, color, group_id);
            }
        }
    }
}

int main(void) 
{

    int N;
    cin >> N;

    // 입력
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            normal[i][j] = c;
            if( c == 'G')
                c = 'R';
            blindness[i][j] = c;
        }
    }

    // dfs
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(normal_gruop[i][j] == 0)
            {
                char color = normal[i][j];
                normal_gruop[i][j] = ++normal_id;
                normal_dfs(N, i, j, color, normal_id);
            }
            if(blindness_gruop[i][j] == 0)
            {
                char color = blindness[i][j];
                blindness_gruop[i][j] = ++blindness_id;
                blindness_dfs(N, i, j,color, blindness_id);
            }
        }
    }

    cout << normal_id << " " << blindness_id;

    return 0;
}