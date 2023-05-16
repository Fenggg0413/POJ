#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Island // 岛屿类
{
public:
    double X;
    double Y;
    Island(double x, double y) : X(x), Y(y) {}
    Island() {}
};

class Section // 区间类
{
public:
    double left;
    double right;
    Section(double l, double r) : left(l), right(r) {}
    Section() {}
    bool operator<(const Section &s)
    {
        return left < s.left;
    }
};

int solve(const vector<Section> &s) // 算法实现
{
    int res; // 需要的雷达数量
    double temp;
    auto val = 0; // 用于做第一次处理
    for (auto beg = s.begin(); beg != s.end(); ++beg)
    {
        if (val == 0) // 处理第一个区间
        {
            val = -1;
            temp = (*beg).right;
            res = 1;
        }
        else
        {
            if (temp < (*beg).left) // 说明两区间没有交集
            {
                ++res; // 雷达数量加一
                temp = (*beg).right;
            }
            else // 否则二者有交集雷达数可不变
            {
                if (temp > (*beg).right)
                {
                    temp = (*beg).right;
                }
            }
        }
    }
    return res;
}

int main()
{
    int n, d;      // n是岛屿的数量，d是雷达装置的覆盖范围
    int count = 0; // 记录测试案例
    do
    {
        ++count;
        cin >> n >> d;
        int err = 0; // 默认有解
        vector<Island> v;
        vector<Section> section;
        for (int i = 0; i < n; ++i) // 输入岛屿
        {
            double x, y;
            cin >> x >> y;
            if (y > d) // 如果有任一y大于d，则无解, 令err=-1
            {
                err = -1;
            }
            Island island(x, y);
            v.push_back(island);
        }
        if (err == -1)
        {
            cout << "case " << count << ": -1" << endl;
        }
        else if (err == 0 && n > 0 && d > 0)
        {
            for (auto i : v) // 对于每一个岛屿，将其在x轴上的投影区间存入section
            {
                double l, r; // left,right
                // 计算区间
                double val = sqrt((d * d) - (i.Y * i.Y));
                l = i.X - val;
                r = i.X + val;
                Section s(l, r);
                section.push_back(s);
            }
            sort(section.begin(), section.end()); // 将区间左端点从小到大排序
            int res = solve(section);
            cout << "case " << count << ": " << res << endl;
        }
    } while (n > 0 && d > 0);
    return 0;
}