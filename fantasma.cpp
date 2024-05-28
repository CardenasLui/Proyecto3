#include <SFML/Graphics.hpp>
#include "fantasma.hpp"
#include "mapa.hpp"
#include <iostream>

Fantasma::Fantasma(Vector2f position){
    if (!texture.loadFromFile("fantasmaP.png"))
    {
        std::cout<<"error"<<endl;
    }
    texture.setRepeated(true);
    this->fantasma.setTexture(texture);
    this->fantasma.setPosition(position);
    //this->fantasma.setScale(1.5,1.5);
    
}

void Fantasma::drawTo(RenderWindow &window){
    window.draw(this->fantasma);
}






