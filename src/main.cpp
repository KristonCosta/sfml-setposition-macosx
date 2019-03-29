#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/System/Clock.hpp>

class SFMLBug
{
    const int WIDTH = 1280;
    const int HEIGHT = 800;
    const uint64_t tick_rate = 100;
    sf::Clock clock;
    sf::Window window;
    uint64_t m_dt;
    uint64_t m_prev;
    uint64_t m_curr;

  public:
    SFMLBug()
    {
        window.create(
            sf::VideoMode(WIDTH, HEIGHT),
            "SFMLBug",
            sf::Style::Default);
        m_dt = m_prev = m_curr = 0;
    }

    static void print_vector2i(std::string str, sf::Vector2i vec)
    {
        std::cout << str << vec.x << "," << vec.y << std::endl;
    }

    int loop()
    {
        bool exitMainLoop = false;
        sf::Event event;
        while (!exitMainLoop)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                {
                    exitMainLoop = true;
                }
            }
            m_curr = clock.getElapsedTime().asMilliseconds();
            m_dt += m_curr - m_prev;
            m_prev = m_curr;
            if (m_dt > tick_rate)
            {
                m_dt -= tick_rate;
                print_vector2i("Previous time: ", sf::Mouse::getPosition(window));
                sf::Mouse::setPosition(sf::Vector2i(10, 10), window);
                print_vector2i("Updated position: ", sf::Mouse::getPosition(window));
            }
        }
        window.close();
        return 0;
    }
};

int main(int argc, char **argv)
{
    SFMLBug bug;
    return bug.loop();
}