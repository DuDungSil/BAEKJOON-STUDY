#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <math.h>

using namespace std;

// 방향 벡터
int dx[6] = {-1, +1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, +1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, +1};

int main(void) 
{
    int M, N, H;
    cin >> M >> N >> H;

    // 고정 크기 배열을 사용하려면 배열 크기를 M, N, H에 맞춰야 합니다.
    int tomato[100][100][100];
    bool visited[100][100][100] = {false};

    queue<tuple<int, int, int>> q;

    // 입력
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                int num;
                cin >> num;
                tomato[h][n][m] = num;
                if(num == 1)
                {
                    visited[h][n][m] = true;
                    tuple<int, int, int> t = {m, n, h};
                    q.push(t);
                }
            }
        }
    }

    // BFS
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            int next_z = z + dz[i];
            
            // 범위 체크
            if(next_x < 0 || next_y < 0 || next_z < 0 || next_x >= M || next_y >= N || next_z >= H) continue;
            if(tomato[next_z][next_y][next_x] == 0 && !visited[next_z][next_y][next_x])
            {
                tomato[next_z][next_y][next_x] = tomato[z][y][x] + 1;
                visited[next_z][next_y][next_x] = true;
                tuple<int, int, int> t = {next_x, next_y, next_z};
                q.push(t);
            }
        }
    }

    // 0인 토마토 확인 && max값 확인
    bool isZero = false;
    int max_count = -1;
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                int count = tomato[h][n][m];
                if(count == 0)
                {
                    isZero = true;
                    break;
                }
                max_count = max(max_count, count);
            }
        }
    }

    if(isZero) cout << -1;
    else cout << max_count - 1;

    return 0;
}
