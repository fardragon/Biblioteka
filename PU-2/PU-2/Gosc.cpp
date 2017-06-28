#include "Gosc.h"

Gosc::Gosc(Baza_uzytkownikow* baza_uzytkownikow, std::function<void(void)> zamknij, std::function<void(int)> loguj_pracownik) : 
	Uzytkownicy(0,baza_uzytkownikow,zamknij), m_loguj_pracownik(loguj_pracownik)
{
	this->menu_glowne();
}

void Gosc::start()
{
	m_gui.start();
}

void Gosc::loguj()
{

	std::string nazwa = "", haslo = "";
	if (auto spt = m_nazwa.lock())
	{
		nazwa = spt->getText().toAnsiString();
	}
	if (auto spt = m_haslo.lock())
	{
		haslo = spt->getText().toAnsiString();
	}
	auto wynik = m_baza_uzytkownikow->logowanie(nazwa, haslo);

	switch (wynik.first)
	{
	case login::blad:
		this->blad_logowania();
		break;
	case login::uzytkownik:
		break;
	case login::pracownik:	
		m_loguj_pracownik(wynik.second);
		m_gui.koniec();
		break;
	case login::admin:
		break;
	}
}

void Gosc::menu_glowne()
{
	m_gui.czysc_gui();
	m_gui.dodaj_tekst("Panel goscia");
	m_gui.dodaj_guzik("Logowanie", std::bind(&Gosc::logowanie, this));
	m_gui.dodaj_guzik("Koniec", std::bind(&Uzytkownicy::zamknij, this));
}

void Gosc::logowanie()
{
	m_gui.czysc_gui();
	m_gui.dodaj_tekst("Logowanie");
	m_nazwa = m_gui.dodaj_editbox("Nazwa",false,false);
	m_haslo = m_gui.dodaj_editbox("Haslo",true,false);
	m_gui.dodaj_guzik("Loguj", std::bind(&Gosc::loguj, this));
	m_gui.dodaj_guzik("Wroc", std::bind(&Gosc::menu_glowne, this));
}

void Gosc::blad_logowania()
{
	m_gui.czysc_gui();
	m_gui.dodaj_tekst("Bledne dane");
	m_gui.dodaj_guzik("Wroc", std::bind(&Gosc::logowanie, this));
}
