//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

//#include "Framework.h"
#include "Stand.h"

// place holder for compiling purposes
// In each method replace with your code
#define STUB_PLEASE_REPLACE(x) (x)

// Constructors
Stand::Stand()
{
	this->name = Name::Unknown;
}

Stand::Stand(const Stand& rhs)
{
	this->name = rhs.name;
	this->currOrders = rhs.currOrders;
	this->peakOrders = rhs.peakOrders;

	//Deep copy linked list
	if (rhs.head)
	{
		this->head = new Order(*rhs.head);

		Order* newOrdr = this->GetHead();
		Order* copy = rhs.head;

		while (copy->GetNext() != nullptr)
		{
			Order* prevNode = newOrdr;

			newOrdr->SetNext(new Order(*copy->GetNext()));

			copy = copy->GetNext();
			newOrdr = newOrdr->GetNext();
			newOrdr->SetPrev(prevNode);
			this->tail = newOrdr;
		}

		newOrdr->SetNext(nullptr);
	}
	else
	{
		this->head = nullptr;
	}
}

Stand& Stand::operator=(const Stand& rhs)
{
	this->name = rhs.name;
	this->currOrders = rhs.currOrders;
	this->peakOrders = rhs.peakOrders;

	//Deep copy linked list
	if (rhs.head)
	{
		this->head = new Order(*rhs.head);

		Order* newOrdr = this->GetHead();
		Order* copy = rhs.head;

		while (copy->GetNext() != nullptr)
		{
			Order* prevNode = newOrdr;

			newOrdr->SetNext(new Order(*copy->GetNext()));

			copy = copy->GetNext();
			newOrdr = newOrdr->GetNext();
			newOrdr->SetPrev(prevNode);
			this->tail = newOrdr;
		}

		newOrdr->SetNext(nullptr);
	}
	else
	{
		this->head = nullptr;
	}

	return *this;
}

Stand::~Stand()
{
	Order* current = this->GetHead();

	//while head is not null, delete; else, break
	while (current != nullptr)
	{
		Order* nextDog = current->GetNext();
		delete current;
		current = nextDog;
	}

	this->head = nullptr;
}

// Helper Methods

//Find order in list from a given name. Returns pointer to Order
Order* Stand::FindOrder(Name nameIn)
{
	Order* current = this->GetHead();
	Order* foundOrder = nullptr;

	while (current != nullptr)
	{
		if (current->GetName() == nameIn)
		{
			foundOrder = current;
		}

		current = current->GetNext();
	}

	return foundOrder;
}

//Removes node from order list with given order pointer
void Stand::RemoveOrder(Order* pOrdr)
{
	//Case if at middle or end of list
	if (pOrdr->GetPrev() != nullptr)
	{
		pOrdr->GetPrev()->SetNext(pOrdr->GetNext());
	}
	//Case if at beginning of list
	else
	{
		this->head = pOrdr->GetNext();
	}

	if (pOrdr->GetNext() != nullptr)
	{
		pOrdr->GetNext()->SetPrev(pOrdr->GetPrev());
	}

	if (pOrdr)
	{
		delete pOrdr;
	}

	this->currOrders -= 1;
}

// Methods
void Stand::Remove(Name nameIn)
{
	Order* orderToRemove = FindOrder(nameIn); //Find order to remove
	RemoveOrder(orderToRemove); //Remove order from list
}

void Stand::Add(Order *pOrdr)
{
	//Case if list is empty
	if (this->GetHead() == nullptr)
	{
		this->head = pOrdr;
	}
	//Case if one element in list
	else if (this->GetHead()->GetNext() == nullptr)
	{
		this->GetHead()->SetNext(pOrdr);
		pOrdr->SetPrev(this->GetHead());
	}
	//Case if > 1 element in list
	else
	{
		pOrdr->SetPrev(this->GetTail());
		this->GetTail()->SetNext(pOrdr);
	}

	//Update tail/next ptrs
	this->tail = pOrdr;
	pOrdr->SetNext(nullptr);

	//Update order stats
	this->currOrders += 1;
	this->peakOrders += 1;
}

int Stand::GetCurrOrders()
{
	return this->currOrders;
}

int Stand::GetPeakOrders()
{
	return this->peakOrders;
}

Order *Stand::GetHead()
{
	return this->head;
}

void Stand::SetTail(Order* pOrdr)
{
	this->tail = pOrdr;
}

Order* Stand::GetTail()
{
	return this->tail;
}

// ---  End of File ---------------

