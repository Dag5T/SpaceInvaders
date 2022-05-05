#include "cHero.h"

std::vector<cHeroMissile*>& cHero::getHeroMissileVector()
{
	return cHero::mHeroMissiles;
}

cHero::cHero(sf::VideoMode windowSize)
{
	mHPMax = 3;
	mHP = mHPMax;
	//std::cout << mHP << std::endl;
	float sizeX = static_cast<float>(windowSize.width);
	float sizeY = static_cast<float>(windowSize.height);
	mMovementSpeed = sizeX/(sizeX*10.f);
	if (!mTexture.loadFromFile("../img/hero.png"))
	{
		std::cout << "Nie udalo sie zaladowac grafiki bohatera";
	}
	mHeroShape.setSize(sf::Vector2f(sizeX/24, sizeY/18));
	mHeroShape.setTexture(&mTexture);
	mHeroShape.setOrigin(cHero::mHeroShape.getSize().x / 2, cHero::mHeroShape.getSize().y / 2);
	mHeroShape.setPosition(sizeX/2, sizeY-mHeroShape.getSize().x);
}

cHero::~cHero()
{
}

sf::RectangleShape& cHero::getShape()
{
	return mHeroShape;
}

sf::Vector2f cHero::getPosition() const
{
	return mHeroShape.getPosition();
}

void cHero::Shoot()
{
	cHero::mShootTimer = cHero::mClock.getElapsedTime();
	if (cHero::mShootTimer.asSeconds() > 0.5)
	{
		cHero::mHeroMissiles.push_back(new cHeroMissile(mHeroShape.getPosition()));
		mClock.restart();
	}
}

bool cHero::checkCollision(const sf::RectangleShape& missleShape)
{
	cHero::mDamageTimer = cHero::mDamageClock.getElapsedTime();
	if (mDamageTimer.asSeconds() >= 1.0f and this->getShape().getGlobalBounds().intersects(missleShape.getGlobalBounds())) //mDamageTimer.asSeconds()>=1.0f and abs(missleShape.getPosition().x - mHeroShape.getPosition().x) < (missleShape.getSize().x / 2 + mHeroShape.getSize().x /2) and abs(missleShape.getPosition().y - mHeroShape.getPosition().y) < (missleShape.getSize().y / 2 + mHeroShape.getSize().y / 2))
	{
		cHero::mHP-=1;
		std::cout <<"Hero's HP: " << cHero::mHP << std::endl;
		mDamageClock.restart();
		return 1;
	}
	return 0;
}

void cHero::checkLife()
{
	if (cHero::mHP == 0)
	{
		std::cout << "umarles na smierc" << std::endl;
	}
}

unsigned cHero::getHP()
{
	return mHP;
}

void cHero::Update(unsigned spaceWidth)
{
	sf::Vector2f movement(0, 0);
	if (mHeroShape.getPosition().x <= 3 * mHeroShape.getSize().x)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			movement.x += mMovementSpeed;
		}
	}
	else if (mHeroShape.getPosition().x >= spaceWidth - 3 * mHeroShape.getSize().x)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			movement.x -= mMovementSpeed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += mMovementSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= mMovementSpeed;
	}
	mHeroShape.move(movement);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		cHero::Shoot();
	}
	cHero::checkLife();
}

void cHero::Draw(sf::RenderWindow& window)
{
	window.draw(mHeroShape);
}
