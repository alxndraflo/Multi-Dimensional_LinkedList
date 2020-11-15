//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

//#include "Framework.h"
#include "Order.h"

// place holder for compiling purposes
// In each method replace with your code
#define STUB_PLEASE_REPLACE(x) (x)

// Constructors
Order::Order()
{
	this->name = Name::Unknown;
}

Order::Order(Name nameIn)
{
	this->name = nameIn;
}

Order::Order(const Order& rhs)
{
	this->name = rhs.name;

	//Deep copy linked list
	if (rhs.head)
	{
		this->head = new HotDog(*rhs.head);

		HotDog* newDog = this->GetHead();
		HotDog* copy = rhs.head;

		while (copy->GetNext() != nullptr)
		{
			HotDog* prevNode = newDog;

			newDog->SetNext(new HotDog(*copy->GetNext()));

			copy = copy->GetNext();
			newDog = newDog->GetNext();
			newDog->SetPrev(prevNode);
			this->tail = newDog;
		}

		newDog->SetNext(nullptr);
	}
	else
	{
		this->head = nullptr;
	}
}

Order& Order::operator=(const Order& rhs)
{
	this->name = rhs.name;

	//Deep copy linked list
	if (rhs.head)
	{
		this->head = new HotDog(*rhs.head);

		HotDog* newDog = this->GetHead();
		HotDog* copy = rhs.head;

		while (copy->GetNext() != nullptr)
		{
			HotDog* prevNode = newDog;

			newDog->SetNext(new HotDog(*copy->GetNext()));

			copy = copy->GetNext();
			newDog = newDog->GetNext();
			newDog->SetPrev(prevNode);
			this->tail = newDog;
		}

		newDog->SetNext(nullptr);
	}
	else
	{
		this->head = nullptr;
	}

	return *this;
}

Order::~Order()
{
	HotDog* current = this->GetHead();

	//While head is not null, delete; else break
	while (current != nullptr)
	{
		HotDog* nextDog = current->GetNext();
		delete current;
		current = nextDog;
	}

	this->head = nullptr;
}

// Methods
void Order::Add(HotDog* pDog)
{
	//Case if list is empty
	if (this->GetHead() == nullptr) 
	{
		this->head = pDog;
	}
	//Case if one element in list
	else if (this->GetHead()->GetNext() == nullptr)
	{
		this->GetHead()->SetNext(pDog);
		pDog->SetPrev(this->GetHead());
	}
	//Case if > 1 element in list
	else
	{
		pDog->SetPrev(this->GetTail());
		this->GetTail()->SetNext(pDog);
	}

	//Update tail/next ptrs
	this->tail = pDog;
	pDog->SetNext(nullptr);
}

void Order::Remove(HotDog* pDog)
{
	//Case if at middle or end of list
	if (pDog->GetPrev() != nullptr)
	{
		pDog->GetPrev()->SetNext(pDog->GetNext());
	}
	//Case if at beginning of list
	else
	{
		this->head = pDog->GetNext();
	}

	//If not at end of list
	if (pDog->GetNext() != nullptr)
	{
		pDog->GetNext()->SetPrev(pDog->GetPrev());
	}

	if (pDog)
	{
		delete pDog;
	}
}

Order* Order::GetNext()
{
	return this->next;
}

Order* Order::GetPrev()
{
	return this->prev;
}

HotDog* Order::GetHead()
{
	return this->head;
}

HotDog* Order::GetTail()
{
	return this->tail;
}

void Order::SetTail(HotDog* pDog)
{
	this->tail = pDog;
}

void Order::SetNext(Order *pOrdr)
{
	this->next = pOrdr;
}

void Order::SetPrev(Order *pOrdr)
{
	this->prev = pOrdr;
}

Name Order::GetName()
{
	return this->name;
}

void Order::SetName(Name nameIn)
{
	this->name = nameIn;
}

// ---  End of File ---------------
