#include "cSpace.h"

cSpace::cSpace(sf::RenderWindow* window)
{
    count = 0;
    mWindow = window;
	if (!mBackgroundTexture.loadFromFile("../img/background_texture.jpg"))
	{
		std::cout << "Nie udalo sie zaladowac tla\n";
	}
	mBackgroundTexture.setRepeated(true);
	mBackground.setTexture(mBackgroundTexture);
	mBackground.setTextureRect(sf::IntRect(0, 0, mWindow->getSize().x, mWindow->getSize().y));
}

cSpace::~cSpace()
{
}

sf::Sprite cSpace::getBackground()
{
	return mBackground;
}

void cSpace::initFirstStage(std::vector<cInvader*>& invader)
{
	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
            sf::Vector2u position(mWindow->getSize().x - (((j + 1) * mWindow->getSize().x) / 6), (i + 1) * mWindow->getSize().y / 6);
            invader.push_back(new cInvader1(position, mWindow->getSize()));
		}
	}
}

void cSpace::initSecondStage(std::vector<cInvader*>& invader)
{
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 5; j++)
        {
            sf::Vector2u position(mWindow->getSize().x + ((j + 1) * mWindow->getSize().x/5), (i + 1) * mWindow->getSize().y / 6);
            invader.push_back(new cInvader2(position, mWindow->getSize()));
        }
    }
}

void cSpace::Fight(cHero* hero, std::vector<cInvader*>& invader, cPoints &score)
{
    switch (count)//zarzadzanie turami
    {
    default:
        break;
    case 0:
        initFirstStage(invader);
        count++;//Zwieksza licznik, aby nie inicjowalo non stop przeciwnikow
        break;
    case 2:
        initSecondStage(invader);
        count++;
        break;
    }
    sf::Event event;
    while (mWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) and mWindow->hasFocus()))
        {
            mWindow->close();
        }
    }
    if ((hero->getHP() <= 0))
    {
        mWindow->close();
    }
    if (invader.empty())//warunek przejscia rundy
    {
        count++;
        std::cout << "Twoj aktualny wynik po rundzie:" << std::endl << score << "\n\n";
        if (count >= 3)
        {
            std::cout << "Gratulacje. Koniec gry" << std::endl;
            mWindow->close();
        }
    }
    mWindow->clear();
    mWindow->draw(mBackground);
    hero->Update(mWindow->getSize().x);
    hero->Draw(*mWindow);
    for (unsigned i = 0; i < hero->getHeroMissileVector().size(); i++)//pociski bohatera
    {
        hero->getHeroMissileVector().at(i)->Update();
        hero->getHeroMissileVector().at(i)->Draw(*mWindow);
        if (hero->getHeroMissileVector().at(i)->checkLife())//zycie pociskow bohatera
        {
            delete hero->getHeroMissileVector().at(i);
            hero->getHeroMissileVector().erase(hero->getHeroMissileVector().begin() + i);
        }
    }
    for (unsigned i = 0; i < invader.size(); i++)//najezdzcy
    {
        invader.at(i)->Update();
        invader.at(i)->Draw(*mWindow);
        for (unsigned j = 0; j < hero->getHeroMissileVector().size(); j++)
        {
            if (invader.at(i)->CheckCollision(hero->getHeroMissileVector().at(j)->getShape()))//sprawdzanie kolizji z pociskami bohatera
            {
                delete hero->getHeroMissileVector().at(j);
                hero->getHeroMissileVector().erase(hero->getHeroMissileVector().begin() + j);
                invader.at(i)->ReduceLife();
            }
        }
        for (unsigned i = 0; i < invader.size(); i++)//pociski najezdzcow
        {
            for (unsigned j = 0; j < invader.at(i)->getEnemyMissileVector().size(); j++)
            {
                invader.at(i)->getEnemyMissileVector().at(j)->Update();
                invader.at(i)->getEnemyMissileVector().at(j)->Draw(*mWindow);
                if (hero->checkCollision(invader.at(i)->getEnemyMissileVector().at(j)->getShape()))//usuwa pocisk, jesli zderzy sie z bohaterem
                {
                    delete invader.at(i)->getEnemyMissileVector().at(j);
                    invader.at(i)->getEnemyMissileVector().erase(invader.at(i)->getEnemyMissileVector().begin() + j);
                    score = score - 1;
                    continue;
                }
                if (invader.at(i)->getEnemyMissileVector().at(j)->checkLife(mWindow->getSize().y))//usuwa pocisk, jesli opusci plansze
                {
                    delete invader.at(i)->getEnemyMissileVector().at(j);
                    invader.at(i)->getEnemyMissileVector().erase(invader.at(i)->getEnemyMissileVector().begin() + j);
                }
            }
        }

        if (invader.at(i)->getHP() <= 0 and invader.at(i)->getEnemyMissileVector().empty())
        {
            delete invader.at(i);
            invader.erase(invader.begin() + i);
            score = score + 1;
        }
    }
    mWindow->display();	
}
