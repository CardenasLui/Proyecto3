#pragma once
#include <SFML/Graphics.hpp>
#include "pacman.hpp"
using namespace std;
using namespace sf;


class Fantasma{
    private:
    sf::Texture texture;
    public:
    int x,y;
    Sprite fantasma;
    Fantasma(Vector2f position);
    void drawTo(RenderWindow &window);
    void mover(vector<vector<int>>&grid,int p, int &cont);
    void update(vector<vector<int>>&grid,Pacman &amarillo, const int&totalTime);
 };

        //     Movimiento del fantasma con teclas flecha
    // void handleInput() {
    //     if (Keyboard::isKeyPressed(Keyboard::Left))
    //         move(Vector2f(-1, 0));
    //     if (Keyboard::isKeyPressed(Keyboard::Right))
    //         move(Vector2f(1, 0));
    //     if (Keyboard::isKeyPressed(Keyboard::Up))
    //         move(Vector2f(0, -1));
    //     if (Keyboard::isKeyPressed(Keyboard::Down))
    //         move(Vector2f(0, 1));
    // }


       