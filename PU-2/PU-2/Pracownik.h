#ifndef Pracownik_h__
#define Pracownik_h__

#include <sstream>

#include "Uzytkownicy.h"
#include "Rezerwacje.h"
#include "Wypozyczenia.h"
#include "Ksiazki.h"

enum class listbox_status
{
	id,
	zamowienie
};


class Pracownik : public Uzytkownicy
{

public:
	Pracownik(Baza_uzytkownikow* baza_uzytkownikow, std::function<void(void)> zamknij, int id, Lista_rezerwacji* zamowienia, Lista_wypozyczen* wypozyczenia, Lista_ksiazek* ksiazki);


private:

	Lista_rezerwacji* m_zamowienia;
	Lista_wypozyczen* m_wypozyczenia;
	Lista_ksiazek* m_ksiazki;

	virtual void start() override;

	void menu_glowne();
	void odbierz_zamowienie();
	void szukaj_uzytkownika();
	void znajdz_id_uzytkownika();
	void pobierz_z_listbox(listbox_status co);
	void pobierz_zamowienia();
	void potwierdz_odbior(const std::string& zamowienie);


	std::weak_ptr<tgui::EditBox> m_uid;
	std::weak_ptr<tgui::EditBox> m_uimie;
	std::weak_ptr<tgui::EditBox> m_unazwisko;
	std::weak_ptr<tgui::ListBox> m_listbox;
};

#endif // Pracownik_h__
