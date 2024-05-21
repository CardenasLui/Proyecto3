#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(560, 620), "Círculo Rojo");
    window.setFramerateLimit(60);

    // Crear círculo rojo
    sf::CircleShape circle(30); // Radio: 30 píxeles
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(400, 300); // Posición inicial del círculo en centro

    // Bucle 
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movimiento del fantasma con teclas flecha
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            circle.move(-1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            circle.move(1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            circle.move(0, -1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            circle.move(0, 1);

        // Dibujar todo
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}