#include <iostream>

using namespace std;
/*
时间：2018年12月27日 16点57分
复习合并排序

1.算法思想
    分治法  具体见下面的注释
    递归  递归函数内部的逻辑实在时要好好揣摩
2.算法技巧
    取一段数组的中间元素，无论奇偶，可直接除2
3.编程技巧
    1.动态分配内存空间(数组) 最后要释放该内存空间（数组）
    2.数组作为函数参数，可以双向传递
    3.使用while循环 数组复制
    4.条件运算
    5.++的使用
*/

void Merge(int A[],int low,int mid,int high){
    //申请一段内存空间 用于暂时存放排序后的元素
    //申请空间大小为 high-low+1
    //动态内存分配
    int *B = new int[high-low+1];
    //排序
    int i = low,j = mid+1;
    int k = 0;//用于存放排序后的指针
    while(i<=mid&&j<=high){
        /*
        if(A[i]<A[j]){
            B[k] = A[i];
        }else{
            B[k] = A[j];
        }
        */
        //使用条件运算代替上面的if else
        //待赋值变量 = 条件？值1：值2
        B[k++] = A[i]<A[j]?A[i++]:A[j++];
    }
    //将剩余部分的元素赋值到B中
    while(i<=mid) B[k++] = A[i++];  // ！数组间的赋值方法
    while(j<=high) B[k++] = A[j++];

    //将B中的元素再次赋值到A中原来的位置
    for(i=0;i<high-low+1;i++){
        A[low+i] = B[i];
    }
    //释放数组 B  中括号的意思时释放数组 没有中括号只会释放内存B
    delete[] B;
}


/*
1.函数说明：
    分：先将待排序的数组，分为两部分，递归分直到只剩一个为止
    治：对相邻两部分进行排序
    合并
2.参数说明：
    A:待排序的数组
    low igh:待分数组的首和尾
*/
void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        //对两个部分进行排序再合并
        Merge(A,low,mid-1,high);
    }
}

int main()
{
    int num,A[100],i=0;
    cin >> num;
    for(i=0;i<num;i++){
        cin >> A[i];
    }
    MergeSort(A,0,num-1);
    for(i=0;i<num;i++) cout<<A[i]<<" ";
    return 0;
}
