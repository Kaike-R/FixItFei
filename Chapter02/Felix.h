#pragma once
#include "Actor.h"
#include "AnimSpriteComponent.h"

class Felix :
    public Actor
{
public:
    Felix(class Game* game);

    void UpdateActor(float deltaTime) override;
    void ProcessKeyboard(const uint8_t* state);
    float GetRightSpeed() const { return mRightSpeed; }
    float GetDownSpeed() const { return mDownSpeed; }

private:
    float mRightSpeed;
    float mDownSpeed;

    bool mIsFixing;
    int mCoolDown;

    AnimSpriteComponent* mAsc;

    std::vector<SDL_Texture*> mAnimsWalk;
    std::vector<SDL_Texture*> mAnimsJump;
    std::vector<SDL_Texture*> mAnimsFix;

    // FixComponent* mFixer;
};

