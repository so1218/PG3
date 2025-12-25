#include <iostream>

template <typename T1, typename T2>
class MinClass
{
public:
    auto Min(T1 a, T2 b)
    {
        return (a < b) ? a : b;
    }
};

int main()
{
    MinClass<int, int> num1;
    std::cout << num1.Min(10, 20) << std::endl;

    MinClass<int, float> num2;
    std::cout << num2.Min(10, 5.5f) << std::endl;

    MinClass<int, double> num3;
    std::cout << num3.Min(10, 8.8) << std::endl;

    MinClass<float, float> num4;
    std::cout << num4.Min(3.3f, 4.4f) << std::endl;

    MinClass<float, double> num5;
    std::cout << num5.Min(6.6f, 2.2) << std::endl;

    MinClass<double, double> num6;
    std::cout << num6.Min(9.9, 1.1) << std::endl;

    return 0;
}