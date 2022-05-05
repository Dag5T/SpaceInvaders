#include "cInvader1.h"

cInvader1::cInvader1(sf::Vector2u startingPosiiton, sf::Vector2u windowSize)
{
	mWindowSize = windowSize;
	mHPMax = 1;
	mHP = mHPMax;
	mMovementSpeed = mWindowSize.x / (mWindowSize.x * 25.f);
	if (!mTexture.loadFromFile("../img/invader1.png"))
	{
		std::cout << "Nie udalo sie zaladowac grafiki najezdzcy" << std::endl;
	}
	mInvaderShape.setSize(sf::Vector2f((static_cast<float>(mWindowSize.x / 10)), static_cast<float>(mWindowSize.y / 18)));
	mInvaderShape.setTexture(&mTexture);
	mInvaderShape.setOrigin(mInvaderShape.getSize().x / 2, mInvaderShape.getSize().y / 2);
	mInvaderShape.setPosition(static_cast<float>(startingPosiiton.x), static_cast<float>(startingPosiiton.y));
	mStartPosition = mInvaderShape.getPosition();
	//std::cout << "Invader1 constructor " << mStartPosition.x << " " << mStartPosition.y << std::endl;
}

cInvader1::~cInvader1()
{
	//std::cout << "invader1 destructor" << std::endl;
}

void cInvader1::Update()
{
	cInvader1::mShootTimer = cInvader1::mClock.getElapsedTime();
	if (mHP == 0)//przesuwanie najezdzcy poza mape, aby nie mogl skrzywdzic bohatera, a jednoczesnie jego pociski mogly doleciec
	{
		mInvaderShape.move(static_cast<float>(mWindowSize.x), static_cast<float>(mWindowSize.y));
	}
	if (mInvaderShape.getPosition().x <= mStartPosition.x - 2 * mInvaderShape.getSize().x)
	{
		mMovementSpeed *= -1;
	}
	mInvaderShape.move(-mMovementSpeed, 0.0f);
	if (mInvaderShape.getPosition().x >= mStartPosition.x)
	{
		mMovementSpeed *= -1;
	}
	if (mShootTimer.asSeconds() >= 1.5f and mShootTimer.asMicroseconds() % 500 == 0)
	{
		cInvader1::mEnemyMissileVector.push_back(new cEnemyMissile(mInvaderShape.getPosition()));
		mClock.restart();
	}
}