#include "Actor.h"
#include "Felix.h"
#include "JumpComponent.h"

JumpComponent::JumpComponent(Felix* owner, 
	float g,
	int updateOrder)
	:Component(owner, updateOrder), 
	mGravity(g), 
	mIsJumping(false), 
	mFelix(owner)
{
	
}

JumpComponent::~JumpComponent()
{
	
}

void JumpComponent::Jump() 
{
	if (!mIsJumping)
	{
		Felix* felix = GetFelix();

		felix->SetDownSpeed(-3.5 * felix->GetHeight());

		mIsJumping = true;
	}
}

void JumpComponent::Update(float deltaTime) 
{
	if (mIsJumping)
	{
		Felix* felix = GetFelix();
		float downSpeed = felix->GetDownSpeed();

		felix->SetDownSpeed(downSpeed + mGravity * deltaTime);
	}
}
