#include "GridComponent.h"
#include "Window.h"
#include "Floor.h"

template class GridComponent<Floor>;
template class GridComponent<Window>;

template <class G>
GridComponent<G>::GridComponent(Actor* owner, int e, float xP, float yP,
    bool isHorizontal, 
    int updateOrder)
    :Component(owner, updateOrder), numElements(e), isHorizontal(isHorizontal), xPadding(xP), yPadding(yP)
{
    Grid.resize(numElements);
    width = owner->GetWidth();
    height = owner->GetHeight();
    xPadding = xPadding * width;
    yPadding = yPadding * height;
    width -= 2 * xPadding;
    height -= 2 * yPadding;
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
        float firstX = xOwner - width / 2 + wElement / 2 + xPadding;

        for (int i = 0; i < numElements; i++) {
            float xElement = firstX + i*wElement;
            G* mElement = new G(game, xElement, yElement, wElement, hElement);
        }
    }

    else{

        float wElement = width;
        float hElement = height / numElements;
        float xElement = xOwner;
        float firstY = yOwner - height/ 2 + hElement / 2 + yPadding;

        for (int i = 0; i < numElements; i++) {
            float yElement = firstY + i * hElement;
            G* mElement = new G(game, xElement, yElement, wElement, hElement);
        }
    }
}