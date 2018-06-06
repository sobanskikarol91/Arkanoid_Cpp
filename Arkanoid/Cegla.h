#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cegla
{
	Sprite sprite;

public:
	// posylamy wskaznik do tekstury  konstruktorowi, ktory inicjalizuje ja w "sprajcie" oraz pozycje
	Cegla(Texture * tekstura, Vector2f pozycja) : sprite(*tekstura) 
	{
		sprite.setPosition(pozycja);
	};	
};

