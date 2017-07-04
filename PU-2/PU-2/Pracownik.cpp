#include "Pracownik.h"

Pracownik::Pracownik(Baza_uzytkownikow * baza_uzytkownikow, std::function<void(void)> zamknij, int id, Lista_rezerwacji* zamowienia, Lista_wypozyczen* wypozyczenia, Lista_ksiazek* ksiazki) :
	Uzytkownicy(id, baza_uzytkownikow, zamknij), m_zamowienia(zamowienia), m_wypozyczenia(wypozyczenia), m_ksiazki(ksiazki)
{
	this->menu_glowne();
}

void Pracownik::start()
{
	m_gui.start();
}

void Pracownik::menu_glowne()
{
	m_gui.czysc_gui();
	m_gui.dodaj_tekst("Panel pracownika");
	m_gui.dodaj_guzik("Odbierz zamowienie", std::bind(&Pracownik::odbierz_zamowienie, this));
	m_gui.dodaj_guzik("Koniec", std::bind(&Uzytkownicy::zamknij, this));
}

void Pracownik::odbierz_zamowienie()
{
	m_gui.czysc_gui();
	m_gui.dodaj_tekst("Wyszukaj zamowienia");
	m_uid = m_gui.dodaj_editbox("ID uzytkownika",false,true);
	m_gui.dodaj_guzik("Dalej", std::bind(&Pracownik::pobierz_zamowienia, this));
	m_gui.dodaj_guzik("Szukaj ID", std::bind(&Pracownik::szukaj_uzytkownika, this));
	m_gui.dodaj_guzik("Wroc", std::bind(&Pracownik::menu_glowne, this));
}


void Pracownik::szukaj_uzytkownika()
{
	m_gui.czysc_gui();
	m_gui.dodaj_tekst("Wyszukaj uzytkownika");
	m_uimie = m_gui.dodaj_editbox("Imie", false, false);
	m_unazwisko = m_gui.dodaj_editbox("Nazwisko", false, false);
	m_gui.dodaj_guzik("Szukaj", std::bind(&Pracownik::znajdz_id_uzytkownika, this));
	m_gui.dodaj_guzik("Wroc", std::bind(&Pracownik::odbierz_zamowienie, this));
}

void Pracownik::znajdz_id_uzytkownika()
{
	std::string imie = "", nazwisko = "";

	if (auto spt = m_uimie.lock())
	{
		imie = spt->getText().toAnsiString();
	}
	if (auto spt = m_unazwisko.lock())
	{
		nazwisko = spt->getText().toAnsiString();
	}

	m_gui.czysc_gui();

	auto wynik = m_baza_uzytkownikow->znajdz_id_uzytkownika(imie, nazwisko);

	if (wynik.empty())
	{
		m_gui.dodaj_tekst("Nie znaleziono uzytkownika");
		m_gui.dodaj_guzik("Wroc", std::bind(&Pracownik::szukaj_uzytkownika, this));
	}
	else
	{
		m_gui.dodaj_tekst("Wyniki");
		m_listbox = m_gui.dodaj_listbox();

		for (auto &it : wynik)
		{
			std::string linia = std::to_string(it.first);
			linia += " ";
			linia += it.second.Imie;
			linia += " ";
			linia += it.second.Nazwisko;
			linia += " ";
			linia += it.second.PESEL;
			if (auto spt = m_listbox.lock())
			{
				spt->addItem(linia);
			}
		}
		m_gui.dodaj_guzik("Wybierz", std::bind(&Pracownik::pobierz_z_listbox, this,listbox_status::id));
		m_gui.dodaj_guzik("Wroc", std::bind(&Pracownik::szukaj_uzytkownika, this));
	}

}

void Pracownik::pobierz_z_listbox(listbox_status co)
{
	std::string wybrany;
	if (auto spt = m_listbox.lock())
	{
		wybrany = spt->getSelectedItem();
	}

	if (wybrany.empty())
	{

		switch (co)
		{
		case listbox_status::id:
			this->odbierz_zamowienie();
			break;
		case listbox_status::zamowienie:
			break;
		}
		
	}
	else
	{
		switch (co)
		{
		case listbox_status::id:
			this->odbierz_zamowienie();
			if (auto spt = m_uid.lock())
			{
				spt->setText(wybrany.substr(0, wybrany.find(" ")));
			}
			break;
		case listbox_status::zamowienie:
			this->potwierdz_odbior(wybrany);
			if (auto spt2 = m_listbox.lock())
			{
				spt2->removeItem(wybrany);
			}

			break;
		}

	}
}

void Pracownik::pobierz_zamowienia()
{
	int uid = 0;
	if (auto spt = m_uid.lock())
	{
		uid = stoi(spt->getText().toAnsiString());
	}
	auto zamowienia = m_zamowienia->szukaj_rezerwacji(uid);
	m_gui.czysc_gui();
	if (zamowienia.empty())
	{
		m_gui.dodaj_tekst("Nie znaleziono zamowien");
		m_gui.dodaj_guzik("Wroc", std::bind(&Pracownik::szukaj_uzytkownika, this));
	}
	else
	{
		m_gui.dodaj_tekst("Wyniki");
		m_listbox = m_gui.dodaj_listbox();

		for (auto &it : zamowienia)
		{
			std::string linia = it.pobierz_ISBN_ksiazki() + " " + m_ksiazki->znajdz_tytul(it.pobierz_ISBN_ksiazki()) + " " +  std::to_string(it.pobierz_id_egzemplarza()) + " " + std::to_string(uid);
			if (auto spt = m_listbox.lock())
			{
				spt->addItem(linia);
			}
		}
		m_gui.dodaj_guzik("Wybierz", std::bind(&Pracownik::pobierz_z_listbox, this, listbox_status::zamowienie));
		m_gui.dodaj_guzik("Wroc", std::bind(&Pracownik::menu_glowne, this));
	}


}

void Pracownik::potwierdz_odbior(const std::string & zamowienie)
{
	std::istringstream temp_stream(zamowienie);
	std::string temp, ISBN, tytul;

	temp_stream >> ISBN;
	temp_stream >> tytul;
	temp_stream >> temp;

	int id_egzemplarza = stoi(temp);
	
	temp_stream >> temp;

	int id_uzytkownika = stoi(temp);

	m_zamowienia->usun_rezerwacje( ISBN,id_egzemplarza);
	m_wypozyczenia->dodaj_wypozyczenie(id_uzytkownika, ISBN, id_egzemplarza);
	m_baza_uzytkownikow->potwierdz_realizacje(id_uzytkownika,tytul );

}
