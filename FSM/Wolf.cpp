#include "Wolf.h"


Wolf::Wolf() :
	m_currentState(Play::instance())
{
}

Wolf::~Wolf()
{
}

void Wolf::update()
{
	m_hunger++;
	m_thirst++;

	if (m_currentState)
	{
		m_currentState->execute(this);
	}
}

void Wolf::changeState(State * newState)
{
	if (m_currentState && newState)
	{
		m_currentState->exit(this);

		m_currentState = newState;

		m_currentState->enter(this);
	}
}
