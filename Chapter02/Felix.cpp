#include "AnimSpriteComponent.h"
#include "Felix.h"
#include "Game.h"

Felix::Felix(Game* game)
	:Actor(game, false)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
	,mAnimState(AnimState::Walking)
	,mFallWindow(nullptr)
	,mCurrentWindow(nullptr)
{
	mAsc = new AnimSpriteComponent(this);

	mAnimsWalk = {
		game->GetTexture("Assets/Felix1.png"),
		game->GetTexture("Assets/Felix2.png"),
		game->GetTexture("Assets/Felix3.png"),
		game->GetTexture("Assets/Felix4.png"),

	};

	mAnimsJump = {
		game->GetTexture("Assets/Felix8.png"),
	};

	mAnimsFix = {
		game->GetTexture("Assets/Felix10.png"),
	};

	mAsc->SetAnimTextures(mAnimsWalk);

	mWidth = mAsc->GetTexWidth();
	mHeight = mAsc->GetTexHeight();

	mJumper = new JumpComponent(this, 5 * mHeight);

	mIsFixing = false;
	mCoolDown = 0;
}

void Felix::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	if (!mJumper->IsJumping() &&
		mAnimState == AnimState::Jumping)
	{
		mAnimState = AnimState::Walking;
	}

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

	auto colliders = GetGame()->GetColliders();

	bool collidedAny = false;

	// stop at each floor
	for (CollideComponent* c : colliders)
	{
		if (c != mFallWindow)
		{
			if (c->Collide(this) && mDownSpeed >= 0)
			{
				Vector2 cPos = c->GetOwner()->GetPosition();
				float cHeight = c->GetOwner()->GetHeight();

				float cBottom = cPos.y + cHeight / 2.0f;

				if ((pos.y < cBottom) &&
					(pos.y > cBottom - GetHeight() / 2.0f))
				{
					pos.y = cBottom - GetHeight() / 2.0f;

					collidedAny = true;
					mDownSpeed = 0;

					mJumper->EndFall();
					mJumper->EndJump();

					mCurrentWindow = c;
					mFallWindow = nullptr;
				}
			}
		}

		if (!collidedAny)
		{
			mCurrentWindow = nullptr;
			mJumper->Fall();
		}
	}

	if (pos.x < GetWidth() / 2.0f)
	{
		pos.x = GetWidth() / 2.0f;
	}
	else if (pos.x > wWidth - GetWidth() / 2.0f)
	{
		pos.x = wWidth - GetWidth() / 2.0f;
	}

	/*if (pos.y < GetHeight() / 2.0f)
	{
		pos.y = GetHeight() / 2.0f;
	}
	else */if (pos.y > wHeight - GetHeight() / 2.0f)
	{
		pos.y = wHeight - GetHeight() / 2.0f;

		mJumper->EndFall();
		mJumper->EndJump();
	}

	SetPosition(pos);
}

void Felix::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	
	// todo: account for gravity on jumps
	//mDownSpeed = 0.0f;

	// left/ right
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;

		if (!mJumper->IsJumping() && 
			mAnimState != AnimState::Walking)
		{
			mAsc->SetAnimTextures(mAnimsWalk);
			mAnimState = AnimState::Walking;
		}
	}
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;

		if (!mJumper->IsJumping() && 
			mAnimState != AnimState::Walking)
		{
			mAsc->SetAnimTextures(mAnimsWalk);
			mAnimState = AnimState::Walking;
		}
	}

	// up/ down
	if (state[SDL_SCANCODE_W])
	{
		mJumper->Jump();

		//mDownSpeed -= 250.0f;
		
		if (mAnimState != AnimState::Jumping)
		{
			//mAsc->SetAnimTextures(mAnimsJump);
			mAnimState = AnimState::Jumping;
		}
	}
	if (state[SDL_SCANCODE_S])
	{
		// todo: fall
		mJumper->Fall();
		// or squat

		//mDownSpeed += 250.0f;

		if (mAnimState != AnimState::Jumping)
		{
			//mAsc->SetAnimTextures(mAnimsJump);
			mAnimState = AnimState::Jumping;
		}
	}

	if (state[SDL_SCANCODE_P])
	{
		//mIsFixing = true;
		//mFixer->Fix();

		if (mAnimState != AnimState::Fixing)
		{
			mAsc->SetAnimTextures(mAnimsFix);
			mAnimState = AnimState::Fixing;
		}
	}

	// Time warp
	if (state[SDL_SCANCODE_T])
	{
		GetGame()->SetTimeWarp(true);
	}
}
