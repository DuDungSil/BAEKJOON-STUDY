// 2638 치즈
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 4변중 2변 이상이 실내온도의 공기와 접촉한 것은 한시간만에 녹음
// 치즈 내부는 공기 접촉 X
// 외부 공기 유입시 공기 들어옴
// 가장자리는 치즈 놓이지 않음

// 치즈가 모두 녹아 없어지는 데 걸리는 시간?

// 영역 색칠?
// 외부에서 시작해서 전부탐색 후 외부 색칠
// 그후 나머지 0은 내부로 판단

int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int main(void) 
{

    int N, M;
    cin >> N >> M;

    // 입력
    vector<vector<int>> world(N, vector<int>(M));
    int cheese_count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            world[i][j] = num;
            if(num == 1)
                cheese_count++;
        }
    }

    // 로직
    int time = 0;
    while(cheese_count > 0)
    {
        time++;

        // 외부 색칠
        vector<vector<bool>> masking(N, vector<bool>(M, false));
        queue<pair<int, int>> q;
        q.push({0,0});
        masking[0][0] = true;
        while(!q.empty())
        {
            pair<int, int> info = q.front();
            q.pop();

            int x = info.first;
            int y = info.second;

            for (int i = 0; i < 4; i++)
            {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
                if(world[next_x][next_y] == 0 && !masking[next_x][next_y])
                {
                    q.push({next_x, next_y});
                    masking[next_x][next_y] = true;
                }
            }
        }

        // 마스킹 이용하여 치즈 제거
        vector<vector<int>> temp(world);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(world[i][j] == 1)
                {
                    int air = 0;
                    for(int k = 0; k < 4; k++)
                    {
                        if(masking[i+dx[k]][j+dy[k]])
                        {
                            air++;
                        }
                        if(air >= 2)
                        {
                            temp[i][j] = 0;
                            cheese_count--;
                            break;
                        } 
                    }
                }
            }
        }

        // 적용
        world = temp;
    }

    cout << time;
    return 0;
}