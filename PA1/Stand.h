//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef STAND_H
#define STAND_H

// Add files include as needed
#include "Names.h"
#include "Order.h"

class Stand
{
public:
	// add code here (add more methods if desired)
	Stand();
	Stand(const Stand& rhs);
	Stand& operator=(const Stand& rhs);
	~Stand();

	// Public Methods (Required)
	void Remove(Name nameIn);
	void Add(Order *pOrdr);
	int GetCurrOrders();
	int GetPeakOrders();

	void SetTail(Order* pOrdr);
	Order* GetTail();

	//Helper methods
	Order* FindOrder(Name nameIn);
	void RemoveOrder(Order* pOrdr);
	
	// Methods used for Testing and Internals (Required)
	Order *GetHead();

private:
	// Data: ---------------------------
	//        add code here
	Name name;
	Order* head = nullptr;
	Order* tail = nullptr;
	int currOrders = 0;
	int peakOrders = 0;
};

#endif

// ---  End of File ---------------
