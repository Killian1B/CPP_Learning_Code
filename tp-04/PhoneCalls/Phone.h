#pragma once

#include "Person.h"

class Phone
{
protected:
	Phone(const Person& owner)
		: _owner { owner }
	{}

public:
	virtual ~Phone() {}
	
	virtual void ring() const = 0;

protected:
	const Person& _owner;
};
