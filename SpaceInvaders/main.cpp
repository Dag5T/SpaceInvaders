#include <iostream>
#include <SFML/Graphics.hpp>
#include "cHero.h"
#include "cinvader.h"
#include "cSpace.h"
#include "cPoints.h"

int main()
{
    sf::VideoMode windowSize(800, 600);
	sf::RenderWindow window(windowSize, "Space Invaders");
	cHero hero(windowSize);
    std::vector <cInvader*> invader;
    cSpace space(&window);
	cPoints score(hero.getHP());
	cPoints finalScore(hero.getHP());
	
	while (window.isOpen())
	{
        space.Fight(&hero, invader, score);
	}
	finalScore = score;
	std::cout << "Twoj wynik to: " << std::endl;
	std::cout << finalScore.getDestroyedInvaders() * 100 * finalScore.getHeroLifes() << std::endl;

	return 0;
}