#pragma once
#include "BaseEntity.h"
#include "WolfStates.h"

class State;

const int TiredThreshold  = 0;
const int WellRested      = 5;
const int HungryThreshold = 5;
const int ThirstThreshold = 5;

class Wolf : public BaseEntity
{
public:
	Wolf();
	virtual ~Wolf();

	// Runs every iteration
	virtual void update();

	// Runs exit/enter on corresponding states
	void changeState(State* newState);

	// Hunger
	bool hungry() { return m_hunger > HungryThreshold; }
	void quenchHunger() { m_hunger = 0; }

	// Stamina
	bool wellRested() { return m_stamina >= WellRested; }
	bool tired() { return m_stamina < TiredThreshold; }
	void increaseStamina() { m_stamina += 1; }
	void decreaseStamina() { m_stamina -= 1; }

	// Thirst
	bool thirsty() { return m_thirst > ThirstThreshold; }
	void quenchThirst() { m_thirst = 0; }

private:
	State* m_currentState;
	int m_hunger = 0;
	int m_thirst = 0;
	int m_stamina = 5;
};

