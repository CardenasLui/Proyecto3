
#include <SFML/Graphics.hpp>
#include "mapa.hpp"
#include "fantasma.hpp"
#include "Pacman.hpp"
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;
int main() {
     // Crear la ventana
     int a=rand()%4+1;
    sf::RenderWindow window(sf::VideoMode(560, 620), "Pac-man 101");
    window.setFramerateLimit(60);
    mapagrid Mapagrid(32,28);
    sf::CircleShape circle(7); // Radio: 30 píxeles1
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(400, 300); // Posición inicial del círculo en centro
    // Cargar PNG
    Fantasma rojo(Vector2f{15.f,14.f});
    Pacman amarillo(Vector2f{15.f,14.f});
    sf::Texture texture;
    if (!texture.loadFromFile("fondo.png"))
    {
        // Si carga falla, mostrar mensaje de error
        return EXIT_FAILURE;
    }
    int p=0;
    //Mapagrid.spawn(&rojo);
        rojo.fantasma.setPosition(260,340);
        //Mapagrid.spawn(&amarillo);
        amarillo.pacman.setPosition(260,220);
   


  sf::Clock clock;

//     // Crear una fuente para mostrar el tiempo
  sf::Font font;
   if (!font.loadFromFile("ChillPixels-Matrix.otf")) {
      std::cerr << "Error al cargar la fuente." << std::endl;
     return -1;
     }

//     // Crear un texto para mostrar el tiempo
  sf::Text text;
  text.setFont(font);
 text.setCharacterSize(20);
 text.setFillColor(sf::Color::Blue);

  text.setPosition(226.f, 270.f); //posicion

   
    int coolddown=0;
    int cdfantasma=0;
const int totalTime = 60; // Tiempo total del temporizador en segundos
    int remainingTime = totalTime;


    // Bucle principal de la aplicación
    

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
             if(event.type==Event::KeyPressed){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                     p=1;
                    cout<<"left"<<endl;
                    coolddown++;
                }
                   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    p=2;
                    cout<<"right"<<endl;
                    coolddown++;
                }
                    
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    p=3;
                    cout<<"up"<<endl;
                    coolddown++;
                }
                    
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    p=4;
                    cout<<"down"<<endl;
                    coolddown++;
                }
                cout<<p<<endl;
                    
             }
            
            

        }
        //Mapagrid.spawn(&rojo);
            rojo.mover(Mapagrid.grid,p, coolddown);
            amarillo.mover(Mapagrid.grid,a, cdfantasma);
            rojo.update(Mapagrid.grid, amarillo, totalTime);
            Mapagrid.drawTo(window);
            window.draw(sprite);
            
            // rojo.update(p);
            rojo.drawTo(window);
            amarillo.drawTo(window);
            window.draw(text);
            window.display();
            window.clear();
           // Movimiento del fantasma con teclas flecha
        
        // Obtener el tiempo transcurrido
        sf::Time elapsed = clock.getElapsedTime();
        int seconds = totalTime - elapsed.asSeconds();
        if (seconds != remainingTime) {
            remainingTime = seconds;
            // Actualizar el texto
            std::ostringstream ss;
            ss << "Tiempo: " << remainingTime;
            text.setString(ss.str());
        }
        // Convertir el tiempo transcurrido a segundos y actualizar el texto
       if (seconds <= 0) {
            return 0;
        }

        // Calcular el tamaño del círculo basado en el tiempo transcurrido
        
       


        // Dibujar el círculo y el texto
    

        

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