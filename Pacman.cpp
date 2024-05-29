
#include <SFML/Graphics.hpp>
#include "pacman.hpp"
#include "mapa.hpp"
#include <iostream>
using namespace std;
using namespace sf;

Pacman::Pacman(Vector2f position){
     //this->dir = rand()%3 +1;
    
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
    /*
    void Pacman::UpdatePac(vector<vector<int>> grid){
        // para dir 1=arriba 2=abajo 3=derecha 4=izquierda
            if (dir==1){
            if (grid[x][y-1] == 0){
                grid[x][y-1] = 3;
                grid[x][y] = 0;
                this->pacman.setPosition(pacman.getPosition().x, pacman.getPosition().y-20);
            }else{
                if (grid[x+1][y] == 0 && grid[x-1][y] == 0){
                this->dir = rand()%2+3;
                if (dir=3){
                    grid[x+1][y] = 3;
                    grid[x][y] = 0;
                    this->pacman.setPosition(pacman.getPosition().x+20, pacman.getPosition().y);
                }
                if (dir=4){
                    grid[x-1][y] = 3;
                    grid[x][y] = 0;
                    this->pacman.setPosition(pacman.getPosition().x-20, pacman.getPosition().y);
                }
                }else{
                    if (grid[x+1][y] == 0){
                        dir=3;
                        grid[x+1][y] = 3;
                        grid[x][y] = 0;
                        this->pacman.setPosition(pacman.getPosition().x+20, pacman.getPosition().y);
                    }
                    if (grid[x-1][y] == 0){
                        dir=4;
                        grid[x-1][y] = 3;
                        grid[x][y] = 0;
                        this->pacman.setPosition(pacman.getPosition().x-20, pacman.getPosition().y);
                    }
                }
            }
            }
    }*/