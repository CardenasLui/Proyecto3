#include <SFML/Graphics.hpp>
using namespace sf;
class Fantasma{
    private:
    sf::Texture texture;
    Sprite fantasma;

    public:
    Fantasma(Vector2f position);
    void drawTo(RenderWindow &window);
    
 };