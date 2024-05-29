
#include "mapa.hpp"
#include "fantasma.hpp"
#include "Pacman.cpp"

mapagrid::mapagrid(int rows, int cols)
{
    this->sizeX = 20;
    this->sizeY = 20;
    this->rows = rows;
    this->cols = cols;

    this->grid = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1},
                   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,  0, 1}, 
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0,  0, 1},
                   {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,  0, 1},
                   {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,  0, 1},
                   {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1,  0, 1},
                   {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1,  0, 1},
                   {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,  0, 1},
                   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0,  0, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1},
                   };
}

void mapagrid::drawTo(RenderWindow &window)
{

    for (int i = 0; i < rows; i++) // esto es para llenar la cuaf¿dricula con 0
    {

        for (int j = 0; j < cols; j++) // a mi vector de vectores que crea el grid le estoy pasando un vector vacio para crear las filas
        {
            RectangleShape cuadrado(Vector2f(this->sizeX, this->sizeY));
            cuadrado.setOutlineThickness(0.5);
            cuadrado.setOutlineColor(Color::White);
            cuadrado.setPosition(Vector2f(j * this->sizeX, i * this->sizeY));
            if (grid[j][i] == 0)
                cuadrado.setFillColor(Color::Transparent);
            else
                cuadrado.setFillColor(Color::White);

            window.draw(cuadrado);
        }
    }
}

void mapagrid::click(int x, int y)
{
    int indexX = x / this->sizeX;
    int indexY = y / this->sizeY;
    grid[indexX][indexY] = (grid[indexX][indexY] + 1) % 2;

    // if(grid[indexX][indexY]==0){
    // grid[indexX][indexY]= 1;
    //  }else{
    // grid[indexX][indexY]==0;
    // }
}

void mapagrid::update()
{
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
    for (int i = 0; i < this->rows; i++) // este for esta revisando cada una de las celdas
    {

        for (int j = 0; j < this->cols; j++)
        {

            if (this->grid[i][j] == 1)
            {

                if (j == this->cols - 1)
                {
                    this->next[i][j] = 1;
                }
                else
                {

                    if (this->grid[i][j + 1] == 0)
                    {
                        this->next[i][j] = 0;
                        this->next[i][j + 1] = 1;
                    }
                    else
                    {
                        this->next[i][j] = 1;
                    }
                }
            }
        }
    }
}
   //grid[Fantasma.x][Fantasma.y]=2;


/*
   void mapagrid::spawn(Pacman &Pacman){
    Pacman.pacman.setPosition(260,230);
    };
void mapagrid::spawn(Fantasma &Fantasma){
    Fantasma.fantasma.setPosition(260,340);
};*/

void mapagrid::mov(int p, Fantasma &rojo){
    Vector2f pos = Vector2f(rojo.x,rojo.y);
    int indexX = pos.x/sizeX;
    int indexY = pos.y/sizeY;

    int posGridX = rojo.fantasma.getPosition().x/32;
    int posGridY = rojo.fantasma.getPosition().y/28;//Obtiene la posición del 2 en el grid en base al sprite

      if(indexX,indexY==0){
         if(p==1){
                 this->grid[posGridX+this->x-1][posGridY+this->y]=2;
                 this->grid[posGridX+this->x][posGridY+this->y]=0;
                 rojo.fantasma.setPosition(rojo.fantasma.getPosition().x-20, rojo.fantasma.getPosition().y);
            }
            if(p==2){
                 this->grid[13+this->x+1][13+this->y]=2;
                 this->grid[13+this->x][13+this->y]=0;
                 rojo.fantasma.setPosition(rojo.fantasma.getPosition().x+20, rojo.fantasma.getPosition().y);   
            }
            if(p==3){
                 this->grid[13+this->y-1][13+this->x]=2;
                 this->grid[13+this->y][13+this->x]=0;
                 rojo.fantasma.setPosition(rojo.fantasma.getPosition().x, rojo.fantasma.getPosition().y-20);   
            }
            if(p==4){
                 this->grid[13+this->y+1][13+this->x]=2;
                 this->grid[13+this->y][13+this->x]=0;
                 rojo.fantasma.setPosition(rojo.fantasma.getPosition().x, rojo.fantasma.getPosition().y+20); 
            }
        }
    this->grid = this->next;
};


