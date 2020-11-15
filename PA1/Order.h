//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef ORDER_H
#define ORDER_H

// Add files include as needed
#include "HotDog.h"
#include "Names.h"

class Order 
{
public:
	// add code here (add more methods if desired)

	// Constructors
	Order();
	Order(Name nameIn);
	Order(const Order& rhs);
	Order& operator=(const Order& rhs);
	~Order();

	// Public Methods (Required)
	Name GetName();
	void SetName(Name nameIn);

	void Add(HotDog* pDog);
	void Remove(HotDog* pDog);

	void SetTail(HotDog* pDog);
	HotDog* GetTail();

	// Methods used for Testing and Internals (Required)
	HotDog* GetHead();

	void SetNext(Order* pOrdr);
	Order* GetNext();

	void SetPrev(Order* pOrdr);
	Order* GetPrev();

private:
	// Data: ---------------------------
	//        add code here
	Name name;
	Order* next = nullptr;
	Order* prev = nullptr;
	HotDog* head = nullptr;
	HotDog* tail = nullptr;
};

#endif

// ---  End of File ---------------
