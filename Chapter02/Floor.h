#pragma once
#include "ChildActor.h"
#include "Window.h"
#include "GridComponent.h"

class Floor :
    public ChildActor
{
public:
    Floor(Game* game, float x, float y, float w, float h);

    void UpdateActor(float deltaTime) override;

protected:

    GridComponent<Window>* mGrid;

};

