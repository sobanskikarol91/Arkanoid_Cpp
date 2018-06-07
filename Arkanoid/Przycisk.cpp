#include "Przycisk.h"

Przycisk::Przycisk() {};
Przycisk::Przycisk(string nazwa, Vector2f pozycja, bool pokaz) // pokaz - czy przycisk ma byc schowany na poczatku 
{
	//pokaz_przycisk(pokaz);

	domyslna_tekstura.loadFromFile("images/" + nazwa + ".png");
	sprite.setPosition(pozycja.x, pozycja.y);
	sprite.setTexture(domyslna_tekstura);
}

bool Przycisk::mysz_nad_obiektem(Vector2i mysz, FloatRect granica) const
{
	return (mysz.x >= granica.left &&  mysz.x <= granica.left + granica.width &&
		mysz.y >= granica.top && mysz.y <= granica.top + granica.height);
}

bool Przycisk::pojedyncze_klikniecie()
{
	// sprawdzamy czy wystapilo pojedyncze klikniecie lewym przyciskiem myszy i czy wczesniej klawisz byl puszczony zalezy nam na detekcji tylko pojedynczego klikniecia
	if (!klawisz_nacisniety && Mouse::isButtonPressed(Mouse::Left))
	{
		klawisz_nacisniety = true;
		return true;
	}
	else if (!Mouse::isButtonPressed(Mouse::Left))
		klawisz_nacisniety = false;

	return false;
}

bool Przycisk::detekcja_klikniecia(const Window * okno)
{
	// jezeli jest nieaktyny zwroc false
	if (!aktywny) return false;

	// pozycja myszy wzgledem okna
	Vector2i mysz = Mouse::getPosition(*okno);

	// okreslamy granice polozenia prostokata
	FloatRect granica = sprite.getGlobalBounds();

	// sprawdzamy czy wystapilo klikniecie w obszarze obiektu
	return (mysz_nad_obiektem(mysz, granica) && pojedyncze_klikniecie());
}

void Przycisk::ustaw_wcisnieta_teksture(Texture * nowa_teksutra)
{
	sprite.setTexture(*nowa_teksutra);
}

void Przycisk::przywroc_domyslna_teksture()
{
	sprite.setTexture(domyslna_tekstura);
}

void Przycisk::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(sprite);
}

void Przycisk::pokaz_przycisk(bool state)
{
	aktywny = state;
	if (!aktywny)  // jak aktywny pokaz wizualnie
		sprite.setColor(Color::Transparent);
	else
		sprite.setColor(Color::White);
}