#ifndef mapa_h
#define mapa_h
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;




class mapatile {
private: 
vector<vector<int>> grid;
vector<vector<int>> next;
int rows, cols;
int sizeX, sizeY;
Vector2i size;
public:
Vector2f pos;

};

#endif