#include "Punkty.h"

Punkty::Punkty() : pozycja(Vector2f(0, 0)), punkty(0) {}
Punkty::Punkty(Vector2f pozycja, Font * czcionka) : pozycja(pozycja), tekst("punkty: 0", *czcionka, 3), punkty(0)
{
	tekst.setPosition(pozycja);
	tekst.setFillColor(Color::Yellow);
	tekst.setOutlineColor(Color::Black);
	tekst.setCharacterSize(24);
}

// przeciazenie operatora inkrementacji
Punkty & Punkty::operator++(int)
{
	punkty++;
	tekst.setString("punkty: " + std::to_string(punkty));
	return *this;
}

// Inherited via Drawable
void Punkty::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(tekst);
}

void Punkty::reset()
{
	punkty = 0;
	tekst.setString("punkty: 0");
}
