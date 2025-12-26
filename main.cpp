#include <iostream>
#include <thread> 

void PrintThread(const char* thread)
{
    std::cout << thread << std::endl;
}

int main()
{
    std::thread thread1(PrintThread, "thread1");
    thread1.join();

    std::thread thread2(PrintThread, "thread2");
    thread2.join();

    std::thread thread3(PrintThread, "thread3");
    thread3.join();

    return 0;
}