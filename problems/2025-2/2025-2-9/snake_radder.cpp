// 16928 사다리 뱀 게임
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

// 사다리 : 밑으로 이동
// 뱀 : 위로 이동
// 사다리 뱀 중 최대 하나만
// 100번 칸에 도착하기 위해 주사위 횟수 최솟값

// dp?
// bfs

int main(void) 
{
    int N, M;
    cin >> N >> M;

    bool visited[101] = {
        false,
    };
    int radder[101] = {0, };
    int snake[101] = {0, };

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        radder[a] = b;
    }
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }

    queue<pair<int, int>> q;
    pair<int, int> start(1, 0);
    q.push(start);
    while(!q.empty())
    {
        int now, depth;
        pair<int, int> info = q.front();
        now = info.first;
        depth = info.second;
        if(now == 100)
        {
            break;
        }
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int next = now + i;
            if(next > 100) continue;
            if(visited[next] == true) continue;
            visited[next] = true;
            if(radder[next] != 0)
            {
                if(visited[radder[next]] == true) continue;
                pair<int, int> next_info(radder[next], depth + 1);
                q.push(next_info);
                visited[radder[next]] = true;
            }
            else if(snake[next] !=0)
            {
                if(visited[snake[next]] == true) continue;
                pair<int, int> next_info(snake[next], depth + 1);
                q.push(next_info);
                visited[snake[next]] = true;
            }
            else
            {
                pair<int, int> next_info(next, depth + 1);
                q.push(next_info);
            }
        }
    }

    cout << q.front().second;

    return 0;
}