#include "cInvader.h"

sf::Vector2f cInvader::getPosition() const
{
	return sf::Vector2f();
}

std::vector<cEnemyMissile*>& cInvader::getEnemyMissileVector()
{
	return mEnemyMissileVector;
}

sf::RectangleShape& cInvader::getShape()
{
	return mInvaderShape;
}

bool cInvader::CheckCollision(const sf::RectangleShape& missleShape)
{
	if (abs(mInvaderShape.getPosition().x - missleShape.getPosition().x) <= (mInvaderShape.getSize().x / 2 + missleShape.getSize().x / 2))
	{
		if (abs(mInvaderShape.getPosition().y - missleShape.getPosition().y) < (mInvaderShape.getSize().y / 2 + missleShape.getSize().y / 2))
		{
			return 1;
		}
		
	}

	return 0;
}

void cInvader::ReduceLife()
{
	cInvader::mHP--;
}

unsigned int cInvader::getHP()
{
	return mHP;
}

void cInvader::Draw(sf::RenderWindow& window)
{
	window.draw(mInvaderShape);
}