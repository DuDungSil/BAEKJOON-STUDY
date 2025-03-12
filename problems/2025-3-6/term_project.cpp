// 9466 텀 프로젝트
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 모든 학생이 팀원 한명 선택 ( 자기 자신 가능 )

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;

        vector<int> selected(n + 1, 0);
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int s;
            cin >> s;
            selected[i] = s;
            graph[i].push_back(s);
            indegree[s]++;
        }

        // 전처리
        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int now = q.front();
            q.pop();

            for (int i = 0; i < graph[now].size(); i++)
            {
                int next = graph[now][i];
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
            
        }

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if(indegree[i] == 0)
            {
                count++;
            }
        }
        cout << count << "\n";

    }

    return 0;
}