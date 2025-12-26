#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>   
#include <windows.h>


void ShowResult(int roll, int userGuess)
{
    printf("出目は %d でした。\n", roll);

    int actualResult = roll % 2;

    if (userGuess == actualResult)
    {
        printf("正解\n");
    }
    else
    {
        printf("不正解\n");
    }
}

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess)
{
    Sleep(delayMs);

    fn(roll, userGuess);
}

int main()
{
    int userGuess;
    int roll;

    srand((unsigned int)time(NULL));

    printf("半(奇数:1)か丁(偶数:0)か: ");
    scanf_s("%d", &userGuess);

    roll = rand() % 6 + 1;

    DelayReveal(ShowResult, 3000, roll, userGuess);

    return 0;
}