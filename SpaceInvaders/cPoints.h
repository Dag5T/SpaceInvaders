#pragma once
#include <iostream>
class cPoints
{
	unsigned mDestroyedInvaders, mHeroLifes;
public:
	cPoints(unsigned aHeroLifes);
	cPoints(unsigned aDestroyedInvaders, unsigned aHeroLifes);
	~cPoints();
	unsigned getDestroyedInvaders();
	unsigned getHeroLifes();
	cPoints operator + (const unsigned right) const;
	cPoints operator - (const unsigned right) const;
	cPoints& operator = (const cPoints aPoints);
	friend std::ostream& operator << (std::ostream& cout, const cPoints& score);
};

std::ostream& operator << (std::ostream& stream, const cPoints& score);