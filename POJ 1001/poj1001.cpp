#include<iostream>
using namespace std;

/*TODO:寻找优化方法*/

char R[7];  //输入的实数字符数组  
int n; //幂
int arr[200]; //存储去除小数点的逆序数
int pos;    //数组长度位置
int dot;    //小数点位置（有几个小数）
int temp;      // 去掉小数点的整数

//将实数字符转换成数组
void StringToArr()  
{
    int i;
    int j = 4;
    for (i = 0; i < 6; i++)
    {
        if (R[i] != '.')
        {
            arr[j--] = R[i] - '0';
        }
        else
        {
            dot = 5 - i;
        }
    }
    pos = 5;
}

//将数组转换为去掉小数点的整数
void arrToInt()
{
    temp = 0;
    for (int i = 4; i >= 0; i--)
    {
        temp = temp * 10 + arr[i];
    }
}

//计算算法的实现
void calculate()
{
    int val = 0;
    for (int i = 0; i < pos; i++)
    {
        arr[i] *= temp;
        arr[i] += val;
        val = arr[i] / 10;
        arr[i] %= 10;
    }
    while(val)
    {
        arr[pos++] = val % 10;
        val /= 10;
    }
}

//将结果打印
void printInfo()
{
    int newdot = dot * n;
    int begin = 0;

    //去掉后置零
    for (int i = 0; i < pos; i++)
    {
        if (newdot == begin || arr[i] != 0)
        {
            break;
        }
        begin++;
    }

    //去掉前导零
    for (int i = pos - 1; i >= 0; i--)
    {
        if (arr[i] != 0)
        {
            break;
        }
        pos--;
    }

    //补全小数
    if(newdot > pos)
    {
        while (newdot > pos)
        {
            arr[pos++] = 0;
        }
    }

    //逆序将数组打印输出
    for (int i = pos - 1; i >= begin; i--)
    {
        if( i == newdot - 1)
        {
            cout << ".";
        }
        cout << arr[i];
    }
}

int main()
{
    while(cin >> R >> n)
    {
        dot = -1;
        pos = 0;
        temp = 0;
        StringToArr();
        arrToInt();
        for (int i = 1; i < n; i++)
        {
            calculate();
        }
        printInfo();
        cout << endl;
    }
    return 0;
}