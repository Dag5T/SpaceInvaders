#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cHero.h"
#include "cHeroMissile.h"
#include "cInvader1.h"
#include "cInvader2.h"
#include "cPoints.h"
class cSpace
{
private:
	unsigned count;
	sf::RenderWindow* mWindow;
	sf::Sprite mBackground;
	sf::Texture mBackgroundTexture;
public:
	cSpace(sf::RenderWindow* window);
	~cSpace();
	sf::Sprite getBackground();
	void initFirstStage(std::vector <cInvader*>& invader);
	void initSecondStage(std::vector <cInvader*>& invader);
	void Fight(cHero* hero, std::vector <cInvader*>& invader, cPoints& score);
};

