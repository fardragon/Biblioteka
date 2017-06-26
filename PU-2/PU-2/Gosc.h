#ifndef Gosc_h__
#define Gosc_h__

#include "Uzytkownicy.h"

class Gosc : public Uzytkownicy
{

public:
	Gosc(Baza_uzytkownikow* baza_uzytkownikow, std::function<void(void)> zamknij);


private:
	virtual void start() override;
	void loguj(std::string nazwa, std::string haslo);

	void menu_glowne();
	void logowanie();

};
#endif // Gosc_h__
