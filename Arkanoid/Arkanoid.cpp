#include "Arkanoid.h"

Arkanoid::Arkanoid() {}

// odstep_cegiel to odstep miedzy ceglami w kolumnie i wierszu
Arkanoid::Arkanoid(Vector2i ile_cegiel, Vector2f odstep_cegiel, Vector2f predkosc)
	: ile_cegiel(ile_cegiel), punkty(Vector2f(0, 480), &czcionka), stan(STAN::WYBICIE), restart_przycisk("Restart", Vector2f(181, 206), false)
{
	stworz_pilke(predkosc);
	stworz_tlo();
	stworz_paletke();
	stworz_cegly(odstep_cegiel);
	wczytaj_czcionke();

	// petla okna
	stworz_okno();
};

void Arkanoid::wczytaj_czcionke()
{
	czcionka.loadFromFile("czcionka/arial.ttf");
}

void Arkanoid::stworz_cegly(Vector2f odstep)
{
	cegla_textura.loadFromFile("images/block02.png");

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

void Arkanoid::stworz_tlo()
{
	tlo_textura.loadFromFile("images/background.jpg");
	tlo.setTexture(tlo_textura);
}

void Arkanoid::stworz_paletke()
{
	paletka_tekstura.loadFromFile("images/paddle.png");
	paletka = Paletka(&paletka_tekstura, Vector2f(220, 440));
}

void Arkanoid::stworz_pilke(Vector2f predkosc)
{
	////pilka_dzwiek.loadFromFile("sounds/ball.wav");
	pilka_textura.loadFromFile("images/ball.png");
	pilka = Pilka(&pilka_textura, Vector2f(255, 420), predkosc);
}

void Arkanoid::stworz_okno()
{
	RenderWindow okno(VideoMode(512, 512), "Arkanoid!");

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
		for (size_t i = 0; i < aktywne_cegly.size(); i++)
			okno.draw(aktywne_cegly[i]);

		maszyna_stanow(okno);
		okno.draw(pilka);
		okno.draw(paletka);
		okno.draw(punkty);
		okno.draw(restart_przycisk);

		// wyswietlamy okno
		okno.display();
	}
}

void Arkanoid::zbij_cegle(int nr)
{
	// zapamietamy zbite cegielki
	zbite_cegly.push_back(aktywne_cegly[nr]);
	// usuwamy z listy aktywnych cegiel zbita cegle
	aktywne_cegly.erase(aktywne_cegly.begin() + nr);
}

void Arkanoid::obsluga_wejscia(RenderWindow & okno)
{
	if (Keyboard::isKeyPressed(Keyboard::Right)) paletka.ruch(Vector2f(0.1, 0), Vector2u(0,430));
	if (Keyboard::isKeyPressed(Keyboard::Left)) paletka.ruch(Vector2f(-0.1, 0), Vector2u(0, 430));
}

// spradzamy czy pilka nachodzi na cegielke i zwracamy prawde albo falsz, 
bool Arkanoid::sprawdz_kolizje(FloatRect obszar_pilki, FloatRect obszar_celu)
{
	return obszar_pilki.intersects(obszar_celu);
}

void Arkanoid::sprawdz_wygrana()
{
	if (aktywne_cegly.size() == 0)
	{
		restart_przycisk.pokaz_przycisk(true);
		stan = STAN::WYGRANA;
	}
}

void Arkanoid::sprawdz_przegrana()
{
	if (pilka.pobierz_pozycje().y > 480)
	{
		restart_przycisk.pokaz_przycisk(true);
		stan = STAN::PRZEGRANA;
	}
}

void Arkanoid::sprawdz_kolizje_cegiel()
{
	// sprawdzenie kolizji dlawszystkich cegiel i pilki
	for (size_t i = 0; i < aktywne_cegly.size(); i++)
	{
		bool kolizja = sprawdz_kolizje(pilka.pobierz_wymiary(), aktywne_cegly[i].pobierz_wymiary());
		if (kolizja)
		{
			// podajemy nr cegly do zbicia
			zbij_cegle(i);
			pilka.odbijWPoziomie();
			dodaj_punkt();
			// sprawdzamy warunek wygranej
			sprawdz_wygrana();
		}
	}
}

void Arkanoid::sprawdz_kolizje_paletki()
{
	bool kolizja = sprawdz_kolizje(pilka.pobierz_wymiary(), paletka.pobierz_wymiary());

	if (kolizja)
		pilka.odbijWPoziomie();
}

void Arkanoid::gra(RenderWindow & okno)
{
	pilka.ruch(&okno.getSize());
	obsluga_wejscia(okno);
	sprawdz_przegrana();
	sprawdz_kolizje_cegiel();
	sprawdz_kolizje_paletki();
}

void Arkanoid::wybicie(RenderWindow & okno)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
		stan = STAN::GRA;
}

// Maszyna Stanow
void Arkanoid::maszyna_stanow(RenderWindow & okno)
{
	switch (stan)
	{
	case GRA:
		gra(okno);
		break;
	case WYBICIE:
		wybicie(okno);
		break;
	case PRZEGRANA:
		restart(okno);
		break;
	case WYGRANA:
		restart(okno);
		break;
	default:
		break;
	}
}

inline void Arkanoid::dodaj_punkt() { punkty++; }

void Arkanoid::restart(RenderWindow & okno)
{
	if (restart_przycisk.detekcja_klikniecia(&okno))
	{
		punkty.reset();
		paletka.reset();
		pilka.reset();
		restart_przycisk.pokaz_przycisk(false);
		stan = STAN::WYBICIE;

		for (size_t i = 0; i < zbite_cegly.size(); i++)
		{
			// dodajemy ponownie cegly do aktnywnych
			aktywne_cegly.push_back(zbite_cegly[i]);
		}
		zbite_cegly.clear(); // czyscimy zbite cegly;
	}
}
