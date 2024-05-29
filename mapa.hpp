#ifndef mapa_h
#define mapa_h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;


class Fantasma;

class mapagrid {
public:
vector<vector<int>> grid;
vector<vector<int>> next;
int rows, cols;
int sizeX;
int sizeY;
int x,y;
Vector2i size;
mapagrid(int rows, int cols);



void update();
//void spawn(Fantasma &fantasmin);
void drawTo(RenderWindow &window); 
void click(int x, int y);
void mov(int p, Fantasma &rojo);

};

#endif