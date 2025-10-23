#include <SFML/Graphics.hpp>
#include "game/Ship.h"
#include "Constants.h"
#include "game/Asteroid.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Asteroids");
    window.setFramerateLimit(144);
    sf::Clock clock;
    Ship player;
    Asteroid asteroid(Asteroid::Size(0), 200, 200);
    

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds(); //delsta time
        sf::Vector2u windowSize = window.getSize();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }
        window.clear();
        player.update(dt,windowSize);
        player.draw(window);
        asteroid.draw(window);
        window.display();
        
    }
}
