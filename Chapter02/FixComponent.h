#pragma once

#include "BrokenSpriteComponent.h"
#include "Component.h"
#include "Felix.h"

class FixComponent :
    public Component
{
public:
    FixComponent(Felix* owner,
        int updateOrder = 100);

    void Update(float deltaTime) override;

    void Fix(BrokenSpriteComponent* window);

private:


};

