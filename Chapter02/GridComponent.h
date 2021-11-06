#pragma once
#include "Component.h"
#include "vector"

template <class G>
class GridComponent :
    public Component
{
public:
    std::vector<bool> Grid;
    int numElements;
    float width;
    float height;
    float xOwner;
    float yOwner;
    float xPadding;
    float yPadding;
    bool isHorizontal; // True: horizontal / False: Vertical
    
    GridComponent(Actor* owner, int e, float xP, float yP, 
        bool isHorizontal = true, 
        int updateOrder = 100);

    void FillGrid();
    
};


