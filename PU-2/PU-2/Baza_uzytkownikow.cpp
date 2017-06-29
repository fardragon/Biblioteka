#include "Baza_uzytkownikow.h"

Baza_uzytkownikow::Baza_uzytkownikow()
{
	m_uzytkownicy.push_back(std::make_tuple(1, "pracownik", "pracownik", login::pracownik));
	m_uzytkownicy.push_back(std::make_tuple(2, "login", "haslo", login::uzytkownik));
	m_dane_uzytkownikow[2] = { "Jan","Kowalski","71020235144", "adres@adres.pl" };
	m_uzytkownicy.push_back(std::make_tuple(18, "login2", "haslo", login::uzytkownik));
	m_dane_uzytkownikow[18] = { "Jan","Kowalski","98765432109", "adres2@adres.pl" };
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

std::vector<std::pair<int, Dane_uzytkownika>> Baza_uzytkownikow::znajdz_id_uzytkownika(const std::string& imie, const std::string& nazwisko)
{
	std::vector<std::pair<int, Dane_uzytkownika>> wyniki;

	for (auto& it : m_dane_uzytkownikow)
	{
		if ((it.second.Imie == imie) && (it.second.Nazwisko == nazwisko))
		{
			wyniki.push_back(std::make_pair(it.first,it.second));
		}
	}

	return wyniki;
}

bool Baza_uzytkownikow::potwierdz_realizacje(int id_uzytkownika, const std::string & tytul)
{
	std::string tytul, adres;
	adres = m_dane_uzytkownikow[id_uzytkownika].adres;
	

}



