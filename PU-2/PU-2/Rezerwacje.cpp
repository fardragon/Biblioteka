#include "Rezerwacje.h"

Lista_rezerwacji::Lista_rezerwacji()
{
	this->dodaj_rezerwacje(18, "ISBN1", 2);
	this->dodaj_rezerwacje(18, "ISBN2", 1);
}

void Lista_rezerwacji::dodaj_rezerwacje(int id_uzytkownika, const std::string& ISBN_ksiazki, int id_egzemplarza)
{
	m_lista.push_back(Rezerwacja(ISBN_ksiazki, id_egzemplarza, id_uzytkownika));
}

bool Lista_rezerwacji::usun_rezerwacje(int id_uzytkownika, const std::string& ISBN_ksiazki, int id_egzemplarza)
{
	std::vector<Rezerwacja>::iterator it;

	it = std::find(m_lista.begin(), m_lista.end(), Rezerwacja(ISBN_ksiazki, id_egzemplarza, id_uzytkownika));

	if (it == m_lista.end())
	{
		return false;
	}
	else
	{
		m_lista.erase(it);
		return true;
	}


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


