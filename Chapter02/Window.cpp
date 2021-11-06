#include "BGSpriteComponent.h"
#include "GridComponent.h"
#include "Game.h"
#include "Window.h"

Window::Window(Game* game, float x, float y, 
	float w, float h)
	:ChildActor(game, x, y, w, h)
{
	auto bg = new BGSpriteComponent(this, 60);

	//set the screen size for the background to fit in
	bg->SetScreenSize(Vector2(mWidth, mHeight));

	//create a vector
	auto bgtexs = {
		GetGame()->GetTexture("Assets/Window01.png")
	};

	//set this vector to the background component
	bg->SetBGTextures(bgtexs);
	bg->SetScrollSpeed(0.0f);

}

void Window::UpdateActor(float deltaTime)
{

}
