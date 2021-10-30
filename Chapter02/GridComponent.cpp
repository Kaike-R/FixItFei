#include "GridComponent.h"

template <class G>
GridComponent<G>::GridComponent(Actor* owner, int e, 
    bool isHorizontal, 
    int updateOrder)
    :Component(owner, updateOrder), numElements(e), isHorizontal(isHorizontal)
{
    Grid.resize(numElements);
    width = owner->GetWidth();
    height = owner->GetHeight();
    Vector2 ownerPos = owner->GetPosition();
    xOwner = ownerPos.x;
    yOwner = ownerPos.y;

    FillGrid();
}

template <class G>
void GridComponent<G>::FillGrid()
{
    Game* game = mOwner->GetGame();

    if (isHorizontal) {
        float wElement = width / numElements;
        float hElement = height;
        float yElement = yOwner;
        float firstX = xOwner - width / 2 + wElement / 2;

        for (int i = 0; i < numElements; i++) {
            float xElement = firstX + i*wElement;
            G* mElement = new G(game, xElement, yElement, wElement, hElement);
        }
    }

    else{

        float wElement = width;
        float hElement = height / numElements;
        float xElement = xOwner;
        float firstY = yOwner - height/ 2 + hElement / 2;

        for (int i = 0; i < numElements; i++) {
            float yElement = firstY + i * hElement;
            G* mElement = new G(game, xElement, yElement, wElement, hElement);
        }
    }
}