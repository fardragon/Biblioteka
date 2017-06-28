#ifndef Gosc_h__
#define Gosc_h__

#include "Uzytkownicy.h"

#include <iostream>

class Gosc : public Uzytkownicy
{

public:
	Gosc(Baza_uzytkownikow* baza_uzytkownikow, std::function<void(void)> zamknij, std::function<void(int)> loguj_pracownik);


private:

	std::weak_ptr<tgui::EditBox> m_nazwa;
	std::weak_ptr<tgui::EditBox> m_haslo;

	std::function<void(int)> m_loguj_pracownik;

	virtual void start() override;
	void loguj();

	void menu_glowne();
	void logowanie();
	void blad_logowania();

};
#endif // Gosc_h__
