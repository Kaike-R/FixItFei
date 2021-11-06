#pragma once
#include "ChildActor.h"
class Window :
    public ChildActor
{
public:
    Window(Game* game, float x, float y, float w, float h);

    void UpdateActor(float deltaTime) override;

protected:
    bool isBroken = false;
    

};

