#include "AnimSpriteComponent.h"
#include "Felix.h"
#include "Game.h"

Felix::Felix(Game* game)
	:Actor(game, false)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
{
	mAsc = new AnimSpriteComponent(this);

	mAnimsWalk = {
		game->GetTexture("Assets/Character01.png"),
		game->GetTexture("Assets/Character02.png"),
		game->GetTexture("Assets/Character03.png"),
		game->GetTexture("Assets/Character04.png"),
		game->GetTexture("Assets/Character05.png"),
		game->GetTexture("Assets/Character06.png"),
	};

	mAnimsJump = {
		game->GetTexture("Assets/Character07.png"),
		game->GetTexture("Assets/Character08.png"),
		game->GetTexture("Assets/Character09.png"),
		game->GetTexture("Assets/Character10.png"),
		game->GetTexture("Assets/Character11.png"),
		game->GetTexture("Assets/Character12.png"),
		game->GetTexture("Assets/Character13.png"),
		game->GetTexture("Assets/Character14.png"),
		game->GetTexture("Assets/Character15.png"),
	};

	mAnimsFix = {
		game->GetTexture("Assets/Character16.png"),
		game->GetTexture("Assets/Character17.png"),
		game->GetTexture("Assets/Character18.png"),
	};

	mAsc->SetAnimTextures(mAnimsWalk);

	mWidth = mAsc->GetTexWidth();
	mHeight = mAsc->GetTexHeight();

	mIsFixing = false;
	mCoolDown = 0;
}

void Felix::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	if (mIsFixing)
	{
		mIsFixing = false;

		if (mCoolDown < 1)
		{
			mCoolDown = 10;

			//mFixer->Fix();
		}
		else mCoolDown -= 1;
	}
	else if (mCoolDown > 0) mCoolDown -= 1;

	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;

	float wWidth  = GetGame()->GetWindowWidth();
	float wHeight = GetGame()->GetWindowHeight();

	if (pos.x < GetWidth() / 2.0f)
	{
		pos.x = GetWidth() / 2.0f;
	}
	else if (pos.x > wWidth - GetWidth() / 2.0f)
	{
		pos.x = wWidth - GetWidth() / 2.0f;
	}

	if (pos.y < GetHeight() / 2.0f)
	{
		pos.y = GetHeight() / 2.0f;
	}
	else if (pos.y > wHeight - GetHeight() / 2.0f)
	{
		pos.y = wHeight - GetHeight() / 2.0f;
	}

	SetPosition(pos);
}

void Felix::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	
	// todo: account for gravity on jumps
	mDownSpeed = 0.0f;

	// left/ right
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
		mAsc->SetAnimTextures(mAnimsWalk);
	}
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
		mAsc->SetAnimTextures(mAnimsWalk);
	}

	// up/ down
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 250.0f;
		mAsc->SetAnimTextures(mAnimsJump);
	}
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 250.0f;
		mAsc->SetAnimTextures(mAnimsJump);
	}

	if (state[SDL_SCANCODE_P])
	{
		mIsFixing = true;
		// mFixer->Fix();
	}

	// Time warp
	if (state[SDL_SCANCODE_T])
	{
		GetGame()->SetTimeWarp(true);
	}
}
