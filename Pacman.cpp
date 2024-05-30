
#include <SFML/Graphics.hpp>
#include "pacman.hpp"
#include "mapa.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace sf;

Pacman::Pacman(Vector2f position){
     this->dir = 1;

    if (!texture.loadFromFile("PacmanP.png"))
    {
        std::cout<<"error"<<endl;
    }
    texture.setRepeated(true);
    this->pacman.setTexture(texture);
    this->pacman.setPosition(position);
    }

    void Pacman::drawTo(RenderWindow &window){
    window.draw(this->pacman);
    }

    
void Pacman::mover(vector<vector<int>> &grid, int &p, int &cont){

    if(p==1 ){
        cout<<"entra"<<endl;
        if(grid[13+x-1][11+y]==0){
            this->pacman.setPosition(this->pacman.getPosition().x-20,this->pacman.getPosition().y);
            cont++;
            
            grid[13+x-1][11+y]==2;
            grid[13+x][11+y]==0;
            x--;
           

        }else{
            p=rand()%3+1;
        }
    }
    if(p==2){
        cout<<"entra"<<endl;
        if(grid[13+x+1][11+y]==0){
            this->pacman.setPosition(this->pacman.getPosition().x+20,this->pacman.getPosition().y);
            cont++;

            grid[13+x+1][11+y]==2;
            grid[13+x][11+y]==0;
            x++;
           

        }else{
            p=rand()%3+1;
        }
        
    }
    if(p==3){
         cout<<"entra"<<endl;

        if(grid[13+x][11+y-1]==0){
            this->pacman.setPosition(this->pacman.getPosition().x,this->pacman.getPosition().y-20);
            cont++;

            grid[13+x][11+y-1]==2;
            grid[13+x][11+y]==0;
            y--;
           

        }else{
            p=rand()%3+1;
        }
    }
    if(p==4){
         cout<<"entra"<<endl;
        if(grid[13+x][11+y+1]==0){
            this->pacman.setPosition(this->pacman.getPosition().x,this->pacman.getPosition().y+20);
            cont++;

            grid[13+x][11+y+1]==2;
            grid[13+x][11+y]==0;
            y++;
           

        }else{
            p=rand()%3+1;
        }
    }
    
}