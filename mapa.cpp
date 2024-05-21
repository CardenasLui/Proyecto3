#include "mapa.hpp"

mapagrid::mapagrid(int rows, int cols)
{
    for (int i = 0; i < rows; i++) // esto es para llenar la cuaf¿dricula con 0
    {
        this->grid.push_back({});
        for (int j = 0; j < cols; j++) // a mi vector de vectores que crea el grid le estoy pasando un vector vacio para crear las filas
        {
            this->grid[i].push_back(rand() % 2); // ya que ya creaste la primer fila entra a este for para ahora crear las columnas en la fila usando un vector vacio o sea (un cuadrito vacio para meter algo)
        }
    }
}

void mapagrid::drawTo(RenderWindow &window)
{

    for (int i = 0; i < rows; i++) // esto es para llenar la cuaf¿dricula con 0
    {

        for (int j = 0; j < cols; j++) // a mi vector de vectores que crea el grid le estoy pasando un vector vacio para crear las filas
        {
            RectangleShape cuadrado(Vector2f(this->sizeX, this->sizeY));
            cuadrado.setOutlineThickness(1);
            cuadrado.setOutlineColor(Color::White);
            cuadrado.setPosition(Vector2f(j * this->sizeX, i * this->sizeY));
            if (grid[j][i] == 0)

                cuadrado.setFillColor(Color(77, 66, 110));
            if (grid[j][i] == 0)

                cuadrado.setFillColor(Color::Magenta);

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
    this->grid = this->next;
}
