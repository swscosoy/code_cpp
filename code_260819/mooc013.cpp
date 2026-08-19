#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

static string typeName[5] = {"dragon", "ninja", "iceman", "lion", "wolf"}; // 各类士兵类型
static int typeHealth[5] = {0};                                            // 各类士兵初始生命值

class Color
{
public:
    string color;        // 队伍颜色
    int soldierOrder[5]; // 士兵生成顺序

    // 构造函数
    Color(string c);

    void createSoldiersOrder()
    {
        if (color == "red")
        {
            soldierOrder[0] = 2; // iceman
            soldierOrder[1] = 3; // lion
            soldierOrder[2] = 4; // wolf
            soldierOrder[3] = 1; // ninja
            soldierOrder[4] = 0; // dragon
        }
        else if (color == "blue")
        {
            soldierOrder[0] = 3; // lion
            soldierOrder[1] = 0; // dragon
            soldierOrder[2] = 1; // ninja
            soldierOrder[3] = 2; // iceman
            soldierOrder[4] = 4; // wolf
        }
    }
};

class Soldier
{
public:
    string commander; // 所属司令
    int code;         // 士兵编号
    int health;       // 生命值
    int tag;          // 士兵类型标签
    string type;      // 士兵类型

    // 构造函数
    Soldier(string c, int cd, int h, string t);
};

class Commander
{
public:
    string name;                            // 司令名字
    string color;                           // 队伍颜色
    int health;                             // 生命元
    int s_num[5]; // 各类型士兵数量
    int s_sum;                          // 士兵总数
    bool stop;                       // 司令部是否停止制造士兵

    // 构造函数
    Commander(string n, string c, int h, bool s);

    // 制造士兵
    void createSoldiers(int time)
    {
        if (this->stop)
            return;
        Color col(color);          // 创建队伍颜色对象;
        col.createSoldiersOrder(); // 生成士兵顺序
        s_sum++; // 士兵总数增加
        for (int t = time;; t++)
        {
            Soldier sol(color, s_sum, typeHealth[col.soldierOrder[t % 5]], typeName[col.soldierOrder[t % 5]]); // 创建士兵对象
            this->health -= sol.health;
            // 司令部生命元减少
            if (t == time + 5){
                this->stop = true;
                cout << setfill('0') << setw(3) << time << " " << color << " headquarter stops making warriors" << endl;
                break;
            }
            else
            {
                if (this->health >= 0)
                {
                    cout
                        << setfill('0') << setw(3)
                        << time << " "
                        << color << " "
                        << sol.type << " "
                        << sol.code << " "
                        << "born with strength" << " "
                        << sol.health << ","
                        << ++s_num[col.soldierOrder[t % 5]] << " "
                        << sol.type << " "
                        << "in" << " "
                        << color << " "
                        << "headquarter" << endl;
                    break;
                }
                else
                {
                    this->health += sol.health; // 司令部生命元恢复
                }
            }
        }
    }
};

Soldier::Soldier(string c, int cd, int h, string t) : commander(c), code(cd), health(h), type(t) {};
Commander::Commander(string n, string c, int h, bool s) : name(n), color(c), health(h), stop(s) {
        for (int i = 0; i < 5; i++) s_num[i] = 0;
        s_sum = 0;
};
Color::Color(string c) : color(c) {};

// 预备士兵
void ready(int M, int time = 0)
{

    // 创建红蓝司令部对象
    Commander redC("redName", "red", M, false);
    Commander blueC("blueName", "blue", M, false);

    // 输出红蓝司令部生成士兵信息
    while (!redC.stop || !blueC.stop)
    {
        redC.createSoldiers(time);
        blueC.createSoldiers(time);
        time++;
    }
}

int main()
{
    int n, i = 1; // 组数
    int M;        // 司令部生命元初始值
    cin >> n;
    while (n)
    {
        cin >> M >> typeHealth[0] >> typeHealth[1] >> typeHealth[2] >> typeHealth[3] >> typeHealth[4];
        cout << "Case:" << i++ << endl;
        ready(M);
        n--;
    }
    return 0;
}