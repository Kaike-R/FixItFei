#include "Floor.h"
#include "Window.h"
#include "GridComponent.h"


Floor::Floor(Game* game, float x, float y, float w, float h)
	:ChildActor(game, x, y, w, h)
{
	mGrid = new GridComponent<Window>(this, 5, 0.0, 0.01, 0.05, true, 70);
}

void Floor::UpdateActor(float deltaTime)
{

}
