#pragma once
#include "ChildActor.h"
class Floor :
    public ChildActor
{
public:
    Floor(Game* game, float x, float y, float w, float h);

    void UpdateActor(float deltaTime) override;

protected:

};

