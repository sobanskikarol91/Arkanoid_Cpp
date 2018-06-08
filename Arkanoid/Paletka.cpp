#include "Paletka.h"


Paletka::Paletka() {}
Paletka::Paletka(Texture * tekstura, Vector2f pozycja) : Obrazek(tekstura), startowa_pozycja(pozycja)
{
	sprite.setPosition(pozycja);
}

void Paletka::ruch(Vector2f kierunek)
{
	sprite.move(kierunek);
}

void Paletka::reset() 
{
	sprite.setPosition(startowa_pozycja);
}