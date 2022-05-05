#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "cHeroMissile.h"
class cHero//: public cHeroMissle
{
private:
	unsigned int mHP, mHPMax;
	float mMovementSpeed;
	sf::Texture mTexture;
	sf::RectangleShape mHeroShape;
	sf::Clock mClock;
	sf::Time mShootTimer;
	sf::Clock mDamageClock;
	sf::Time mDamageTimer;
	std::vector <cHeroMissile*> mHeroMissiles;
public:
	std::vector <cHeroMissile*>& getHeroMissileVector();
	cHero(sf::VideoMode windowSize);
	~cHero();
	sf::RectangleShape& getShape();
	sf::Vector2f getPosition() const;
	void Shoot();
	bool checkCollision(const sf::RectangleShape& missleShape);
	void checkLife();
	unsigned getHP();
	void Update(unsigned spaceWidth);
	void Draw(sf::RenderWindow& window);
};

