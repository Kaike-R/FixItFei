#include "BGSpriteComponent.h"
#include "Game.h"
#include "Building.h"

Building::Building(Game* game, float x, float y,
	float w, float h)
	:ChildActor(game, x, y, w, h)
{
	auto bg = new BGSpriteComponent(this, 50);

	//set the screen size for the background to fit in
	bg->SetScreenSize(Vector2(mWidth, mHeight));

	//create a vector
	auto bgtexs = {
		GetGame()->GetTexture("Assets/PredioFundoPadrao.png")
	};

	//set this vector to the background component
	bg->SetBGTextures(bgtexs);
	bg->SetScrollSpeed(0.0f);

	mGrid = new GridComponent<Floor>(this, 4, 0.15, 0.01, 0.05, false);
}

void Building::UpdateActor(float deltaTime)
{

}
