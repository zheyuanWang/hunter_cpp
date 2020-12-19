#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        //执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 内存消耗： 6.2 MB , 6.2 MB , 在所有 C++ 提交中击败了 20.84% 的用户
        int a = 1, b = 1 , tmp = 1;
        string s = to_string(num);
        int length = s.size();
        //if(length==1) return 1; //这一行可以去掉: 在for循环中含有了length>i (即>1)的条件, 否则直接返回的b=1

        for(int i =1; i<length; i++){
            string tmp_str= s.substr(i-1,2);
            int tmp_int = stoi(tmp_str);
            if(tmp_int<26 && tmp_int>=10){ // 题意06并不能组合成6, 所以个位数都要排除在外
                tmp = b;
                b = tmp + a;
                a = tmp;
            }
            else{
                a = b; //记得更新上上格子a的值, b保持在当前格子没有变
            }
        }
    return b;
    }
};


void test_function1(int test_int)
{
    Solution ss;
    cout<<ss.translateNum(test_int);
}

int main(){
    test_function1(18822);
}