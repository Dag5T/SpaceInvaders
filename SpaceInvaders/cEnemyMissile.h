#include <iostream>
#include <SFML/Graphics.hpp>
class cEnemyMissile
{
private:
	sf::Texture mTexture;
	float mMissileSpeed;
	sf::RectangleShape mMissileShape;
public:
	cEnemyMissile(sf::Vector2f enemyPosition);
	~cEnemyMissile();
	sf::RectangleShape& getShape();
	sf::Vector2f getPosition();
	unsigned int checkLife(unsigned windowHeight) const;
	void Update();
	void Draw(sf::RenderWindow& window);
};