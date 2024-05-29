#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Pacman{
    private:
    sf::Texture texture;
    

    public:
    int x,y;
    Sprite fantasma;
    Pacman(Vector2f position);
    void drawTo(RenderWindow &window);
 };