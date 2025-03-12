// 1987 알파벳
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R, C;
int max_move_count = 0;

int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

bool visited[40] = {
    false,
};

void dfs(vector<vector<int>>& arr, pair<int, int> now, int move_count)
{
    max_move_count = max(max_move_count, move_count);

    for (int i = 0; i < 4; i++)
    {
        pair<int, int> next = {now.first + dx[i], now.second + dy[i]};
        if(next.first < 1 || next.first > R || next.second < 1 || next.second > C || visited[arr[next.first][next.second]]) continue;
        visited[arr[next.first][next.second]] = true;
        dfs(arr, next, move_count + 1);
        visited[arr[next.first][next.second]] = false;
    }

}

int main(void) 
{

    cin >> R >> C;

    vector<vector<int>> arr(R+1, vector<int>(C+1, -1));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = int(c - 'A');
        }
    }

    visited[arr[1][1]] = true;
    dfs(arr, {1, 1}, 1);

    cout << max_move_count;

    return 0;
}