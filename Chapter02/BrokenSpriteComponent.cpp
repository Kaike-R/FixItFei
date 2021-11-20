#include "BrokenSpriteComponent.h"

BrokenSpriteComponent::BrokenSpriteComponent(class Actor* owner,
	int drawOrder)
	:ChildSpriteComponent(owner, drawOrder)
	,mHowBroken(0)
{
}

void BrokenSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	SetTexture(mBrokenTextures[mHowBroken]);
}

void BrokenSpriteComponent::SetBrokenTextures(const std::vector<SDL_Texture*>& textures)
{
	mBrokenTextures = textures;

	// for testing only
	mHowBroken = mBrokenTextures.size() - 1;
	SetTexture(mBrokenTextures[mHowBroken]);
}
