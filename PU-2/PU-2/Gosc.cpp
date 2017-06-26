#include "Gosc.h"

Gosc::Gosc(Baza_uzytkownikow * baza_uzytkownikow, std::function<void(void)> zamknij): 
	Uzytkownicy(0,baza_uzytkownikow,zamknij)
{
	this->menu_glowne();
}

void Gosc::start()
{
	m_gui.start();
}

void Gosc::loguj(std::string nazwa, std::string haslo)
{
	auto success = m_baza_uzytkownikow->logowanie(nazwa, haslo);



}

void Gosc::menu_glowne()
{
	m_gui.czysc_gui();
	m_gui.dodaj_guzik("Logowanie", std::bind(&Gosc::logowanie, this));
	m_gui.dodaj_guzik("Koniec", std::bind(&Uzytkownicy::zamknij, this));
}

void Gosc::logowanie()
{
	m_gui.czysc_gui();
	m_gui.dodaj_guzik("Wroc", std::bind(&Gosc::menu_glowne, this));
}
