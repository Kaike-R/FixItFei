#pragma once
#include "Component.h"
#include "vector"
#include "Floor.h"
#include "Window.h"

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
    bool isHorizontal; // True: horizontal / False: Vertical
    
    GridComponent(Actor* owner, int e, 
        bool isHorizontal = true, 
        int updateOrder = 100);

    void FillGrid();
    
};

template class GridComponent<Floor>;
template class GridComponent<Window>;
