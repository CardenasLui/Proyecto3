#include <SFML/Graphics.hpp>
#include "mapa.hpp"
#include "fantasma.hpp"
using namespace sf;
int main() {
     // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(560, 620), "Pac-man 101");
    window.setFramerateLimit(60);
    mapagrid Mapagrid(32,28);
    Fantasma rojo(Vector2f{15.f,14.f});
    sf::Texture texture;
    if (!texture.loadFromFile("fondo.png"))
    {
        // Si carga falla, mostrar mensaje de error
        return EXIT_FAILURE;
    }


   // Crear sprite y asociarlo a la textura
    sf::Sprite sprite(texture);
    // Cargar PNG
        sprite.setColor(Color::White);
    // Bucle principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        Mapagrid.spawn(rojo);
         

        window.clear();
        window.draw(sprite);
        Mapagrid.drawTo(window);
        rojo.drawTo(window);
        window.display();

    }

    // // Crear círculo rojo
   
    // Bucle 
    // while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     Movimiento del fantasma con teclas flecha
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //         circle.move(-1, 0);
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //         circle.move(1, 0);
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //         circle.move(0, -1);
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //         circle.move(0, 1);

    //     Dibujar todo
    //     window.clear();
    //    Mapagrid.drawTo(window);
    //     window.draw(circle);
    //     window.display();
   // }
    

    return 0;
}