// 2206 벽 부수고 이동하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int main(void) 
{

    cin >> N >> M;

    vector<vector<int>> world(N+1, vector<int>(M+1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            char num;
            cin >> num;
            world[i][j] = int(num-'0');
        }
    }

    // bfs
    queue<tuple<pair<int,int>, bool, int>> q;
    map<pair<int, int>, bool> visited;
    map<pair<int, int>, bool> visited_d;
    q.push({{1, 1}, false, 1});
    visited[{1, 1}] = true;

    while(!q.empty())
    {
        pair<int, int> now;
        bool destroyed;
        int depth;
        tie(now, destroyed, depth) = q.front();

        if(now.first == N && now.second == M)
        {
            break;
        }
        q.pop();

        // 탐색
        for(int i = 0; i < 4; i++)
        {
            int next_y = now.first + dy[i];
            int next_x = now.second + dx[i];

            if(next_x < 1 || next_y < 1 || next_x > M || next_y > N) continue;

            if(world[next_y][next_x] == 1)
            {
                if(!destroyed && !visited_d[{next_y, next_x}])
                {
                    q.push({{next_y, next_x}, true, depth + 1});
                    visited_d[{next_y, next_x}] = true;
                }
            }
            else
            {
                if(!destroyed)
                {
                    if(!visited[{next_y, next_x}])
                    {
                        q.push({{next_y, next_x}, destroyed, depth + 1});
                        visited[{next_y, next_x}] = true;
                    }
                }
                else
                {
                    if(!visited_d[{next_y, next_x}])
                    {
                        q.push({{next_y, next_x}, destroyed, depth + 1});
                        visited_d[{next_y, next_x}] = true;
                    }
                }
            }
        }

    }

    if(!q.empty())
    {
        cout << get<2>(q.front());
    }
    else
    {
        cout << -1;
    }
    return 0;
}