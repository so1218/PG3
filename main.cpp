#include <stdio.h>
#include <windows.h>

// 再帰的に時給を計算して、合計賃金を返す関数
int recursiveWage(int hours, int wage)
{
    if (hours == 0)
        return 0;
    return wage + recursiveWage(hours - 1, wage * 2 - 50);
}

int main()
{
    int hours = 8;

    int general = hours * 1226;

    int recursive = recursiveWage(hours, 100);

    printf("働いた時間 %d時間\n", hours);
    printf("一般的な賃金体系 %d円\n", general);
    printf("再帰的な賃金体系 %d円\n", recursive);


    return 0;
}
