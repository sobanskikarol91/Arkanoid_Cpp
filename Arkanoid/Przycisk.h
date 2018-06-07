#pragma once
#include "Przycisk.h"
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Przycisk : public Drawable
{
	Texture domyslna_tekstura;
	Sprite sprite;
	bool klawisz_nacisniety;  // flaga ktora przyda sie do detekcji pojedynczego klikniecia 
	bool aktywny; // czy przycisk aktywny

public:
	Przycisk();
	Przycisk(string nazwa, Vector2f  pozycja, bool pokaz); // pokaz - czy przycisk ma byc schowany na poczatku 
	bool mysz_nad_obiektem(Vector2i mysz, FloatRect granica) const;
	bool pojedyncze_klikniecie();
	bool detekcja_klikniecia(const Window * okno);
	void ustaw_wcisnieta_teksture(Texture * nowa_teksutra);
	void przywroc_domyslna_teksture();
	void draw(RenderTarget & target, RenderStates state) const;
	void pokaz_przycisk(bool state);
};

