#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

// klasa ktora przechowuje Sprite jako pole, cegla paletka i pilka beda dziedziczyc po tej klasie
class Obrazek : public Drawable
{
protected:
	Sprite sprite;
	Obrazek();
	Obrazek(Texture * tekstura);

public:
	// przyda sie do sprawdzenia kolizji
	FloatRect pobierz_wymiary();
	Vector2f pobierz_pozycje();
	// opisuje jak ma byc rysowany obiekt. Musi byc zaimplementowane z Interfejsu Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override;
};

