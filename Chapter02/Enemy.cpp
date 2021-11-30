#include "Enemy.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Enemy::Enemy(Game* game, bool timeWarp, float speed)
	:Projectile(game, timeWarp, speed)
{
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Pato1.png"),
		game->GetTexture("Assets/Pato2.png"),
	};

	asc->SetAnimTextures(anims);

	mWidth = asc->GetTexWidth();
	mHeight = asc->GetTexHeight();
}

void Enemy::UpdateActor(float deltaTime)
{
	Projectile::UpdateActor(deltaTime);
}
