#pragma once
#include "Component.h"
#include "vector"
#include "Andar.h"


template <class G>
class GridComponent :
    public Component
{
public:
    std::vector<bool> Grid;
    int numElements;
    float width;
    float height;
    float xActorCord;
    float yActorCord;
    bool isHorizontal; // True: horizontal / False: Vertical

    
    GridComponent(int e, float w, float h, bool flag, float xActorCord, float yActorCord);
    void FillGrid();
    
};


template class GridComponent<Andar>;
template class GridComponent<Janela>;



