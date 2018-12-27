#include <iostream>

using namespace std;
/*
ʱ�䣺2018��12��27�� 16��57��
��ϰ�ϲ�����

1.�㷨˼��
    ���η�  ����������ע��
    �ݹ�  �ݹ麯���ڲ����߼�ʵ��ʱҪ�úô�Ħ
2.�㷨����
    ȡһ��������м�Ԫ�أ�������ż����ֱ�ӳ�2
3.��̼���
    1.��̬�����ڴ�ռ�(����) ���Ҫ�ͷŸ��ڴ�ռ䣨���飩
    2.������Ϊ��������������˫�򴫵�
    3.ʹ��whileѭ�� ���鸴��
    4.��������
    5.++��ʹ��
*/

void Merge(int A[],int low,int mid,int high){
    //����һ���ڴ�ռ� ������ʱ���������Ԫ��
    //����ռ��СΪ high-low+1
    //��̬�ڴ����
    int *B = new int[high-low+1];
    //����
    int i = low,j = mid+1;
    int k = 0;//���ڴ��������ָ��
    while(i<=mid&&j<=high){
        /*
        if(A[i]<A[j]){
            B[k] = A[i];
        }else{
            B[k] = A[j];
        }
        */
        //ʹ������������������if else
        //����ֵ���� = ������ֵ1��ֵ2
        B[k++] = A[i]<A[j]?A[i++]:A[j++];
    }
    //��ʣ�ಿ�ֵ�Ԫ�ظ�ֵ��B��
    while(i<=mid) B[k++] = A[i++];  // �������ĸ�ֵ����
    while(j<=high) B[k++] = A[j++];

    //��B�е�Ԫ���ٴθ�ֵ��A��ԭ����λ��
    for(i=0;i<high-low+1;i++){
        A[low+i] = B[i];
    }
    //�ͷ����� B  �����ŵ���˼ʱ�ͷ����� û��������ֻ���ͷ��ڴ�B
    delete[] B;
}


/*
1.����˵����
    �֣��Ƚ�����������飬��Ϊ�����֣��ݹ��ֱ��ֻʣһ��Ϊֹ
    �Σ������������ֽ�������
    �ϲ�
2.����˵����
    A:�����������
    low igh:����������׺�β
*/
void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        //���������ֽ��������ٺϲ�
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
