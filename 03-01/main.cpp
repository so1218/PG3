#include <iostream>

class Enemy
{
public:
    Enemy()
    {
        state_ = &Enemy::Approach;
    }

    void Update()
    {
        (this->*state_)();
    }

private:
    void (Enemy::*state_)();

    void Approach()
    {
        std::cout << "Ú‹ß\n";
        state_ = &Enemy::Shoot;
    }

    void Shoot()
    {
        std::cout << "ŽËŒ‚\n";
        state_ = &Enemy::Retreat;
    }

    void Retreat()
    {
        std::cout << "—£’E\n";
        state_ = &Enemy::Approach;
    }
};

int main()
{
    Enemy enemy;

    for (int i = 0; i < 3; i++)
    {
        enemy.Update();
    }

    return 0;
}
