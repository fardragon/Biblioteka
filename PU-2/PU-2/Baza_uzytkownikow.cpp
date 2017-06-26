#include "Baza_uzytkownikow.h"

Baza_uzytkownikow::Baza_uzytkownikow()
{
	this->m_uzytkownicy.push_back(std::make_tuple(1, "pracownik", "pracownik", login::pracownik));
}

std::pair<login, int> Baza_uzytkownikow::logowanie(const std::string & nazwa, const std::string & haslo)
{
	for (auto &it : m_uzytkownicy)
	{
		if (std::get<1>(it) == nazwa)
		{
			if (std::get<2>(it) == haslo)
			{
				return std::make_pair(std::get<3>(it), std::get<0>(it));
			}
			else
			{
				return std::make_pair(login::blad, 0);
			}
		}
	}
	return std::make_pair(login::blad, 0);
}



