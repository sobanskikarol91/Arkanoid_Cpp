#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cegla.h"
#include "Pilka.h"
#include "Paletka.h"

using namespace std;
using namespace sf;

//teset
#include <iostream>
using namespace std;
class Arkanoid
{
	Texture tlo_textura, cegla_textura, pilka_textura, paletka_tekstura;
	Sprite tlo;
	Vector2i ile_cegiel;// ilosc cegiel w wierszach i kolumnach
	vector<Cegla> aktywne_cegly;
	vector<Cegla> zbite_cegly;
	Paletka paletka;
	Pilka pilka;

public:
	Arkanoid() {}

	// odstep_cegiel to odstep miedzy ceglami w kolumnie i wierszu
	Arkanoid(Vector2i ile_cegiel, Vector2f odstep_cegiel, Vector2f predkosc) : ile_cegiel(ile_cegiel)
	{
		stworz_pilke(predkosc);
		stworz_tlo();
		stworz_paletke();
		stworz_cegly(odstep_cegiel);
		stworz_okno();
	};

private:
	void stworz_cegly(Vector2f odstep)
	{
		cegla_textura.loadFromFile("images/block01.png");

		Vector2u wielkosc_tekstury = cegla_textura.getSize();
		// tworzymy cegly w rzedach i kolumnach
		for (size_t y = 0; y < ile_cegiel.y; y++)
		{
			for (size_t x = 0; x < ile_cegiel.x; x++)
			{
				// dodajemy do listy cegle ustawiajac jej teksture i pozycje i odstep miedzy ceglami

				Vector2f pozycja = Vector2f((odstep.x + wielkosc_tekstury.x)*x, (wielkosc_tekstury.y + odstep.y)*y);

				aktywne_cegly.push_back(Cegla(&cegla_textura, pozycja));
			}
		}
	}

	void stworz_tlo()
	{
		tlo_textura.loadFromFile("images/background.jpg");
		tlo.setTexture(tlo_textura);
	}

	void stworz_paletke()
	{
		paletka_tekstura.loadFromFile("images/paddle.png");
		paletka = Paletka(&paletka_tekstura, Vector2f(300, 440));
	}

	void stworz_pilke(Vector2f predkosc)
	{
		pilka_textura.loadFromFile("images/ball.png");
		pilka = Pilka(&pilka_textura, Vector2f(300, 300), predkosc);
	}

	void stworz_okno()
	{
		RenderWindow okno(VideoMode(520, 450), "Arkanoid!");

		// wykonuj dopoki okno jest otwarte
		while (okno.isOpen())
		{
			Event event;

			while (okno.pollEvent(event))
			{
				// gdy uzytkownik nacisnie zamkniecie okna to je zamknij
				if (event.type == Event::Closed)
					okno.close();
			}

			okno.clear(); // odswiezamy ekran

			// najpierw rysujemy tlo aby bylo z tylu
			okno.draw(tlo);

			// rysuj tylko aktywne cegly
			for (size_t i = 0; i <  aktywne_cegly.size(); i++)
				okno.draw(aktywne_cegly[i]);

			// sprawdzenie kolizji dlawszystkich cegiel i pilki
			for (size_t i = 0; i < aktywne_cegly.size(); i++)
			{
				bool kolizja = sprawdz_kolizje(pilka.pobierz_wymiary(), aktywne_cegly[i].pobierz_wymiary());
				if (kolizja)
				{
					// podajemy nr cegly do zbicia
					zbij_cegle(i);
					pilka.odbijWPoziomie();
				}
			}

			pilka.ruch(&okno.getSize());
			obsluga_wejscia();
			okno.draw(pilka);
			okno.draw(paletka);
			okno.display();
		}
	}

	void zbij_cegle(int nr)
	{
		// zapamietamy zbite cegielki
		zbite_cegly.push_back(aktywne_cegly[nr]);
		// usuwamy z listy aktywnych cegiel zbita cegle
		cout << nr;
		aktywne_cegly.erase(aktywne_cegly.begin() + nr);
	}

	void czas_rozgrywki()
	{
	}

	void obsluga_wejscia()
	{
		if (Keyboard::isKeyPressed(Keyboard::Right)) paletka.ruch(Vector2f(0.1, 0));
		if (Keyboard::isKeyPressed(Keyboard::Left)) paletka.ruch(Vector2f(-0.1, 0));
	}

	// spradzamy czy pilka nachodzi na cegielke i zwracamy prawde albo falsz, 
	bool sprawdz_kolizje(FloatRect obszar_pilki, FloatRect obszar_celu)
	{
		return obszar_pilki.intersects(obszar_celu);
	}

	bool sprawdz_wygrana()
	{

	}

	bool sprawdz_przegrana()
	{

	}
};

