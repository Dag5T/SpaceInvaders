#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cInvader.h"
class cInvader1 :
	public cInvader
{
public:
	cInvader1(sf::Vector2u startingPosiiton, sf::Vector2u windowSize);
	~cInvader1();
	void Update();
};

