// 13549 숨바꼭질 3
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main(void) 
{

    int C, N;
    cin >> C >> N;

    bool visited[1000001] = {false,};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, C});

    int max = 9999999999;
    while (!pq.empty())
    {
        pair<int, int> info = pq.top();
        int now = info.second;
        int depth = info.first;
        if(now == N)
        {
            break;
        }
        pq.pop();

        int next1 = now * 2;
        if(next1 >= 0 && next1 <= 1000001 && !visited[next1])
        {
            visited[next1] = true;
            pq.push({depth, next1});
        }

        int next2 = now + 1;
        if(next2 >= 0 && next2 <= 1000001 && !visited[next2])
        {
            visited[next2] = true;
            pq.push({depth + 1, next2});
        }

        int next3 = now - 1;
        if(next3 >= 0 && next3 <= 1000001 && !visited[next3])
        {
            visited[next3] = true;
            pq.push({depth + 1, next3});
        }

    }

    cout << pq.top().first;

    return 0;
}