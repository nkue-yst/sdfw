#include <sdfw.h>

using namespace sdfw;

int main()
{
    init();
    openWindow(1280, 720);

    constexpr int32_t THICKNESS = 5;

    while (System::update())
    {
        Point pos = Mouse::pos();

        Line(   0,   0, pos.x, pos.y, THICKNESS).draw(Color(255, 255, 128));
        Line(1280,   0, pos.x, pos.y, THICKNESS).draw(Color(255, 128, 128));
        Line(   0, 720, pos.x, pos.y, THICKNESS).draw(Color(128, 255, 128));
        Line(1280, 720, pos.x, pos.y, THICKNESS).draw(Color(128, 128, 255));
    }

    quit();
}
