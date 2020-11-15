//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

//#include "Framework.h"
#include "HotDog.h"

// place holder for compiling purposes
// In each method replace with your code
#define STUB_PLEASE_REPLACE(x) (x)

// Constructors
HotDog::HotDog()
{
	this->condiments = (int)Condiments::Plain;
}

HotDog::HotDog(const HotDog& rhs)
{
	this->condiments = rhs.condiments;
}

HotDog& HotDog::operator=(const HotDog& rhs)
{
	this->condiments = rhs.condiments;

	return *this;
}

HotDog::HotDog(Condiments condiment)
{
	this->condiments = (int)condiment;
}

HotDog::~HotDog()
{
}

// Methods
void HotDog::Minus(Condiments condiment)
{
	// Only use bit-wise operations
	this->condiments = (condiments | (int)condiment) ^ (int)condiment;
}

void HotDog::Add(Condiments condiment)
{
	// Only use bit-wise operations
	this->condiments = this->condiments | (int)condiment;
}

int HotDog::GetCondiments()
{
	return this->condiments;
}

HotDog *HotDog::GetNext()
{
	return this->next;
}

HotDog *HotDog::GetPrev()
{
	return this->prev;
}

void HotDog::SetNext(HotDog *pDog)
{
	this->next = pDog;
}

void HotDog::SetPrev(HotDog *pDog)
{
	this->prev = pDog;
}

// ---  End of File ---------------

