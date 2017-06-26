#ifndef Biblioteka_h__
#define Biblioteka_h__

#include <memory>

#include "Baza_uzytkownikow.h"
#include "Gosc.h"

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
	bool m_loop;

	Baza_uzytkownikow m_baza_uzytkownikow;
	std::unique_ptr<Uzytkownicy> m_uzytkownik;

	void zamknij();


};
#endif // Biblioteka_h__
