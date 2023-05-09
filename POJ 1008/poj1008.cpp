#include<iostream>
#include<string>
using namespace std;

string Haab_month[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
string Tzolkin_day[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main()
{
    int haab_day, haab_year;
    char ch;
    string haab_month;
    int count; //记录总数据量
    cin >> count;
    cout << count <<endl;
    while(count--)
    {
        cin >> haab_day >> ch >> haab_month >> haab_year;
        //找到对应的Haab月
        int temp;
        int days;   //总天数
        for (int i = 0; i < 19; i++)
        {
            if(haab_month == Haab_month[i])
            {
                temp = i + 1;   //暂存月份对应的下标
                break;
            }
        }
        days = 365 * haab_year + (temp - 1) * 20 + haab_day;
        int Tzolkin_year, Tzolkin_day_index, Tzolkin_day_num;
        Tzolkin_year = days / 260;
        if(days % 260 == 0){
            days = 260;
        }
        else{
            days = days % 260;
        }
        Tzolkin_day_num = days % 13 + 1;
        Tzolkin_day_index = days % 20;
        cout << Tzolkin_day_num << " " << Tzolkin_day[Tzolkin_day_index] << " " << Tzolkin_year << endl;
    }
    return 0;
}

