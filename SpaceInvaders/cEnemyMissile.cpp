#include "cEnemyMissile.h"

cEnemyMissile::cEnemyMissile(sf::Vector2f enemyPosition)
{
	mMissileShape.setSize(sf::Vector2f(10.f, 15.f));
	mMissileShape.setFillColor(sf::Color(187, 131, 23, 255));
	mMissileShape.setOrigin(mMissileShape.getSize().x / 2, mMissileShape.getSize().y / 2);
	mMissileSpeed = 0.06f;
	mMissileShape.setPosition(enemyPosition);
}

cEnemyMissile::~cEnemyMissile()
{
	//std::cout << "enemy missile destructor" << std::endl;
}

sf::RectangleShape& cEnemyMissile::getShape()
{
	return mMissileShape;
}

sf::Vector2f cEnemyMissile::getPosition()
{
	return sf::Vector2f();
}

unsigned int cEnemyMissile::checkLife(unsigned windowHeight) const
{
	if (mMissileShape.getPosition().y >= windowHeight)//do zmiany
	{
		return 1;
	}
	return 0;
}

void cEnemyMissile::Update()
{
	mMissileShape.move(0.f, mMissileSpeed);
}

void cEnemyMissile::Draw(sf::RenderWindow& window)
{
	window.draw(mMissileShape);
}
