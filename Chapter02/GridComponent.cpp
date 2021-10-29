#include "GridComponent.h"

template <class G>
GridComponent<G>::GridComponent(int e, float w, float h, bool flag, float xActorCord, float yActorCord)
    : numElements(e), width(w), height(h), isHorizontal(flag), xActorCord(xActorCord), yActorCord(yActorCord)
{
    Grid.resize(numElements);
}

template <class G>
void GridComponent<G>::FillGrid()
{
    if (isHorizontal) {
        float wElement = width / numElements;
        float hElement = height;
        float yElement = yActorCord;
        float firstX = xActorCord - width / 2 + wElement / 2;

        for (int i = 0; i < numElement; i++) {
            float xElement = firstX + i*wElement;
            G* mElement = new G(xElement, yElement, wElement, hElement);

        }
    }

    else{

        float wElement = width;
        float hElement = height / numElements;
        float xElement = xActorCord;
        float firstY = yActorCord - height/ 2 + hElement / 2;

        for (int i = 0; i < numElement; i++) {
            float yElement = firstY + i * hElement;
            G* mElement = new G(xElement, yElement, wElement, hElement);

        }

    }

}