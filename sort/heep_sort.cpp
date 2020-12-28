#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 把数组arr中从start到end的部分调整成大顶堆。
void max_heapify(int arr[], int start, int end){
    int dad = start;
    int max_son = start * 2 +1;
    while(max_son <= end){
        if(max_son + 1 <=end && arr[max_son] < arr[max_son + 1]){  //max_son指向 两个子节点中较大的一个
            max_son++;  //case:右子节点
        }

        if(arr[max_son] > arr[dad]){  //max_son和dad比较
            swap(&arr[max_son], &arr[dad]);
            dad = max_son;  //如果换了,进入低一层: 当前max_son作为dad
            max_son = dad*2 + 1;  //对应的左子节点 = dad x 2 + 1
        }
        else{
            return ; //不用换就return, 如果换了继续判定while循环
        }
    }
}


void heap_sort(int arr[], int len){
    //创建堆，从最后一个非叶子结点开始
    //最后一个叶子节点的索引值是n-1,它的父节点索引值是[(n-1)-1]/2 = n/2 -1
    for(int i = len/2 - 1; i>=0; i--){  //从最后的根节点开始,i--, 从底层整理到高层
        max_heapify(arr, i, len-1);  //调整为大顶堆, 每次循环得到当前大顶堆的max(顶)
    }

    //堆排序
    for(int i = len-1; i>0; i--){ //从尾巴开始, i-- (每次短一截)
        swap(&arr[0], &arr[i]);  //把尾巴min元素换到堆顶,再次构建大顶堆
        max_heapify(arr, 0, i-1);
    }
}


int main(){
    int arr[] = {4,6,8,5,9};
    int len = sizeof(arr) / sizeof(*arr);

    heap_sort(arr,len);

    for(int i = 0; i<len; i++){
        printf("%d , \n", arr[i]);
    }
}