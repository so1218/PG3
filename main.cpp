#include <iostream>
#include <list>
#include <cstring>

using namespace std;

// 駅情報構造体
struct Station 
{
    const char* name;
    int openedYear;
};

// 駅を出力する関数
void printStations(const list<Station>& stations, int year)
{
    cout << year << "年" << endl;
    for (const auto& station : stations)
    {
        if (station.openedYear <= year)
        {
            cout << station.name << endl;
        }
    }
    cout << endl;
}

int main() 
{
    list<Station> yamanotesen;

    // 駅データの追加
    yamanotesen.push_back({ "東京", 1970 });
    yamanotesen.push_back({ "神田", 1970 });
    yamanotesen.push_back({ "秋葉原", 1970 });
    yamanotesen.push_back({ "御徒町", 1970 });
    yamanotesen.push_back({ "上野", 1970 });
    yamanotesen.push_back({ "鶯谷", 1970 });
    yamanotesen.push_back({ "日暮里", 1970 });
    yamanotesen.push_back({ "田端", 1970 });
    yamanotesen.push_back({ "駒込", 1970 });
    yamanotesen.push_back({ "巣鴨", 1970 });
    yamanotesen.push_back({ "大塚", 1970 });
    yamanotesen.push_back({ "池袋", 1970 });
    yamanotesen.push_back({ "目白", 1970 });
    yamanotesen.push_back({ "高田馬場", 1970 });
    yamanotesen.push_back({ "新大久保", 1970 });
    yamanotesen.push_back({ "新宿", 1970 });
    yamanotesen.push_back({ "代々木", 1970 });
    yamanotesen.push_back({ "原宿", 1970 });
    yamanotesen.push_back({ "渋谷", 1970 });
    yamanotesen.push_back({ "恵比寿", 1970 });
    yamanotesen.push_back({ "目黒", 1970 });
    yamanotesen.push_back({ "五反田", 1970 });
    yamanotesen.push_back({ "大崎", 1970 });
    yamanotesen.push_back({ "品川", 1970 });
    yamanotesen.push_back({ "田町", 1970 });
    yamanotesen.push_back({ "浜松町", 1970 });
    yamanotesen.push_back({ "新橋", 1970 });
    yamanotesen.push_back({ "有楽町", 1970 });

    // 西日暮里
    for (auto it = yamanotesen.begin(); it != yamanotesen.end(); ++it) 
    {
        if (strcmp(it->name, "田端") == 0)
        {
            yamanotesen.insert(it, { "西日暮里", 2019 });
            break;
        }
    }

    // 高輪ゲートウェイ
    for (auto it = yamanotesen.begin(); it != yamanotesen.end(); ++it)
    {
        if (strcmp(it->name, "田町") == 0) 
        {
            yamanotesen.insert(it, { "高輪ゲートウェイ", 2022 });
            break;
        }
    }

    // 駅表示
    printStations(yamanotesen, 1970);
    printStations(yamanotesen, 2019);
    printStations(yamanotesen, 2022);

    return 0;
}