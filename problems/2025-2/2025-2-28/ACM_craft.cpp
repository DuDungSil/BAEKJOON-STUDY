// 1005 ACM craft
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 위상정렬

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, K;
        cin >> N >> K;

        vector<int> need_time(N+1);
        vector<int> dist(N+1, 0);
        vector<int> degrees(N+1, 0);
        for (int i = 1; i <= N; i++)
        {
            int D;
            cin >> D;
            need_time[i] = D;
        }

        vector<vector<int>> sequence(N+1);
        for (int i = 0; i < K; i++)
        {
            int X, Y;
            cin >> X >> Y;
            sequence[X].push_back(Y);
            degrees[Y]++;
        }

        int W;
        cin >> W;

        queue<int> q;
        for(int i = 1; i <= N; i++)
        {
            if(degrees[i] == 0)
            {
                q.push(i);
            }
        }

        int time = 0;

        // 시간 계산
        while(!q.empty())
        {
            int now = q.front();
            q.pop();

            if(now == W)
                break;

            for (int i = 0; i < sequence[now].size(); i++)
            {
                int next = sequence[now][i];
                degrees[next]--;
                dist[next] = max(dist[now] + need_time[now], dist[next]);
                if(degrees[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        
        cout << dist[W] + need_time[W] << "\n";
    }

    return 0;
}