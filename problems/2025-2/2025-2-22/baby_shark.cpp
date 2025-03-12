// 16263 아기 상어
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// 아기상어 크기 : 2
// 아기상어 이동 : 1초에 상하좌우 인접 한 칸
//                자신의 크기보다 큰 물고기 칸만 못지나감
//                크기가 같은 물고기 칸은 못먹지만 지나감
//         행동 : 1. 먹을 수 있는 물고기가 없다면 엄마 상어한테 도움
//                2. 먹을 수 있는 물고기가 1마리라면 먹으러감
//                3. 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹음
//                   거리 : 동일할시 위, 왼쪽 순

// 아기상어 이동은 1초
// 물고기 먹는 시간은 0초
// 이동과 동시에 물고기를 먹는다면 그 칸은 빈 칸
// 자신 크기와 같은 수의 물고기를 먹는다면 크기 + 1

// 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 먹을것인가?

// 먹을 수 있는 물고기의 거리를 모두 구하기 ( 이동 못하는 경우 있음 )
// 먹을 물고기 선택
// 이동
// 먹음 ( 크기 변화 )

// 먹을 물고기 없으면 종료

int N;
vector<vector<int>> world;
int shark_size = 2;
int shark_eat = 0;
int time = 0;
pair<int, int> shark;

int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int getDistance(pair<int, int> fish)
{
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    q.push({0, shark});
    visited[shark.first][shark.second] = true;

    while(!q.empty())
    {
        pair<int, pair<int, int>> info = q.front();
        int depth = info.first;
        pair<int, int> now = info.second;

        if(now.first == fish.first && now.second == fish.second)
        {
            break;
        }
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || visited[next_x][next_y]) continue;
            if(world[next_x][next_y] > shark_size) continue;

            q.push({depth + 1, {next_x, next_y}});
            visited[next_x][next_y] = true;
        }
    }

    if(!q.empty()) return q.front().first;
    else return -1;
}

int main(void) 
{

    cin >> N;

    int fish_count = 0;
    world = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;

            if(num == 9)
            {
                shark = {i, j};
                world[i][j] = 0;
            }
            else if(num != 0)
            {
                fish_count++;
                world[i][j] = num;
            }
            else
                world[i][j] = num;
        }
    }

    // 탐색
    while(fish_count > 0)
    {
        // 남은 물고기 거리 구하기
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(world[i][j] > 0 && world[i][j] < shark_size)
                {
                    int dis = getDistance({i, j});
                    if(dis != -1)
                    {
                        pq.push({dis, {i, j}});
                    }
                }
            }
        }

        // 먹을 물고기가 없다면 탈출
        if(pq.empty())
            break;

        // 먹을 물고기 선택
        pair<int, pair<int, int>> info = pq.top();
        int distance = info.first;
        pair<int, int> target = info.second;

        // 이동
        shark.first = target.first;
        shark.second = target.second;
        time += distance;

        // 먹기
        world[target.first][target.second] = 0;
        fish_count--;
        shark_eat++;

        // 크기 변화 체크
        if(shark_size == shark_eat)
        {
            shark_size++;
            shark_eat = 0;
        }
    }

    cout << time;

    return 0;
}