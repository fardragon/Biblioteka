#ifndef Biblioteka_h__
#define Biblioteka_h__

#include <memory>

#include "Baza_uzytkownikow.h"
#include "Rezerwacje.h"
#include "Ksiazki.h"
#include "Gosc.h"
#include "Pracownik.h"

enum class status
{
	loguj_uzytkownik,
	loguj_pracownik,
	loguj_administrator,
	zamknij
};


class Biblioteka
{

public:
	Biblioteka();

	void start();

private:
	status m_status;
	bool m_petla;
	int m_uid;

	Baza_uzytkownikow m_baza_uzytkownikow;
	Lista_ksiazek m_lista_ksiazek;
	Lista_rezerwacji m_lista_rezerwacji;

	std::unique_ptr<Uzytkownicy> m_uzytkownik;

	void zamknij();
	void loguj_pracownik(int id);


};
#endif // Biblioteka_h__
