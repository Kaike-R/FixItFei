#pragma once

#include <vector>

#include "ChildSpriteComponent.h"

class BrokenSpriteComponent :
    public ChildSpriteComponent
{
public:
    BrokenSpriteComponent(class Actor* owner,
        int drawOrder = 100);

    void Update(float deltaTime) override;

    void SetBrokenTextures(const std::vector<SDL_Texture*>& textures);

    void Fix() { mHowBroken -= mHowBroken == 0 ? 0 : 1; }

private:
    std::vector<SDL_Texture*> mBrokenTextures;

    // [0..3] -> not broken to most broken
    int mHowBroken;
};
