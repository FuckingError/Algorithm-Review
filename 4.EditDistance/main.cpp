#include <iostream>
#include <cstring>

using namespace std;
const int N = 100;
int c[N][N];//这里先使用二维数组  待会写一个滚动数组
char s1[N],s2[N];
int i,j;
int len1,len2;
/*
2019年1月18日 20点41分
编辑距离
s1：family
s2: frame    求s1经过最少多少次编辑 可以成为s2

思路：

  1.自顶往下 (从字符串最后开始)
   如果相同: c[i][j] = c[i-1][j-1]
   如果不同:三种操作方式
        1.编辑 c[i][j] = c[i-1][j-1]+1
        2.删除 c[i][j] = min(c[i-1][j]+1,c[i][j-1]+1)
                              删s1末尾     删s2末尾
            注意：删除只能删s1 不能删s2  所以删除就是 c[i][j] = c[i-1][j]+1
        3.删除s2 （结合实例 按正常操作思路看）其实就是在s1中插入   ! 如果自顶往下分析(字符串从后往前分析)不容易想清楚 可以按正常操作思路从前往后分析（思考如何操作字符串才能达到目的）
            c[i][j] = c[i][j-1]+1
    2.dp方程有了之后 就要思考递归的边界  也就是递推的初始值(数组边界的值是什么)

数据结构：
    二维数组
复杂度 mn


编程技巧：min的使用 当从三个数中找一个最小值
*/

void editDistance(){
     //初始化数组
    /*
        行是s2   列是s1
        数组边界：
            0行初始值为 0-len2
            0列初始值为 1-len1(从第1行开始)
    */
    for(i=0;i<=len2;i++){
        c[0][i] = i;
    }
    for(i=1;i<=len1;i++){
        c[i][0] = i;
    }
    //填表
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]) c[i][j] = c[i-1][j-1];
            else c[i][j] = min(min(c[i-1][j],c[i][j-1]),c[i-1][j-1])+1; // ! min的使用 当从三个数中找一个最小值
        }
    }
}

int main()
{
    cout<<"输入s1"<<endl;
    cin>>s1;
    cout<<"输入s2"<<endl;
    cin>>s2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    editDistance();
    cout<<"编辑距离为:"<<c[len1][len2];
    return 0;
}
