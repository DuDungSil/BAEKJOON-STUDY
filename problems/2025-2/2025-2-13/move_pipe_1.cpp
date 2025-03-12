// 17070 파이프 옮기기 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 3방향 : 오른쪽, 오른쪽아래, 아래 

// 파이프의 한쪽 끝을 (N, N) 으로 이동시키는 방법의 수
// 이동 불가시 0

// 브루트 포스?

int N;
int _count = 0;

void dfs(vector<vector<int>>& map, pair<int, int> now, int prev_type)
{

    if(now.first == N && now.second == N)
    {
        _count++;
        return;
    }

    // 가로
    if(prev_type == 0)
    {
        pair<int, int> next1 = {now.first, now.second + 1};
        if(next1.first <= N && next1.second <= N && map[next1.first][next1.second] != 1)
        {
            dfs(map, next1, 0);
        }

        pair<int, int> next2 = {now.first + 1, now.second + 1};
        if(next2.first <= N && next2.second <= N && map[next2.first][next2.second] != 1 && map[next2.first - 1][next2.second] != 1 && map[next2.first][next2.second - 1] != 1)
        {
            dfs(map, next2, 1);
        }
    }
    // 대각선
    else if(prev_type == 1)
    {
        pair<int, int> next1 = {now.first, now.second + 1};
        if(next1.first <= N && next1.second <= N && map[next1.first][next1.second] != 1)
        {
            dfs(map, next1, 0);
        }

        pair<int, int> next2 = {now.first + 1, now.second + 1};
        if(next2.first <= N && next2.second <= N && map[next2.first][next2.second] != 1 && map[next2.first - 1][next2.second] != 1 && map[next2.first][next2.second - 1] != 1)
        {
            dfs(map, next2, 1);
        }

        pair<int, int> next3 = {now.first + 1, now.second};
        if(next3.first <= N && next3.second <= N && map[next3.first][next3.second] != 1)
        {
            dfs(map, next3, 2);
        }
    }
    // 세로
    else if(prev_type == 2)
    {
        pair<int, int> next1 = {now.first + 1, now.second + 1};
        if(next1.first <= N && next1.second <= N && map[next1.first][next1.second] != 1 && map[next1.first - 1][next1.second] != 1 && map[next1.first][next1.second - 1] != 1 )
        {
            dfs(map, next1, 1);
        }

        pair<int, int> next2 = {now.first + 1, now.second};
        if(next2.first <= N && next2.second <= N && map[next2.first][next2.second] != 1)
        {
            dfs(map, next2, 2);
        }
    }

}

int main(void) 
{

    cin >> N;

    vector<vector<int>> map(N+1, vector<int>(N+1));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    pair<int, int> start1 = {1, 2};

    dfs(map, start1, 0);

    cout << _count;

    return 0;
}