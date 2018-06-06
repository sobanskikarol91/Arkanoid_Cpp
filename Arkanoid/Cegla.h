#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cegla : public Drawable	
{
	Sprite sprite;

public:
	// posylamy wskaznik do tekstury  konstruktorowi, ktory inicjalizuje ja w "sprajcie" oraz pozycje
	Cegla(Texture * tekstura, Vector2f pozycja) : sprite(*tekstura) 
	{
		sprite.setPosition(pozycja);
	};	

	// opisuje jak ma byc rysowany obiekt. Musi byc zaimplementowane z Interfejsu Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override
	{
		target.draw(sprite);
	}
};

