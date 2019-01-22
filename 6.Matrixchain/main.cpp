#include <iostream>

using namespace std;
const int N = 1000;
int M[N+2]; //matrix
int C[N][N];  //第一行填行 第二行填列
int T[N][N];  //记录括号的位置...
int n;
int i,j,p,k;
/*
2019年1月21日 13点53分
矩阵的快速乘

思路：
    首先这一题类似于游艇租赁
    好像可以用分治法（类似于合并排序）  不行 分治的分界两边的矩阵不能联系起来，合并不了...
    还是最优化 从动态规划入手吧

    动态规划思路：
        线性的题目 从最后开始思考 如果要计算i到j的矩阵 最少计算量 假设i到j-1的最少计算量已经计算出来了,
        此时计算i到j,一共有j-i-1种画括号的方法，比较得出最少操作次数，即可填入i j中

        最优子结构证明:(证明前要先知道子问题是啥啊！！！) 矩阵链为Ai..Ak..Aj  在Ak后面加括号,设操作次数为C 此时总操作次数就是C(i,j) = C(1,k)+C(k+1,j)+const（这是一个常量）
            两个矩阵相乘的操作次数计算为:m*n*k(m为左边矩阵的行数 n为右边矩阵的列数 k为中间相同的个数)
            假设此时是最优的,则C(l,k) 和 C(k+1,j)也是最优的
            证明:
                如果C（1，k）不是最优的，则存在一个最优解为c，c<C(l,k) 则此时,C(i,j)' = c+C（k+1,j）+const < C(i,j) 与前提矛盾 所以存在最优子结构
    dp方程:
        C(i,j) = min(C(i,k)+C(k+1.j)+const) i<=k<j

    这一题一定要再做一次！！！
*/
void matrixChain(){
    //初始化数组
    for(p=1;p<=2;p++){
        for(i=1;i<=n-p+1;i++){
            j = p+i-1;//行 j 列 p
            if(i!=j){
                C[i][j] = M[i]*M[j]*M[j+1];
                T[i][j] = i;
            }
            else C[i][j] = 0;
        }
    }

    int c;
    for(p=3;p<=n;p++){
        for(i=1;i<=n-p+1;i++){
            j = p+i-1;//行 i 列 j
            C[i][j] = 100000;
            for(k=i;k<j;k++){
                 c = C[i][k]+C[k+1][j]+M[i]*M[j+1]*M[k+1];
                 if(c<C[i][j]){
                    C[i][j] = c;
                    T[i][j] = k;
                 }
            }
        }
    }
}

void print(int h,int t){
    if(h==t){
        cout<<"A["<<h<<"]";
        return;
    }
    cout<<"(";
    print(h,T[h][t]);
    print(T[h][t]+1,t);
    cout<<")";
}

int main()
{
    cout << "矩阵数" << endl;
    cin>>n;
    cout<<"依次输入矩阵的行和最后一个矩阵的列"<<endl;
    for(i=1;i<=n+1;i++){
        cin>>M[i];
    }
    matrixChain();
    cout<<"最大操作次数为:"<<C[1][n]<<endl;
    print(1,n);
    return 0;
}
