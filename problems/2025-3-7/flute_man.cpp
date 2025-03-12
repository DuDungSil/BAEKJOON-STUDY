// 16724 피리 부는 사나이
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// dfs & 경로 사이클 찾기

int N, M;
int _count = 0;
bool visited[1001][1001] = {false, };
bool finished[1001][1001] = {false, };
vector<vector<char>> world;

void dfs(pair<int, int> now)
{
    int now_x = now.first;
    int now_y = now.second;

    visited[now_x][now_y] = true;

    pair<int, int> next;
    switch (world[now_x][now_y])
    {
        case 'D':
            next = {now_x + 1, now_y};
            break;
        case 'U':
            next = {now_x - 1, now_y};
            break;
        case 'R':
            next = {now_x, now_y + 1};
            break;
        case 'L':
            next = {now_x, now_y - 1};
            break;
    }

    // 다음 가려는 경로가 이미 완료된 경로 
    if(!finished[next.first][next.second])
    {
        if(!visited[next.first][next.second])
        {
            dfs(next);
        }
        else
        {
            _count++;
        }
    }
    
    finished[now_x][now_y] = true;
}

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> N >> M;

    world = vector<vector<char>>(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            world[i][j] = c;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(!visited[i][j])  dfs({i, j});
        }
    }

    cout << _count;



    return 0;
}