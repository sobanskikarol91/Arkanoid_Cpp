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
	Punkty() : pozycja(Vector2f(0, 0)), punkty(0) {}
	Punkty(Vector2f pozycja, Font * czcionka) : pozycja(pozycja), tekst("punkty: 0", *czcionka, 3), punkty(0)
	{
		tekst.setPosition(pozycja);
		tekst.setFillColor(Color::Yellow);
		tekst.setOutlineColor (Color::Black);
		tekst.setCharacterSize(24);
	}

	// przeciazenie operatora inkrementacji
	Punkty & operator++(int)
	{
		punkty++;
		tekst.setString("punkty: " + std::to_string(punkty));
		return *this;
	}

	// Inherited via Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override
	{
		target.draw(tekst);
	}

	void reset() override
	{
		punkty = 0;
		tekst.setString("punkty: 0");
	}
};

