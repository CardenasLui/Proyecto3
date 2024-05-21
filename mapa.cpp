#include "mapa.hpp"

mapagrid::mapagrid(int rows, int cols)
{
    this->rows = rows; 
    this->cols = cols;
    this->sizeX=25;
    this->sizeY=25;

    for (int i = 0; i < rows; i++) 
    {
        this->grid.push_back({});
        for (int j = 0; j < cols; j++) 
        {
            this->grid[i].push_back(0); 
        }
    }

     this->next = vector<vector<int>>(rows, vector<int>(cols, 0)); // 
}