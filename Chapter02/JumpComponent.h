#pragma once
#include "Component.h"

class JumpComponent :
    public Component
{
public:
    JumpComponent(class Felix* owner, 
        float g, 
        int updateOrder = 100);
    ~JumpComponent();

    void Fall();

    void Jump();
    void EndJump() { mIsJumping = false; }

    void Update(float deltaTime) override;

    bool IsJumping() const { return mIsJumping; }

    // todo: fix dependency on Felix
    class Felix* GetFelix() const { return mFelix; }

private:
    class Felix* mFelix;
    
    bool mIsJumping;

    float mGravity;



};
