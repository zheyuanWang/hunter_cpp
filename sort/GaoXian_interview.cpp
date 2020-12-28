// 你必须定义一个 `main()` 函数入口。
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void printv(vector<int> arr){
  int size_tmp = arr.size(); //todo: no need to calculate size once more
  int i;
  for(i=0;i<size_tmp;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

int main()
{ 
/*
题1：代码编程实现把给定字符串倒转，但单词不倒转，单词之间是空格，如示例：
Here we come Gaussian
Gaussian come we Here；
示例代码中，可以直接复制输入string为“Here we come Gaussian”，用于检验代码的正确性。
*/
  /*
  string teststr = "Here we come Gaussian";
  teststr=' '+teststr;
  string tmpstr;
  string resstr;
  int str_size = teststr.size();
  int w;
  for(w=str_size-1;w>=0;w--){
    //cout<<teststr[w]<<"\n";
    if(teststr[w]!=' '){
        tmpstr.push_back(teststr[w]);
    }
    else{
      reverse(tmpstr.begin(),tmpstr.end());
      tmpstr+=' ';
      resstr+=tmpstr;
      tmpstr="";  //todo remove extra ' '
    }
  }
  cout<<resstr;
  
  */
  

/*题2：C++ 以最小时间算法复杂度实现： 排成锯齿状的顺序；数字同时比左右两边大；或同时比左右两边小：比如1 4 8 9 3 2 5 6 ，排成
     -> 1 4 3 8 2 6 5 9
或者 -> 1 8 4 9 3 5 2 6
*/
    vector<int> test= {1, 4, 8, 3, 2, 6, 5, 9};
    int size = test.size();
    sort(test.begin(),test.end());
       // printv(test);
  
    vector<int> res;
    int j;
    int k = 0;
    int tail = size-1;
    for(j=0;j<size;j++){ 
      if(j%2==0){
        res.push_back(test[k]);
        k++;
      }
      else{
        res.push_back(test[tail]);
        tail--;
      }
      //cout<<"k="<<k<<" test.k= "<<test[k]<<" \n";
     // printv(res);
    }  
  
    printv(res);
  return 0;
}

