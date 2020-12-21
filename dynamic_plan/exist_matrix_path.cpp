#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //参考标准答案改的, 最后还是跑不进时间限制-> 就因为多了两行cout, 以后提交代码记得把cout给注释掉
        lenx = board.size();
        leny = board[0].size();
        for(int xx = 0; xx<lenx; xx++){
            for(int yy = 0; yy<leny;yy++){
                //cout<<"checking position ("<<xx<<" "<<yy<<")\n";
                if(dfs(board,word,xx,yy,0)) return true;
            }
        }
    return false;
    }
    
private:
    int lenx, leny;
//bool dfs(vector<vector<char>> board, string word, int x, int y, int k) { // 这里用board 取代 & board不妥, 前者会导致运行时长大大增加
//但是, 使用&board 进行引用传递的话要记得把 已路过所以标记为0 的格子恢复原来的值以方便下一波操作

    bool dfs(vector<vector<char>>& board, string word, int x, int y, int k) {       
        //cout<<"sub position ("<<x<<" "<<y<<")\n";
            if(x>=lenx||y>=leny||x<0||y<0||word[k]!=board[x][y]){ // out of range
                return false;
                }
            if(board[x][y]==word[k]){ //current block matches
                board[x][y]='\0'; //avoid come back
                if (k==(word.size()-1)){
                    return true;
                }
                bool res = dfs(board,word,x+1,y,k+1)||dfs(board,word,x,y+1,k+1)||dfs(board,word,x-1,y,k+1)||dfs(board,word,x,y-1,k+1);

                board[x][y] = word[k]; //关键的恢复操作
                //而且, k的递增要在迭代中给出, 否则恢复操作中的不清楚对应的k值
                return res;
            }
    return false;
    }
};


int main(){
//    vector<vector<char>> input_board = {{'A','B','C','E'},{'S','F','C','S'},{'B','D','E','E'}};    
//    vector<vector<char>> input_board={{'A'}};
    vector<vector<char>> input_board = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    Solution ss;
    cout<<ss.exist(input_board,"AAB");
}