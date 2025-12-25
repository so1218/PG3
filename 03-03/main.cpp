#include <iostream>
#include <memory>

class Pirate
{
public:
    virtual void Attack()
    {
        std::cout << "ŠC‘¯‚ªUŒ‚‚·‚é\n";
    }

    virtual ~Pirate() {}
};

class Luffy : public Pirate
{
public:
    void Attack() override
    {
        std::cout << "ƒSƒ€ƒSƒ€‚ÌƒsƒXƒgƒ‹\n";
    }
};

class Zoro : public Pirate
{
public:
    void Attack() override
    {
        std::cout << "ŽOç¢ŠE\n";
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