#include <iostream>
using namespace std;
long long extgcd(long long a, long long b, long long &x, long long &y)
{
    long long d;
    if (b == 0)
    { //递归终止条件
        x = 1;
        y = 0;
        return a;
    }
    d = extgcd(b, a % b, x, y);
    long long temp = x;
    x = y;
    y = temp - a/b* y;
    return d; //返回的是最大公约数
}
int main()
{
    long long x, y, m, n, L, X, Y, d, r;
    while (cin >> x >> y >> m >> n >> L)
    {
        d = extgcd(n - m, L, X, Y);//a=n-m,b=L
        r = L / d; //最小正整数解在[0,b/d-1]范围
        if ((x - y) % d)    //c=x-y,c%d不等于0则无解
            cout << "Impossible" << endl;
        else
            cout << ((x - y) / d * X % r + r) % r << endl; //算出最小正整数解
    }
    return 0;
}