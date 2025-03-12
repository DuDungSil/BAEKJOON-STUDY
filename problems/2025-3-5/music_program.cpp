// 2623 음악프로그램
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 위상정렬?

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> orders(M);
    vector<vector<int>> graph(N+1);
    vector<int> indegree(N+1, 0);
    vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));

    for (int i = 0; i < M; i++)
    {
        int K;
        cin >> K;
        
        for (int j = 0; j < K; j++)
        {
            int num;
            cin >> num;
            orders[i].push_back(num);
        }
    }

    // 전처리 100 * 1000 * 1000
    for(int i = 0; i < M; i++)
    {
        vector<int>& order = orders[i];
        for (int j = 0; j < order.size() - 1; j++)
        {   
            for (int k = j + 1; k < order.size(); k++)
            {
                int first_node = order[j];
                int second_node = order[k];
                if(!visited[first_node][second_node])
                {
                    visited[first_node][second_node] = true;
                    graph[first_node].push_back(second_node);
                    indegree[second_node]++;
                }
            }
        }
    }

    // 위상정렬
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    queue<int> output;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        output.push(now);

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            indegree[next]--;
            if(indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    if(output.size() == N)
    {
        // 정상 출력
        while(!output.empty())
        {
            cout << output.front() << "\n";
            output.pop();
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}