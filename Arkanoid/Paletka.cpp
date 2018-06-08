#include "Paletka.h"


Paletka::Paletka() {}
Paletka::Paletka(Texture * tekstura, Vector2f pozycja) : Obrazek(tekstura), startowa_pozycja(pozycja)
{
	sprite.setPosition(pozycja);
}

void Paletka::ruch(Vector2f kierunek, Vector2u  granica)
{
	// sprawdzamy czy paletka nei wyszla za ekran z lewej i prawej strony
	if (pobierz_pozycje().x < granica.x)
		sprite.setPosition(Vector2f(granica.x, pobierz_pozycje().y));
	else if (pobierz_pozycje().x > granica.y)
		sprite.setPosition(Vector2f(granica.y, pobierz_pozycje().y));
	else
		sprite.move(kierunek);

}

void Paletka::reset()
{
	sprite.setPosition(startowa_pozycja);
}