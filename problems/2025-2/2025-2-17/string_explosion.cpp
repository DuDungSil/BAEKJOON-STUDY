// 9935 문자열 폭발
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 폭발 문자열 : 문자는 문자열에서 사라지며 남은 문자열은 합쳐짐
// 폭발 과정
// 1. 문자열이 폭발 문자열 포함 : 모든 폭발 문자열 폭발 => 남은 문자열 이어붙임
// 2. 새로 생긴 문자열에 폭발 문자열 포함 가능
// 3. 폭발 문자열이 문자열에 없을때까지 계속

// 남아있는 문자가 없는 경우  "FRULA" 출력
// 폭발 문자열은 같은 문자를 두 개 이상 포함하지 않음

// 스택?
// 폭발 문자열의 마지막 char 가 나왔을때 트리거

int main(void) 
{

    string str, ex_str;
    cin >> str >> ex_str;

    stack<char> stack;

    char final_c = ex_str[ex_str.size() - 1];
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        stack.push(c);

        if(c == final_c && stack.size() >= ex_str.size())
        {
            string temp;
            for(int j = 0; j < ex_str.size(); j++)
            {
                temp.push_back(stack.top());
                stack.pop();
            }
            reverse(temp.begin(), temp.end());

            if(temp.compare(ex_str) != 0)
            {
                for(int j = 0; j < temp.size(); j++)
                {
                    stack.push(temp[j]);
                }
            }
        }
    }

    if(stack.empty())
    {
        cout << "FRULA" << "\n";
    }
    else
    {
        string temp;
        while(!stack.empty())
        {
            temp.push_back(stack.top());
            stack.pop();
        }
        reverse(temp.begin(), temp.end());
        cout << temp << "\n";
    }

    return 0;
}