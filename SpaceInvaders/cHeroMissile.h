#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
class cHeroMissile
{
private:
	sf::Texture mTexture;
	float mMissileSpeed;
	sf::RectangleShape mMissileShape;
public:
	cHeroMissile(sf::Vector2f heroPosition);
	~cHeroMissile();
	sf::RectangleShape& getShape();
	sf::Vector2f getPosition();
	unsigned int checkLife() const;
	void Update();
	void Draw(sf::RenderWindow& window);
};
