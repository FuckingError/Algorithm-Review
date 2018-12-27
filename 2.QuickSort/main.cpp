#include <iostream>

using namespace std;

/*
2018年12月27日 18点54分

快速排序
    排序的步骤在划分数组的时候完成
    划分数组：基于元素值的划分

算法思想
    分治法
    递归

算法技巧
    数组的划分（Hoare划分）



这里的快速排序比之前趣学算法的优化后的快速排序效率要高 因为这里允许i j 相交后交换位置
*/

/*
函数说明：
    首元素为中值
    先从左向右扫描直到遇到大于 等于 中值的元素停止
    然后从右向左扫描直到遇到小于 等于 中值的元素停止
    (等于的作用：让划分后的数组两部分更加均衡}

    有返回值：中值  !函数有无返回值 在写这个函数的时候自然会知道，无需刻意的在写函数前去思考
*/
int HoarePartition(int r[],int low,int high){
    int privot = r[low];
    int i = low+1,j = high;
    //体会：while嵌套 越往里的越是具体操作步骤，写代码时可以从内往外写，逐层考虑限制条件
    while(i<j){
            // ! 在while循环条件里面 ++ -- 不好
        while(i<=high&&r[i]<=privot) i++; // ！ 先把越界的条件写在前面判断 否则可能会出现越界后 空指针异常
        while(j>low&&r[j]>=privot) j--;// ！不要下意识的写++ 这里应该是--  | 这里j>low 不能写等于 如果是j>=low 则 最坏情况下 跳出该while是i=low-1 此时已经越界，那么外层while循环的外面的代码 swap 和 返回中值都会异常
        //三种情况  i<j i=j j<i
        //当 i<j 交换r[i] r[j]
        if(i<j) swap(r[i++],r[j--]);
        /*
        i == j 此时r[i] 也就是r[j] 一定等于privot  也就是说 此时已经划分好了
            此时只要再一次while循环，就会j<i 就会将数组首元素的privot与r[j]交换位置，两个privot就在一起了
        j < i 需要交换privot和r[j] 这只需要在最后执行(也是外层while的中止条件)
        */
    }
    /*
    跳出while时 i 和 j会越界吗 i不用管
        j不会 因为跳出while循环是的最坏情况是 j=low 此时swap还是其本身 返回中值位置是首元素位置
    */

    //i == j 有两种情况  一是从while中跳出来的 二是从HoarePartition进来就i==j(即此时待排序的部分只有两个元素)
    if(i==j){
        if(high-low==1&&r[low]<r[j]) return j;
        else if(high-low!=1) j = j-1; //当从hile循环中跳出来时 交换j-1和首元素 这样效率会高一点
    }
    swap(r[low],r[j]);
    return j;
}


/*
函数说明：
    先划分元素，划分完毕后根据中值对划分后的两部分再进行快排(递归)
*/
void QuickSort(int r[],int low,int high){
    int mid = 0;
    if(low<high){
        mid = HoarePartition(r,low,high);
        QuickSort(r,low,mid-1);
        QuickSort(r,mid+1,high);
    }
}

int main()
{
    int num,A[100],i=0;
    cin >> num;
    for(i=0;i<num;i++){
        cin >> A[i];
    }
    QuickSort(A,0,num-1);
    for(i=0;i<num;i++) cout<<A[i]<<" ";
    return 0;
}
