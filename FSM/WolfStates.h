#pragma once
#include "State.h"

class Wolf;

/********************/
class SearchForFood : public State
{
public:
	static SearchForFood* instance();
	virtual void enter(Wolf* wolf);
	virtual void execute(Wolf* wolf);
	virtual void exit(Wolf* wolf);
private:
	SearchForFood() {}
	SearchForFood(const SearchForFood&);
	SearchForFood& operator=(const SearchForFood&);
};


/*******************/
class HuntFood : public State
{
public:
	static HuntFood* instance();
	virtual void enter(Wolf* wolf);
	virtual void execute(Wolf* wolf);
	virtual void exit(Wolf* wolf);
private:
	HuntFood() {}
	HuntFood(const HuntFood&);
	HuntFood& operator=(const HuntFood&);
};


/*******************/
class EatFood : public State
{
public:
	static EatFood* instance();
	virtual void enter(Wolf* wolf);
	virtual void execute(Wolf* wolf);
	virtual void exit(Wolf* wolf);
private:
	EatFood() {}
	EatFood(const EatFood&);
	EatFood& operator=(const EatFood&);
};


/*******************/
class Rest : public State
{
public:
	static Rest* instance();
	virtual void enter(Wolf* wolf);
	virtual void execute(Wolf* wolf);
	virtual void exit(Wolf* wolf);
private:
	Rest() {}
	Rest(const Rest&);
	Rest& operator=(const Rest&);
};


/*******************/
class SearchForWater : public State
{
public:
	static SearchForWater* instance();
	virtual void enter(Wolf* wolf);
	virtual void execute(Wolf* wolf);
	virtual void exit(Wolf* wolf);
private:
	SearchForWater() {}
	SearchForWater(const SearchForWater&);
	SearchForWater& operator=(const SearchForWater&);
};


/*******************/
class DrinkWater : public State
{
public:
	static DrinkWater* instance();
	virtual void enter(Wolf* wolf);
	virtual void execute(Wolf* wolf);
	virtual void exit(Wolf* wolf);
private:
	DrinkWater() {}
	DrinkWater(const DrinkWater&);
	DrinkWater& operator=(const DrinkWater&);
};


/*******************/
class Play : public State
{
public:
	static Play* instance();
	virtual void enter(Wolf* wolf);
	virtual void execute(Wolf* wolf);
	virtual void exit(Wolf* wolf);
private:
	Play() {}
	Play(const Play&);
	Play& operator=(const Play&);
};
