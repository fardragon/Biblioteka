#include "Uzytkownicy.h"

Uzytkownicy::Uzytkownicy(int id, Baza_uzytkownikow* baza_uzytkownikow, std::function<void(void)> zamknij): 
	m_gui(std::bind(&Uzytkownicy::zamknij,this)),
	m_id(id), m_baza_uzytkownikow(baza_uzytkownikow), m_zamknij(zamknij)
{

}

Uzytkownicy::~Uzytkownicy()
{

}

void Uzytkownicy::zamknij()
{
	m_zamknij();
	m_gui.koniec();
}
