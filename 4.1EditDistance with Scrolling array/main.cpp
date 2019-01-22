#include <iostream>
#include <cstring>

using namespace std;
/*
2019��1��18�� 23��47��
ʹ�ù������� ������
*/
const int N = 100;
char s1[N],s2[N];
int c[N]; //��Ϊs2
int i,j;
int len1,len2;

void EditDistance(){
    //��ʼ������c 0 �� s2
    int temp = 0,mintemp = 0;//�洢�� �൱�ڶ�ά������Ͻǵ�ֵ

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
    cout << "����s1" << endl;
    cin>>s1;
    cout << "����s2" << endl;
    cin>>s2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    EditDistance();
    cout<<"�༭����Ϊ:"<<c[len2]<<endl;
    return 0;
}
