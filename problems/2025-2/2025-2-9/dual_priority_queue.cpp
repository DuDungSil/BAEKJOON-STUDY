// 7662 이중 우선순위 큐
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// 데이터 삽입 연산
// 데이터 삭제 연산 1. 우선순위 높은거 2. 우선순위 낮은거
// Q의 최솟값, 최대값 구하기

int main(void) 
{

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int k;
        cin >> k;

        priority_queue<long long> big;
        priority_queue<long long, vector<long long>, greater<long long>> small;
        map<long long, long long> big_removed;
        map<long long, long long> small_removed;

        for (int j = 0; j < k; j++)
        {
            char c;
            cin >> c;

            long long num;
            cin >> num;
            
            if(c == 'I')
            {
                big.push(num);
                small.push(num);
            }
            if(c == 'D')
            {
                // 최댓값 삭제
                if(num == 1)
                {
                    while(!big.empty())
                    {
                        long long prior = big.top();
                        if(small_removed[prior] > 0)
                        {
                            small_removed[prior]--;
                            big.pop();
                        }
                        else
                        {
                            big_removed[prior]++;
                            big.pop();
                            break;
                        }
                    }
                }
                // 최솟값 삭제
                else if(num == -1)
                {
                    while(!small.empty())
                    {
                        long long prior = small.top();
                        if(big_removed[prior] > 0)
                        {
                            big_removed[prior]--;
                            small.pop();
                        }
                        else
                        {
                            small_removed[prior]++;
                            small.pop();
                            break;
                        }
                    }
                }
            }
        }

        while(!big.empty())
        {
            long long prior = big.top();
            if(small_removed[prior] > 0)
            {
                small_removed[prior]--;
                big.pop();
            }
            else
            {
                break;
            }
        }
        while(!small.empty())
        {
            long long prior = small.top();
            if(big_removed[prior] > 0)
            {
                big_removed[prior]--;
                small.pop();
            } 
            else
            {
                break;
            }
        }
        if(big.empty() || small.empty())
        {
            cout << "EMPTY" << "\n";
        }
        else
        {
            cout << big.top() << " " << small.top() << "\n";
        }


    }

    return 0;
}