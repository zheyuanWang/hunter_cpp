#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fff(int v){
        cout<<v<<"  ";
        if(v<13){
            v++;
            return fff(v);
        }
        return v;
    }
};

int main(){
    Solution ss;
    int x = 1;
    cout<<"mmmm"<<ss.fff(x);
    cout<<"x="<<x;
}