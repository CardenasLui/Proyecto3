
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
    this->x=0;
    this->y=0;
    
}

void Fantasma::drawTo(RenderWindow &window){
    window.draw(this->fantasma);
}


void Fantasma::mover(vector<vector<int>> &grid,int p, int &cont){
    if(p==1 && cont==0){
        if(grid[13+x-1][13+y]==0){
            this->fantasma.setPosition(this->fantasma.getPosition().x-20,this->fantasma.getPosition().y);
            cont++;
            grid[13+x-1][13+y]==2;
            grid[13+x][13+y]==0;
            x--;

        }
    }
    if(p==2&& cont==0){
        if(grid[13+x+1][13+y]==0){
            this->fantasma.setPosition(this->fantasma.getPosition().x+20,this->fantasma.getPosition().y);
            cont++;
            grid[13+x+1][13+y]==2;
            grid[13+x][13+y]==0;
            x++;

        }
    }
    if(p==3&& cont==0){
        if(grid[13+x][13+y-1]==0){
            this->fantasma.setPosition(this->fantasma.getPosition().x,this->fantasma.getPosition().y-20);
            cont++;
            grid[13+x][13+y-1]==2;
            grid[13+x][13+y]==0;
            y--;

        }
    }
    if(p==4&& cont==0){
        if(grid[13+x][13+y+1]==0){
            this->fantasma.setPosition(this->fantasma.getPosition().x,this->fantasma.getPosition().y+20);
            cont++;
            grid[13+x][13+y+1]==2;
            grid[13+x][13+y]==0;
            y++;

        }
    }
    if(cont!=0){
        cont++;
    }
    if(cont==50){
        cont=0;
    }
}






