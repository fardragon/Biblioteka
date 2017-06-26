#ifndef Uzytkownicy_h__
#define Uzytkownicy_h__

#include <functional>


#include "GUI.h"
#include "Baza_uzytkownikow.h"



class Uzytkownicy
{
protected:

	int m_id;
	GUI m_gui;
	Baza_uzytkownikow* m_baza_uzytkownikow;

	std::function<void(void)> m_zamknij;

public:
	Uzytkownicy(int id, Baza_uzytkownikow* baza_uzytkownikow, std::function<void(void)> zamknij);
	virtual ~Uzytkownicy();

	virtual void start() = 0;
	virtual void zamknij();

};
#endif // Uzytkownicy_h__
