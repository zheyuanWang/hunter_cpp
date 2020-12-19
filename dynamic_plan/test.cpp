#include <string>
#include <iostream>
using namespace std;

int main(){
    string s = "12345";
    string tmp_str= s.substr(-1,2);
    cout<<tmp_str;
}