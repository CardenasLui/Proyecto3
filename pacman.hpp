#ifndef pacman_h
#define pacman_h
#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Pacman{
    private:
    sf::Texture texture;
    public:
    int x,y;
    int dir;
    Sprite pacman;
    Pacman(Vector2f position);
    void drawTo(RenderWindow &window);
    void mover(vector<vector<int>> &grid, int&a, int&cont);
 };
 #endif 