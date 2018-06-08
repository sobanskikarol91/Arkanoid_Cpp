#include "Cegla.h"

// posylamy wskaznik do tekstury  konstruktorowi, ktory inicjalizuje ja w "sprajcie" oraz pozycje
Cegla::Cegla(Texture * tekstura, Vector2f pozycja) : Obrazek(tekstura)
{
	sprite.setPosition(pozycja);
};
