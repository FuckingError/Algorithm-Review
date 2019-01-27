#include <iostream>
#define M 105
using namespace std;

/*2019年1月27日 21点24分

使用回溯法(深度优先搜索)

想象一棵树
约束条件：1.当前装入的物品小于等于背包容量
          2.还有剩余物品
限界条件(用来加速找到最优解):当前符合约束条件的已装容量价值+剩余物品的总价值 判断是否大于当前最优值  如果小于则不需要再往下进行了 剪枝


注意点:
    1.数组的填入还是从1开始吧  逻辑上负担会轻一点

总结:
    回溯法套路：
        1.解空间是什么
        2.计算上界
        3.分析约束条件(可能不止一个)
*/

int n,c;
double w[M],v[M];//重量 和 价值
int i,j;
double cw = 0.0;//当前重量
double cp = 0.0;//当前价值
bool x[M];//记录下此时的背包情况

double bestp = 0.0;//当前最优价值
bool bestx[M];//当前最优解


//计算上界
double Bound(int k){//剩余物品为 k到n
    double rp = 0;//记录剩余物品总价值
    while(k<=n){
        rp += v[k];
        k++;
    }
    return cp+rp;
}

//递归
void Backtrack(int t){//当前扩展结点为t
    //1.首先判断t是否小于等于n
     /*
            首先如果一切顺序 则一直是向左扩展，得到第一个最优值
                然后回溯到某一点开始向左拓展 此时会判断是否满足限界函数，即当前价值加上剩余总价值是否大于最优解
                    满足才会向右拓展，此时又是如果一切顺利 则....
                    不满足就会剪枝回溯
                所以只要过了子结点 也就是调用了当前这个函数就是最优值
        */
    if(t>n){//说明此时已经到达叶子结点
        //记录下最优值 和 最优解
        for(i=1;i<=n;i++){
            bestx[i] = x[i];
        }
        bestp = cp;
        return;
    }

    //向左拓展 即此时t物品放入  向右拓展 即此时t物品没有放入
    //2.向左扩展 判断是否满足约束条件 cw+w[t]<=c
    if(cw+w[t]<=c){
        x[t] = 1;
        cw += w[t];
        cp += v[t];
        Backtrack(t+1);
        //当这个向右拓展的分支执行完毕后 又回溯到当前结点，准备向左拓展
        cw -= w[t];
        cp -= v[t];
    }
    //3.向左拓展  判断是否满足限界条件
    if(Bound(t+1)>bestp){
        x[t] = 0;
        Backtrack(t+1);
    }
}

void knapsack(){
    //调用搜索函数
    Backtrack(1);
    cout<<"最大价值为:"<<bestp<<endl;
    for(i=1;i<=n;i++){
        if(bestx[i]==1) cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    cout <<"请输入物品个数"<< endl;
    cin>>n;
    cout <<"请输入购物车容量"<< endl;
    cin>>c;//capacity
    cout <<"依次输入每个物品的重量w和价值v"<< endl;
    for(i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    knapsack();
    return 0;
}
