#include <sdfw.h>
#include <random>
#include <string>

#define WIDTH 1280
#define HEIGHT 720

using namespace sdfw;

class Paddle
{
public:
    Paddle()
        : x(0)
        , y(HEIGHT / 2 - 100)
    {
    }

    void draw()
    {
        Line(this->x, this->y, this->x, this->y + 200, 10).draw();
    }

    uint32_t x, y;
};

class Ball
{
public:
    Ball()
        : x(WIDTH / 2)
        , y(HEIGHT / 2)
        , dx(2)
        , dy(2)
    {
    }

    void draw()
    {
        Circle(this->x, this->y, 10).draw();
    }

    void paddleReflection()
    {
        this->dx *= -1;
        se_reflection->play();
    }

    void wallReflection()
    {
        this->dy *= -1;
        se_reflection->play();
    }

    uint32_t x, y, dx, dy;
    Audio* se_reflection;
};

int main()
{
    init();
    openWindow(WIDTH, HEIGHT);
    Scene::setBackground(Color(0, 0, 0));

    std::random_device rnd;
    Paddle* player = new Paddle();
    Paddle* npc = new Paddle();
    Ball* ball = new Ball();

    uint32_t score_player = 0;
    uint32_t score_npc = 0;

    player->x = 0 + 100;
    npc->x = WIDTH - 100;
    ball->se_reflection = new Audio("sample_01.mp3");

    while (System::update())
    {
        // Score
        print(std::to_string(score_player) + " - " + std::to_string(score_npc));

        // Player's paddle movement
        player->y = Mouse::pos().y - 100;

        // NPC's paddle movement
        npc->y = ball->y - 100 + 80;

        // Update X (Judge goal)
        if (ball->x + ball->dx >= WIDTH)
        {
            score_player++;
            ball->x = WIDTH / 2;
            ball->y = HEIGHT / 2;
        }
        else if (ball->x + ball->dx <= 0)
        {
            score_npc++;
            ball->x = WIDTH / 2;
            ball->y = HEIGHT / 2;
        }
        else
        {
            ball->x += ball->dx;
        }

        // Update Y
        if (ball->y + ball->dy >= HEIGHT)
        {
            ball->wallReflection();
        }
        else
        {
            ball->y += ball->dy;
        }

        // Player's paddle reflection
        if (player->x <= ball->x - 5 && ball->x - 5 <= player->x + 5 && player->y <= ball->y && ball->y <= player->y + 200)
        {
            ball->paddleReflection();
        }
        
        // NPC's paddle reflection
        if (npc->x - 5 <= ball->x + 5 && ball->x + 5 <= npc->x + 5 && npc->y <= ball->y && ball->y <= npc->y + 200)
        {
            ball->paddleReflection();
        }

        ball->draw();
        player->draw();
        npc->draw();
    }

    delete player;
    delete npc;
    delete ball;
    quit();
}
