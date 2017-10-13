#include "WolfStates.h"
#include "Wolf.h"
#include <iostream>
#include <random>

//---------------------- SearchForFood
SearchForFood* SearchForFood::instance()
{
	static SearchForFood instance;
	return &instance;
}

void SearchForFood::enter(Wolf* wolf)
{
	std::cout << "Out and huntin' some sheep\n";
}

void SearchForFood::execute(Wolf* wolf)
{
	if (rand() % 10 < 3)
	{
		std::cout << "Spotted sheep!\n";
		wolf->changeState(HuntFood::instance());
	}
	else
	{
		std::cout << "Searching for sheep\n";
	}
}

void SearchForFood::exit(Wolf* wolf)
{
	std::cout << "Finishing search\n";
}


//----------------------- HuntFood
HuntFood * HuntFood::instance()
{
	static HuntFood instance;
	return &instance;
}

void HuntFood::enter(Wolf* wolf)
{
	std::cout << "Preparin' for hunt\n";
}

void HuntFood::execute(Wolf* wolf)
{
	wolf->decreaseStamina();
	if (wolf->tired())
	{
		std::cout << "Too tired to hunt right now\n";
		wolf->changeState(Rest::instance());
	}
	else if (rand() % 10 < 3)
	{
		std::cout << "Caught the sheep!\n";
		wolf->changeState(EatFood::instance());
	}
	else
		std::cout << "Huntin'\n";
}

void HuntFood::exit(Wolf* wolf)
{
	std::cout << "Stopped huntin' the sheep\n";
}


//---------------------- EatFood
EatFood * EatFood::instance()
{
	static EatFood instance;
	return &instance;
}

void EatFood::enter(Wolf * wolf)
{
	std::cout << "Preparin' food\n";
}

void EatFood::execute(Wolf * wolf)
{
	std::cout << "Eatin' sheep. Nom nom\n";
	wolf->quenchHunger();
	if (wolf->thirsty())
	{
		std::cout << "Now I'm really thirsty\n";
		wolf->changeState(SearchForWater::instance());
	}
	else if (wolf->tired())
	{
		std::cout << "Now I'm really tired\n";
		wolf->changeState(Rest::instance());
	}
	else
	{
		std::cout << "Time to play\n";
		wolf->changeState(Play::instance());
	}
}

void EatFood::exit(Wolf * wolf)
{
	std::cout << "Mmm, that was delicious\n";
}


//-------------------------- Rest
Rest * Rest::instance()
{
	static Rest instance;
	return &instance;
}

void Rest::enter(Wolf * wolf)
{
	std::cout << "Preparin' for a nap\n";
}

void Rest::execute(Wolf * wolf)
{
	std::cout << "Nappin'...\n";
	wolf->increaseStamina();
	if (wolf->wellRested())
	{
		std::cout << "Time to find some more food\n";
		wolf->changeState(SearchForFood::instance());
	}
}

void Rest::exit(Wolf * wolf)
{
	std::cout << "T'was a good nap\n";
}


//--------------------------- SearchForWater
SearchForWater * SearchForWater::instance()
{
	static SearchForWater instance;
	return &instance;
}

void SearchForWater::enter(Wolf * wolf)
{
	std::cout << "Walkin' toward water area\n";
}

void SearchForWater::execute(Wolf * wolf)
{
	std::cout << "Lookin' for water\n";
	if (rand() % 10 < 3)
	{
		wolf->changeState(DrinkWater::instance());
	}
}

void SearchForWater::exit(Wolf * wolf)
{
	std::cout << "Found water!\n";
}


//------------------------- DrinkWater
DrinkWater * DrinkWater::instance()
{
	static DrinkWater instance;
	return &instance;
}

void DrinkWater::enter(Wolf * wolf)
{
	std::cout << "Starting to drink\n";
}

void DrinkWater::execute(Wolf * wolf)
{
	wolf->quenchThirst();
	std::cout << "Drinking water\n";
	wolf->changeState(SearchForFood::instance());
}

void DrinkWater::exit(Wolf * wolf)
{
	std::cout << "Leaving water area\n";
}


//-------------------------- Play
Play * Play::instance()
{
	static Play instance;
	return &instance;
}

void Play::enter(Wolf * wolf)
{
	std::cout << "Bringing toys\n";
}

void Play::execute(Wolf * wolf)
{
	if (wolf->hungry())
	{
		std::cout << "Too hungry to play\n";
		wolf->changeState(SearchForFood::instance());
	}
	else if (wolf->thirsty())
	{
		std::cout << "Too thirsty to play\n";
		wolf->changeState(SearchForWater::instance());
	}
	else if (wolf->tired())
	{
		std::cout << "Too tired to play\n";
		wolf->changeState(Rest::instance());
	}
	else
		std::cout << "Playin' with toys\n";
}

void Play::exit(Wolf * wolf)
{
	std::cout << "Leavin' toys\n";
}
