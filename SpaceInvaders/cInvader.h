#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cHeroMissile.h"
#include "cEnemyMissile.h"
class cInvader
{
protected:
	unsigned int mHP, mHPMax;
	float mMovementSpeed;
	sf::Texture mTexture;
	sf::RectangleShape mInvaderShape;
	sf::Vector2f mStartPosition;
	sf::Clock mClock;
	sf::Time mShootTimer;
	sf::Vector2u mWindowSize;
	std::vector <cEnemyMissile*> mEnemyMissileVector;
public:
	sf::Vector2f getPosition() const;
	virtual std::vector <cEnemyMissile*>& getEnemyMissileVector();
	sf::RectangleShape& getShape();
	bool CheckCollision(const sf::RectangleShape& missleShape);
	void ReduceLife();
	unsigned int getHP();
	virtual void Update() = 0;
	void Draw(sf::RenderWindow& window);
};
