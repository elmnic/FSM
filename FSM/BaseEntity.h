#pragma once
class BaseEntity
{
public:
	enum AnimalType { Wolf, Sheep };

	BaseEntity();
	virtual ~BaseEntity();

	// Runs every iteration
	virtual void update() = 0;
};

