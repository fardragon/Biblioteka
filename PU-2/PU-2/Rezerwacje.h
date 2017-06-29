#ifndef Rezerwacje_h__
#define Rezerwacje_h__

#include <string>
#include <vector>
#include <algorithm>

class Rezerwacja
{
public:

	Rezerwacja(const std::string& ISBN , int id_egzemplarza, int id_uzytkownika) : m_id_egzemplarza(id_egzemplarza), m_ISBN(ISBN), m_id_uzytkownika(id_uzytkownika) {};
	std::string pobierz_ISBN_ksiazki() const { return m_ISBN; } ;
	int pobierz_id_egzemplarza() const { return m_id_egzemplarza; };
	int pobierz_id_uzytkownika() const { return m_id_uzytkownika; };

	/*
	bool operator == (const Rezerwacja& other)
	{
		if ((other.pobierz_id_uzytkownika() == m_id_uzytkownika) && (other.pobierz_ISBN_ksiazki() == m_ISBN) && (other.pobierz_id_egzemplarza() == m_id_egzemplarza))
		{
			return true;
		}
		return false;
	}
	*/
private:

	std::string m_ISBN;
	int  m_id_egzemplarza;
	int  m_id_uzytkownika;
};


class Lista_rezerwacji
{
public:

	Lista_rezerwacji();

	bool dodaj_rezerwacje(int id_uzytkownika, const std::string& ISBN_ksiazki, int id_egzemplarza);
	bool usun_rezerwacje(const std::string& ISBN_ksiazki, int id_egzemplarza);
	std::vector<Rezerwacja> szukaj_rezerwacji(int id_uzytkownika);

private:

	std::vector<Rezerwacja> m_lista;

};




#endif // Rezerwacje_h__
