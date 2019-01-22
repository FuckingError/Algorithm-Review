#include <iostream>
#include <cstring>

using namespace std;
/*
2019年1月18日 23点47分
使用滚动数组 哈哈哈
*/
const int N = 100;
char s1[N],s2[N];
int c[N]; //行为s2
int i,j;
int len1,len2;

void EditDistance(){
    //初始化数组c 0 到 s2
    int temp = 0,mintemp = 0;//存储的 相当于二维表的左上角的值

    for(i=0;i<=len2;i++){
        c[i] = i;
    }
    for(i=0;i<len1;i++){
        for(j=1;j<=len2;j++){
            if(s1[i]!=s2[j-1]){
                mintemp = min(min(c[j],c[j-1]),temp)+1;
                temp = c[j];
                c[j] = mintemp;
            }else c[j] = temp;
        }
    }
}

int main()
{
    cout << "输入s1" << endl;
    cin>>s1;
    cout << "输入s2" << endl;
    cin>>s2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    EditDistance();
    cout<<"编辑距离为:"<<c[len2]<<endl;
    return 0;
}
