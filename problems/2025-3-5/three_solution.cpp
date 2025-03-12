// 2473 세 용액
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 이분 탐색 ?

// 1개 배제후 2포인터 ?
// 투포인터 + dp?

long long const INF = 99999999999;

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> solutions;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        solutions.push_back(num);
    }

    sort(solutions.begin(), solutions.end());

    long long min_sum = INF;
    int idxs[3] = {0, };
    for (int i = 0; i < solutions.size(); i++)
    {
        long long target = solutions[i];

        int l_idx = i + 1;
        int r_idx = solutions.size() - 1;
        while(l_idx < r_idx)
        {
            long long sum = solutions[l_idx] + solutions[r_idx];

            if(abs(target + sum) < min_sum)
            {
                min_sum = abs(target + sum);
                idxs[0] = i;
                idxs[1] = l_idx;
                idxs[2] = r_idx;
            }

            if(target + sum > 0)
                r_idx--;
            else if (target + sum < 0)
                l_idx++;
            else
                break;
        }
    }

    cout << solutions[idxs[0]] << " " << solutions[idxs[1]] << " " << solutions[idxs[2]];

    return 0;
}