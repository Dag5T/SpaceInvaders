#include "cPoints.h"

cPoints::cPoints(unsigned aHeroLifes): mDestroyedInvaders(0), mHeroLifes(aHeroLifes)
{
}

cPoints::cPoints(unsigned aDestroyedInvaders, unsigned aHeroLifes)
	: mDestroyedInvaders(aDestroyedInvaders), mHeroLifes(aHeroLifes)
{
}

cPoints::~cPoints()
{
}

unsigned cPoints::getDestroyedInvaders()
{
	return mDestroyedInvaders;
}

unsigned cPoints::getHeroLifes()
{
	return mHeroLifes;
}

cPoints cPoints::operator+(const unsigned right) const
{
	cPoints tmp(this->mDestroyedInvaders,this->mHeroLifes);
	tmp.mDestroyedInvaders += right;
	return tmp;
}

cPoints cPoints::operator-(const unsigned right) const
{
	cPoints tmp(this->mDestroyedInvaders, this->mHeroLifes);
	tmp.mHeroLifes -= right;
	return tmp;
}

cPoints& cPoints::operator=(const cPoints aPoints)
{
	mDestroyedInvaders = aPoints.mDestroyedInvaders;
	mHeroLifes = aPoints.mHeroLifes;

	return *this;
}

std::ostream& operator<<(std::ostream& stream, const cPoints& score)
{
	return stream << "Zniszczeni przeciwnicy: " << score.mDestroyedInvaders << std::endl << "Punkty zycia: " << score.mHeroLifes;
}
