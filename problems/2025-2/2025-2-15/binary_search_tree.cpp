// 5639 이진 검색 트리
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class binary_search_tree
{
    vector<int> tree;

    public:

        binary_search_tree()
        {
            tree = vector<int>(10001, 0);
            tree[0] = 0;
        }

        void push(int num)
        {
            int now = 1;
            while(true)
            {
                int child_l = 2 * now;
                int child_r = 2 * now + 1;

                if( tree[now] == 0)
                {
                    tree[now] = num;
                    break;
                }

                if ( num < tree[now] )
                {
                    now = child_l;
                    continue;
                }
                else
                {
                    now = child_r;
                    continue;
                }
                
            }


        }

        void print(int now)
        {
            if (tree[now] == 0) return;

            int child_l = 2 * now;
            int child_r = 2 * now + 1;

            if(child_l <= 100001) print(child_l);
            if(child_r <= 100001) print(child_r);

            cout << tree[now] << "\n";
        }
};

int main(void) 
{

    int num;
    binary_search_tree tree;

	while (cin >> num) {
		tree.push(num);
	}
    tree.print(1);

    return 0;
}