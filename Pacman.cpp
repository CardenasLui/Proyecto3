#include <SFML/Graphics.hpp>
#include "pacman.hpp"
#include "mapa.hpp"
#include <iostream>
Pacman::Pacman(Vector2f position){
    if (!texture.loadFromFile("PacmanP.png"))
    {
        std::cout<<"error"<<endl;
    }
    texture.setRepeated(true);
    this->fantasma.setTexture(texture);
    this->fantasma.setPosition(position);
    }
    void Fantasma::drawTo(RenderWindow &window){
    window.draw(this->fantasma);
}