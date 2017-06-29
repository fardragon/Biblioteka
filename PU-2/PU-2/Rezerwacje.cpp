#include "Rezerwacje.h"

Lista_rezerwacji::Lista_rezerwacji()
{
	this->dodaj_rezerwacje(18, "ISBN1", 2);
	this->dodaj_rezerwacje(18, "ISBN2", 15);
}

bool Lista_rezerwacji::dodaj_rezerwacje(int id_uzytkownika, const std::string& ISBN_ksiazki, int id_egzemplarza)
{
	std::vector<Rezerwacja>::iterator it;
	it = std::find_if(m_lista.begin(), m_lista.end(), [ISBN_ksiazki, id_egzemplarza](const Rezerwacja& a)->bool {if ((a.pobierz_ISBN_ksiazki() == ISBN_ksiazki) && (a.pobierz_id_egzemplarza() == id_egzemplarza)) return true; else return false; });

	if (it == m_lista.end())
	{
		m_lista.push_back(Rezerwacja(ISBN_ksiazki, id_egzemplarza, id_uzytkownika));
		return true;
	}
	return false;
}

bool Lista_rezerwacji::usun_rezerwacje(const std::string& ISBN_ksiazki, int id_egzemplarza)
{
	std::vector<Rezerwacja>::iterator it;

	it = std::find_if(m_lista.begin(), m_lista.end(), [ISBN_ksiazki, id_egzemplarza](const Rezerwacja& a)->bool {if ((a.pobierz_ISBN_ksiazki() == ISBN_ksiazki) && (a.pobierz_id_egzemplarza() == id_egzemplarza)) return true; else return false; });

	if (it == m_lista.end())
	{
		return false;
	}
	m_lista.erase(it);
	return true;

}

std::vector<Rezerwacja> Lista_rezerwacji::szukaj_rezerwacji(int id_uzytkownika)
{
	std::vector<Rezerwacja> wynik;
	for (auto& it : m_lista)
	{
		if (it.pobierz_id_uzytkownika() == id_uzytkownika)
		{
			wynik.push_back(it);
		}
	}
	return wynik;
}


