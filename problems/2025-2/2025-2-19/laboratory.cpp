#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 벽 3개 세우기 가능
// 3개 위치 찾기

// 그리디?

int N, M;
int _count;
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};
vector<vector<int>> map;
vector<pair<int, int>> pollutions;

void pollution()
{
    // 깊은복사
    vector<vector<int>> temp(map);

    queue<pair<int, int>> q;

    for (int i = 0; i < pollutions.size(); i++)
    {
        q.push(pollutions[i]);
    }

    while(!q.empty())
    {
        pair<int, int> info = q.front();
        q.pop();

        int x = info.second;
        int y = info.first;

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && temp[next_y][next_x] == 0)
            {
                temp[next_y][next_x] = 2;
                q.push({next_y, next_x});
            }
        }
    }

    int p_count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(temp[i][j] == 0)
                p_count++;
        }
    }

    _count = max(_count, p_count);
}

void wall(int depth, pair<int, int> prev)
{

    if(depth == 4)
    {
        // 오염시킨후 안전구역 개수 세기
        pollution();
        return;
    }

    int i_start = prev.first;
    int j_start = prev.second;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(i <= i_start && j <= j_start) continue;
            if(map[i][j] == 0)
            {
                map[i][j] = 1;
                wall(depth + 1, {i, j});
                map[i][j] = 0;
            }
        }
    }

}

int main(void) 
{

    cin >> N >> M;

    map = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    // 오염 위치 저장
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(map[i][j] == 2)
            {
                pollutions.push_back({i, j});
            }
        }
    }

    // 완전 탐색
    wall(1, {-1, -1});

    cout << _count;

    return 0;
}