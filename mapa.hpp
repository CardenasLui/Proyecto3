#ifndef mapa_h
#define mapa_h
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;




class mapagrid {
private: 
vector<vector<int>> grid;
vector<vector<int>> next;
int rows, cols;
int sizeX;
int sizeY;
Vector2i size;
public:

mapagrid(int rows, int cols);



void update();
void drawTo(RenderWindow &window); 


};

#endif