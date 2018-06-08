#include "Obrazek.h"

Obrazek::Obrazek() {}
Obrazek::Obrazek(Texture * tekstura) : sprite(*tekstura) {}

// przyda sie do sprawdzenia kolizji
FloatRect Obrazek::pobierz_wymiary()
{
	return sprite.getGlobalBounds();
}

Vector2f Obrazek::pobierz_pozycje()
{
	return sprite.getPosition();
}

void Obrazek::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(sprite);
}