#include "cInvader2.h"

cInvader2::cInvader2(sf::Vector2u startingPosition, sf::Vector2u windowSize)
{
	mWindowSize = windowSize;
	mHPMax = 1;
	mHP = mHPMax;
	mMovementSpeed = mWindowSize.x / 3000.f;
	if (!mTexture.loadFromFile("../img/invader2.png"))
	{
		std::cout << "Nie udalo sie zaladowac grafiki najezdzcy" << std::endl;
	}
	mInvaderShape.setSize(sf::Vector2f((static_cast<float>(mWindowSize.x / 10)), static_cast<float>(mWindowSize.y / 18)));
	mInvaderShape.setTexture(&mTexture);
	mInvaderShape.setOrigin(mInvaderShape.getSize().x / 2, mInvaderShape.getSize().y / 2);
	mInvaderShape.setPosition(static_cast<float>(startingPosition.x), static_cast<float>(startingPosition.y));
	//std::cout << "Invader2 constructor " << mStartPosition.x << " " << mStartPosition.y << std::endl;
}

cInvader2::~cInvader2()
{
	//std::cout << "invader2 destructor" << std::endl;
}

void cInvader2::Update()
{
	cInvader2::mShootTimer = cInvader2::mClock.getElapsedTime();
	if (mHP == 0)//przesuwanie najezdzcy poza mape, aby nie mogl skrzywdzic bohatera, a jednoczesnie jego pociski mogly doleciec
	{
		mInvaderShape.move(static_cast<float>(mWindowSize.x), static_cast<float>(mWindowSize.y));
	}
	if (mInvaderShape.getPosition().x <= -mInvaderShape.getSize().x)
	{
		mMovementSpeed *= -1;
	}
	mInvaderShape.move(-mMovementSpeed, 0.0f);
	if (mInvaderShape.getPosition().x <= mWindowSize.x)
	{
		mIsInitialized = true;
	}
	if (mInvaderShape.getPosition().x >= mWindowSize.x + mInvaderShape.getSize().x and mIsInitialized)
	{
		mMovementSpeed *= -1;
	}
	if (mShootTimer.asSeconds() >= 0.5f and mShootTimer.asMicroseconds() % 500 == 0)
	{
		cInvader2::mEnemyMissileVector.push_back(new cEnemyMissile(mInvaderShape.getPosition()));
		mClock.restart();
	}
}
