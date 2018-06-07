#pragma once
#include "IReset.h"
#include <SFML/Graphics.hpp>
#include "Obrazek.h"
using namespace sf;

class ObiektGry : public IReset, Obrazek
{
private:
	Vector2f startowa_pozycja;

protected:
	ObiektGry(Vector2f startowa_pozycja) : startowa_pozycja(startowa_pozycja) { }

public:
	void reset() override
	{
		sprite.setPosition(startowa_pozycja);
	}
};

