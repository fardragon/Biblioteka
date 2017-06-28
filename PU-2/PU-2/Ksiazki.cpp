#include "Ksiazki.h"

Lista_ksiazek::Lista_ksiazek()
{
	this->dodaj_ksiazke("ISBN1", "TYTUL", "AUTOR");
	this->dodaj_egzemplarz("ISBN1", 1, 1, "Wyd1");
	this->dodaj_egzemplarz("ISBN1", 2, 1, "Wyd1");
	this->dodaj_egzemplarz("ISBN1", 3, 1, "Wyd1");

	this->dodaj_ksiazke("ISBN2", "TYTUL2", "AUTOR2");
	this->dodaj_egzemplarz("ISBN2", 1, 1, "Wyd2");
	this->dodaj_egzemplarz("ISBN2", 2, 2, "Wyd3");
}

bool Lista_ksiazek::dodaj_ksiazke(const std::string& ISBN, const std::string& tytul, const std::string& autor)
{
	std::vector<Ksiazka>::iterator it;
	it = std::find_if(m_lista.begin(), m_lista.end(), [ISBN](const Ksiazka& a)->bool {
		if (ISBN == a.pobierz_ISBN())
		{
			return true;
		}
		else
		{
			return false;
		}
	});
	if (it == m_lista.end())
	{
		m_lista.push_back(Ksiazka(ISBN, tytul, autor));
		return true;
	}
	else
	{
		return false;
	}
}

bool Lista_ksiazek::dodaj_egzemplarz(const std::string & ISBN, int id, int numer_wydania, const std::string & wydawnictwo)
{
	std::vector<Ksiazka>::iterator it;
	it = std::find_if(m_lista.begin(), m_lista.end(), [ISBN](const Ksiazka& a)->bool {
		if (ISBN == a.pobierz_ISBN())
		{
			return true;
		}
		else
		{
			return false;
		}
	});

	if (it == m_lista.end()) return false;

	return it->dodaj_egzemplarz(id, numer_wydania, wydawnictwo);

}

bool Ksiazka::dodaj_egzemplarz(int id, int numer_wydania, const std::string & wydawnictwo)
{
	std::vector<Egzemplarz>::iterator it;
	it = std::find_if(m_egzemplarze.begin(), m_egzemplarze.end(), [id](const Egzemplarz& a)->bool {
		if (id == a.pobierz_id())
		{
			return true;
		}
		else
		{
			return false;
		}
	});

	if (it == m_egzemplarze.end())
	{
		m_egzemplarze.push_back(Egzemplarz(id, numer_wydania, wydawnictwo));
		return true;
	}
	else
	{
		return false;
	}
}
