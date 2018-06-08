#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cegla.h"
#include "Pilka.h"
#include "Paletka.h"
#include <SFML/Audio.hpp>
#include "Punkty.h"
#include "Przycisk.h"


enum STAN { WYBICIE, GRA, PRZEGRANA, RESTART, WYGRANA };

class Arkanoid
{
	Texture tlo_textura, cegla_textura, pilka_textura, paletka_tekstura;
	Sprite tlo;
	Punkty punkty;

	Font czcionka;
	Vector2i ile_cegiel;// ilosc cegiel w wierszach i kolumnach
	vector<Cegla> aktywne_cegly;
	vector<Cegla> zbite_cegly;
	Paletka paletka;
	Pilka pilka;
	STAN stan;
	Przycisk restart_przycisk;

public:
	Arkanoid();
	// odstep_cegiel to odstep miedzy ceglami w kolumnie i wierszu
	Arkanoid(Vector2i ile_cegiel, Vector2f odstep_cegiel, Vector2f predkosc);
private:
	void wczytaj_czcionke();
	void stworz_cegly(Vector2f odstep);
	void stworz_tlo();
	void stworz_paletke();
	void stworz_pilke(Vector2f predkosc);
	void stworz_okno();
	void zbij_cegle(int nr);
	void obsluga_wejscia(RenderWindow & okno);
	// spradzamy czy pilka nachodzi na cegielke i zwracamy prawde albo falsz,  wykorzystujemy tez to do detekcji kolizji z paletka
	bool sprawdz_kolizje(FloatRect obszar_pilki, FloatRect obszar_celu);
	void sprawdz_wygrana();
	void sprawdz_przegrana();
	void sprawdz_kolizje_cegiel();
	void sprawdz_kolizje_paletki();
	void gra(RenderWindow & okno);
	void wybicie(RenderWindow & okno);
	void maszyna_stanow(RenderWindow & okno);
	inline void dodaj_punkt();
	void restart(RenderWindow & okno);
};

