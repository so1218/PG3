#include <iostream>
#include <memory>

class Pirate
{
public:
    virtual void Attack()
    {
        std::cout << "海賊が攻撃する\n";
    }

    virtual ~Pirate() {}
};

class Luffy : public Pirate
{
public:
    void Attack() override
    {
        std::cout << "ゴムゴムのピストル\n";
    }
};

class Zoro : public Pirate
{
public:
    void Attack() override
    {
        std::cout << "三千世界\n";
    }
};

int main()
{
    std::unique_ptr<Pirate> pirate1 = std::make_unique<Luffy>();
    std::unique_ptr<Pirate> pirate2 = std::make_unique<Zoro>();

    pirate1->Attack();
    pirate2->Attack();

    return 0;
}