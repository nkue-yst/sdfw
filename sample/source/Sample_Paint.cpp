#include <sdfw.h>

#include <vector>

using namespace sdfw;

int main()
{
    init();
    openWindow(600, 600);
    Scene::setBackground(Color(255, 255, 255));

    std::vector<Circle> drawn_point;

    while (System::update())
    {
        if (Mouse::pressed(LEFT))
        {
            drawn_point.push_back(Circle(Mouse::pos().x, Mouse::pos().y, 15));
        }
        else if (Mouse::pressed(RIGHT))
        {
            drawn_point.clear();
        }

        for (Circle pt : drawn_point)
        {
            pt.draw(Color(0, 0, 0));
        }
    }

    quit();
}
