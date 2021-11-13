#pragma once
#include "Actor.h"
#include "AnimSpriteComponent.h"
#include "JumpComponent.h"

class Felix :
    public Actor
{
public:
    enum class AnimState
    {
        Walking, 
        Jumping, 
        Fixing
    };

    Felix(class Game* game);

    void UpdateActor(float deltaTime) override;
    void ProcessKeyboard(const uint8_t* state);

    float GetDownSpeed() const { return mDownSpeed; }
    void SetDownSpeed(float ds) { mDownSpeed = ds; }

    float GetRightSpeed() const { return mRightSpeed; }
    void SetRightSpeed(float rs) { mRightSpeed = rs; }
    
private:
    float mRightSpeed;
    float mDownSpeed;

    bool mIsFixing;
    //bool mIsJumping;
    int mCoolDown;

    JumpComponent* mJumper;
    
    AnimState mAnimState;

    AnimSpriteComponent* mAsc;

    std::vector<SDL_Texture*> mAnimsWalk;
    std::vector<SDL_Texture*> mAnimsJump;
    std::vector<SDL_Texture*> mAnimsFix;

    // FixComponent* mFixer;
};

