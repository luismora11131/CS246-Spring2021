#ifndef ABSTRACTDECK_H
#define ABSTRACTDECK_H

#include <iostream>
#include <string>
#include <sstream>
#include "Card.h"

class DeckInterface
{
	public:
	virtual void Shuffle() = 0;
	virtual Card Draw() = 0;
	virtual bool Load(const Card&) = 0;
	virtual bool IsEmpty() const = 0;
	virtual std::string ToString() const = 0;
};

#endif
