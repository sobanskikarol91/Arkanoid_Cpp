#pragma once
#include "Obrazek.h"

class Cegla : public Obrazek
{
public:
	// posylamy wskaznik do tekstury  konstruktorowi, ktory inicjalizuje ja w "sprajcie" oraz pozycje
	Cegla(Texture * tekstura, Vector2f pozycja) : Obrazek(tekstura)
	{
		sprite.setPosition(pozycja);
	};	
};

