#include <iostream>
#include <pigpio.h>
#include "MyClass.h"
#include "B.h"


class A
{
    public:
    void Print()
    {
        std::cout << "A" << std::endl;
    }

};


int main()
{
    std::cout <<"Hello Robert" << std::endl;

    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialisation failed." << std::endl;
        return 1;
    }

    int gpio_pin = 17; // GPIO17
    gpioSetMode(gpio_pin, PI_OUTPUT);

    for (int i = 0; i < 10; ++i) {
        gpioWrite(gpio_pin, 1); // LED on
        time_sleep(1);           // wait 1 second
        gpioWrite(gpio_pin, 0); // LED off
        time_sleep(1);           // wait 1 second
    }

    gpioTerminate();

    A a;
    a.Print();

    B b;
    b.Print();
    MyClass my;
    my.printMyName();


    return 0;
}