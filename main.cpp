#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(50);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Vector2f shapePosition = shape.getPosition();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            shapePosition.x -= 10;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            shapePosition.x += 10;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            shapePosition.y -= 10;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            shapePosition.y += 10;

        shape.setPosition(shapePosition);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }

    return 0;
}