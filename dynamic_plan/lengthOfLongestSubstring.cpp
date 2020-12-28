#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;
        int i = -1, res = 0, len = s.size();
        for(int j = 0; j < len; j++) {
            if(dic.find(s[j]) != dic.end())  //若找到重复:
                i = max(i, dic.find(s[j])->second); // 更新左指针(若有重复则指向重复)
            dic[s[j]] = j; // 哈希表记录新值. 总是先更新左指针后记录, 使得左指针指向的是前一个重复点
            res = max(res, j - i); // 更新结果, j-i=两个重复点相减
        }
        return res;
    }

    //以下方法我觉得没必要引入tmp,还是上面这个好.
    int lengthOfLongestSubstring_single_ptr(string s) {
        unordered_map<char, int> dic;  //字典,记录某char上一次出现的index
        int res = 0, tmp = 0, len = s.size(), i;
        for(int j = 0; j < len; j++) {
            if(dic.find(s[j]) == dic.end()) i = - 1;  //没有找到重复的char s[j]
            else i = dic.find(s[j])->second; // 找到了重复翻char: 获取索引 i
                                            //对map容器  (*it).first会得到key，  (*it).second会得到value，这等同于it->first和it->second
            dic[s[j]] = j;                  // 更新哈希表(更新该char上一次出现的index)
            tmp = tmp < j - i ? tmp + 1 : j - i; // dp[j - 1] -> dp[j]
            res = max(res, tmp);            // max(dp[j - 1], dp[j])
        }
        return res;
    }
};


