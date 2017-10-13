#pragma once

class Wolf;

class State
{
public:
	virtual ~State() {}

	// Called when entering state
	virtual void enter(Wolf*) = 0;

	// Called every update
	virtual void execute(Wolf*) = 0;

	// Called when exiting state
	virtual void exit(Wolf*) = 0;
};

