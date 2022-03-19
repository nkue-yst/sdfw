#include <sdfw.h>

#include <chrono>
#include <string>
#include <thread>

#define delay(ms) std::this_thread::sleep_for(std::chrono::milliseconds(##ms));

constexpr uint32_t DURATION = 30000;

using namespace sdfw;

int main()
{
    init();

    int32_t win = openWindow(1280, 720);

    std::string str;
    while (System::update())
    {
        str = "X: " + std::to_string(Mouse::pos().x) + ", Y: " + std::to_string(Mouse::pos().y);
        print(str);

        Line(1280, 720, Mouse::pos().x, Mouse::pos().y, 5).draw();

        if (Time::getMillisec() > DURATION)
            break;
    }

    delay(1000);

    closeWindow(win);
    quit();
}
