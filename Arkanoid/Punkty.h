#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "IReset.h"
using namespace sf;

class Punkty : public Drawable, IReset
{
	Text tekst;
	Vector2i pozycja;
	int punkty;

public:
	Punkty();
	Punkty(Vector2f pozycja, Font * czcionka);
	// przeciazenie operatora inkrementacji
	Punkty & operator++(int);
	// Inherited via Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override;
	void reset() override;
};

