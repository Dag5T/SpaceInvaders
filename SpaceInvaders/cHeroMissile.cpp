#include "cHeroMissile.h"

cHeroMissile::cHeroMissile(sf::Vector2f heroPosition)
{
	mMissileShape.setSize(sf::Vector2f(15.f, 30.f));
	mMissileShape.setFillColor(sf::Color(187, 231, 255, 255));
	mMissileShape.setOrigin(mMissileShape.getSize().x / 2, mMissileShape.getSize().y / 2);
	mMissileSpeed = 0.5f;
	mMissileShape.setPosition(heroPosition);
}
cHeroMissile::~cHeroMissile()
{
	//std::cout << "destruktor" << std::endl;
}

sf::RectangleShape& cHeroMissile::getShape()
{
	return cHeroMissile::mMissileShape;
}

sf::Vector2f cHeroMissile::getPosition()
{
	return cHeroMissile::mMissileShape.getPosition();
}

unsigned int cHeroMissile::checkLife() const
{
	if (mMissileShape.getPosition().y - mMissileShape.getSize().y < 0)
	{
		return 1;
	}
	return 0;
}

void cHeroMissile::Update()
{
	mMissileShape.move(0.f, -mMissileSpeed);
}

void cHeroMissile::Draw(sf::RenderWindow& window)
{
	window.draw(mMissileShape);
}