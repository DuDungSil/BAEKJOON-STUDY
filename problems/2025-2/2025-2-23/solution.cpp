// 2467 용액
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 특성값이 0에 가까운 용액을 만들어내는 두 용액의 특성값 출력

int main(void) 
{

    int N;
    cin >> N;

    vector<int> solution;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        solution.push_back(num);
    }

    int big_sum = 2000000001;
    int big_nums[2] = {
        0,
    };
    int small_sum = -2000000001;
    int small_nums[2] = {
        0,
    };

    int l_p = 0;
    int r_p = N - 1;
    while(l_p < r_p)
    {
        int sum = solution[l_p] + solution[r_p];

        if(sum == 0)
        {
            cout << solution[l_p] << " " << solution[r_p];
            return 0;
        }
        else if(sum > 0 && sum < big_sum)
        {
            big_sum = sum;
            big_nums[0] = solution[l_p];
            big_nums[1] = solution[r_p];
        }
        else if(sum < 0 && sum > small_sum)
        {
            small_sum = sum;
            small_nums[0] = solution[l_p];
            small_nums[1] = solution[r_p];
        }

        if(abs(solution[l_p]) < abs(solution[r_p]))
            r_p--;
        else
            l_p++;
    }

    if(abs(big_sum) < abs(small_sum))
        cout << big_nums[0] << " " << big_nums[1];
    else
        cout << small_nums[0] << " " << small_nums[1];

    return 0;
}