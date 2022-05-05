#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cInvader.h"
class cInvader2 :
    public cInvader
{
private:
	bool mIsInitialized = false;
public:
	cInvader2(sf::Vector2u startingPosiiton, sf::Vector2u windowSize);
	~cInvader2();
	void Update();
};

